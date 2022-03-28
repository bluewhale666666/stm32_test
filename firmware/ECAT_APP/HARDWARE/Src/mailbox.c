#include "ecat_def.h"
#include "ecatslv.h"

#define    _MAILBOX_    1
#include "mailbox.h"
#undef _MAILBOX_

#include "ecatcoe.h"
#include "ecatfoe.h"
#include "emcy.h"
#include "hw_readwrite.h"
/*variables are declared in ecatslv.c*/
extern VARVOLATILE UINT16    u16dummy;

BOOL bNoMbxMemoryAvailable; /**< \brief Indicates if enough dynamic memory is available to handle at least one mailbox datagram */

TMBX MBXMEM *  psWriteMbx; /**< \brief Pointer to write mailbox buffer*/

//    PutInMbxQueue
UINT8 PutInMbxQueue(TMBX MBXMEM * pMbx, TMBXQUEUE MBXMEM * pQueue)
{
    UINT16 lastInQueue;
	 UINT16 sm1Activate = 0;
    ENTER_MBX_CRITICAL;


    lastInQueue = pQueue->lastInQueue+1;
    if (lastInQueue == pQueue->maxQueueSize)
    {
        // Umbruch der Queue
        lastInQueue = 0;
    }

    if (pQueue->firstInQueue == lastInQueue)
    {
        // Ueberlauf der Queue -> letztes Element wieder herausnehmen
        LEAVE_MBX_CRITICAL;
        return MBXERR_NOMOREMEMORY;
    }

    pQueue->queue[pQueue->lastInQueue] = pMbx;
    pQueue->lastInQueue = lastInQueue;

    LEAVE_MBX_CRITICAL;

    return 0;
}

//    GetOutOfMbxQueue
TMBX MBXMEM * GetOutOfMbxQueue(TMBXQUEUE MBXMEM * pQueue)
{
    TMBX MBXMEM * pMbx;
    ENTER_MBX_CRITICAL;

    if (pQueue->firstInQueue != pQueue->lastInQueue)
    {
        // Queue ist nicht leer
        UINT16 firstInQueue = pQueue->firstInQueue;
        pMbx = pQueue->queue[firstInQueue];
        firstInQueue++;
        pQueue->firstInQueue = firstInQueue;
        if (pQueue->firstInQueue == pQueue->maxQueueSize)
        {
            // Umbruch der Queue
            pQueue->firstInQueue = 0;
        }
    }
    else
        pMbx = 0;


    LEAVE_MBX_CRITICAL;

    return pMbx;
}

/*********************************************************************************
 \brief    This function intialize the Mailbox Interface.
*********************************************************************************/
void MBX_Init(void)
{
	 UINT16 sm1Activate;
	
    u16ReceiveMbxSize    = MIN_MBX_SIZE;
    u16SendMbxSize       = MAX_MBX_SIZE;
    u16EscAddrReceiveMbx = MIN_MBX_WRITE_ADDRESS;
    u16EscAddrSendMbx    = MIN_MBX_READ_ADDRESS;

    sMbxReceiveQueue.firstInQueue = 0;
    sMbxReceiveQueue.lastInQueue  = 0;
    sMbxReceiveQueue.maxQueueSize = MAX_MBX_QUEUE_SIZE;

    sMbxSendQueue.firstInQueue    = 0;
    sMbxSendQueue.lastInQueue     = 0;
    sMbxSendQueue.maxQueueSize    = MAX_MBX_QUEUE_SIZE;

    psWriteMbx = (TMBX MBXMEM *) APPL_AllocMailboxBuffer(128);

    psRepeatMbx = NULL;
    psReadMbx   = NULL;
    psStoreMbx  = NULL;

    bMbxRepeatToggle = FALSE;

    /*Reset Repeat acknowledge bit of SyncManager1 (0x80F bit 2)*/
//    UINT16 sm1Activate = 0;
    HW_EscReadWord(sm1Activate,(ESC_SYNCMAN_ACTIVE_OFFSET + SIZEOF_SM_REGISTER));
    sm1Activate &= SWAPWORD(~0x0200);
    HW_EscWriteWord(sm1Activate,(ESC_SYNCMAN_ACTIVE_OFFSET + SIZEOF_SM_REGISTER));

    bMbxRunning         = FALSE;
    bSendMbxIsFull      = FALSE;
    bReceiveMbxIsLocked = FALSE;

    u8MailboxSendReqStored = 0;
    u8MbxWriteCounter      = 0;
    u8MbxReadCounter       = 0;
}

/*********************************************************************************

 \brief     This function includes the state transition from INIT to
 \brief     PRE-OPERATIONAL in the EtherCAT Slave corresponding to
 \brief     local management service Start Mailbox Handler
 \brief     it is checked if the mailbox areas overlaps each other
 \brief     and the Sync Manager channels 0 and 1 are enabled.
 \brief     This function shall only be called if mailbox is supported.
*********************************************************************************/
UINT16 MBX_StartMailboxHandler(void)
{
	  UINT16 sm1Activate;
    UINT16 result = 0;
    /* get address of the receive mailbox sync manager (SM0) */
    TSYNCMAN ESCMEM * pSyncMan = (TSYNCMAN ESCMEM *)GetSyncMan(MAILBOX_WRITE);
    /* store size of the receive mailbox */
    u16ReceiveMbxSize    = pSyncMan->Length;
    /* store the address of the receive mailbox */
    u16EscAddrReceiveMbx = pSyncMan->PhysicalStartAddress;

    /* get address of the send mailbox sync manager (SM1) */
    pSyncMan =(TSYNCMAN ESCMEM *) GetSyncMan(MAILBOX_READ);

    /* store the size of the send mailbox */
    u16SendMbxSize    = pSyncMan->Length;
    /* store the address of the send mailbox */
    u16EscAddrSendMbx = pSyncMan->PhysicalStartAddress;

    // HBu 02.05.06: it should be checked if there are overlaps in the sync manager areas
    if ((u16EscAddrReceiveMbx + u16ReceiveMbxSize) > u16EscAddrSendMbx && (u16EscAddrReceiveMbx < (u16EscAddrSendMbx + u16SendMbxSize)))
    {
        return ALSTATUSCODE_INVALIDMBXCFGINPREOP;
    }

    /* enable the receive mailbox sync manager channel */
    EnableSyncManChannel(MAILBOX_WRITE);
    /* enable the send mailbox sync manager channel */
    EnableSyncManChannel(MAILBOX_READ);

    memset(psWriteMbx,0,u16ReceiveMbxSize);

    if(psWriteMbx == NULL)
    {
        bNoMbxMemoryAvailable = TRUE;

        //check if at least enough memory for an mailbox error is available (other wise stop the state transition)

        memset(psWriteMbx,0,10);/* a mailbox error datagram length*/

        if(psWriteMbx == NULL)
        {
            result = ALSTATUSCODE_NOMEMORY;
        }
    }
    else
    {
        bNoMbxMemoryAvailable = FALSE;
    }

    return result;
}

/*********************************************************************************
 \brief    This function includes the state transition from
 \brief    PRE-OPERATIONAL to INIT in the EtherCAT Slave corresponding to
 \brief  local management service Stop Mailbox Handler
 \brief  the Sync Manager channels 0 and 1 are disabled
*********************************************************************************/
void MBX_StopMailboxHandler(void)
{
	UINT16 sm1Activate;
    TMBX MBXMEM * pMbx;

    /* mailbox handler is stopped */
    bMbxRunning = FALSE;
    /* disable the receive mailbox sync manager channel */

    DisableSyncManChannel(MAILBOX_WRITE);
    /* disable the send mailbox sync manager channel */
    DisableSyncManChannel(MAILBOX_READ);

    /* initialize variables again */

    if (psRepeatMbx != NULL)
        APPL_FreeMailboxBuffer(psRepeatMbx);

    if (psStoreMbx != NULL && psStoreMbx != psRepeatMbx)
        APPL_FreeMailboxBuffer(psStoreMbx);

    if (psReadMbx != NULL && psReadMbx != psRepeatMbx && psReadMbx != psStoreMbx)
        APPL_FreeMailboxBuffer(psReadMbx);

    psRepeatMbx = NULL;
    psReadMbx   = NULL;
    psStoreMbx  = NULL;

    bMbxRepeatToggle    = FALSE;
    /*Reset Repeat acknowledge bit of SyncManager1 (0x080F bit 2)*/

   // UINT16 sm1Activate = 0;
		sm1Activate = 0;
    HW_EscReadWord(sm1Activate,(ESC_SYNCMAN_ACTIVE_OFFSET + SIZEOF_SM_REGISTER));
    sm1Activate &= SWAPWORD(~0x0200);
    HW_EscWriteWord(sm1Activate,(ESC_SYNCMAN_ACTIVE_OFFSET + SIZEOF_SM_REGISTER));

    bSendMbxIsFull         = FALSE;
    bReceiveMbxIsLocked    = FALSE;
    u8MailboxSendReqStored = 0;
    u8MbxWriteCounter      = 0;
    u8MbxReadCounter       = 0;

    do
    {
        pMbx = GetOutOfMbxQueue(&sMbxReceiveQueue);
        if (pMbx)
        {
            APPL_FreeMailboxBuffer(pMbx);
            pMbx = NULL;
        }
    } while (pMbx != NULL);

    do
    {
        pMbx = GetOutOfMbxQueue(&sMbxSendQueue);
        if (pMbx)
        {
            APPL_FreeMailboxBuffer(pMbx);
            pMbx = NULL;
        }
    } while (pMbx != NULL);

    EMCY_Init();
}

/*********************************************************************************
 \param     pMbx        Pointer to the received Mailbox command from Master.

 \brief    The function checks the mailbox header for the requested service and calls the
 \brief    corresponding XXXX_ServiceInd-function
*********************************************************************************/

TFOEMBX MBXMEM  foetmp;
UINT8 MailboxServiceInd(TMBX MBXMEM *pMbx)
{
    UINT8 result;

    /*only FoE is allowed in Boot mode*/
    if(bBootMode == TRUE && (MBX_TYPE_FOE != ((pMbx->MbxHeader.Flags[MBX_OFFS_TYPE] & MBX_MASK_TYPE) >> MBX_SHIFT_TYPE )))
        return MBXERR_UNSUPPORTEDPROTOCOL;

    switch ( (pMbx->MbxHeader.Flags[MBX_OFFS_TYPE] & MBX_MASK_TYPE) >> MBX_SHIFT_TYPE )
    {
    case MBX_TYPE_COE:
        /* CoE datagram received */
        result = COE_ServiceInd((TCOEMBX MBXMEM *) pMbx);
        break;

    case MBX_TYPE_FOE:
        /* FoE datagram received */
        foetmp.MbxHeader.Length       = pMbx->MbxHeader.Length;
        foetmp.MbxHeader.Address      = pMbx->MbxHeader.Address;
        foetmp.MbxHeader.Flags[0]     = pMbx->MbxHeader.Flags[0];
        foetmp.FoeHeader.OpCode       = pMbx->Data[0];
        foetmp.FoeHeader.Cmd.PacketNo = ((UINT32)pMbx->Data[2]<<16|pMbx->Data[1]<<0);
        memcpy(&(foetmp.Data[0]),&(pMbx->Data[3]),(pMbx->MbxHeader.Length-6));

        result = FOE_ServiceInd(&foetmp);
        break;

    default:
        result = MBXERR_UNSUPPORTEDPROTOCOL;
        break;
    }

    return result;
}

/*********************************************************************************
 \param     pMbx        Pointer to the received Mailbox command from Master.

 \brief    This function is called when the Master has written the Receive-Mailbox.
 \brief    It will only be called if the send mailbox is empty, that a response for the
 \brief    mailbox service could be stored.
 \brief    The function checks the mailbox header for the requested service and calls the
 \brief    corresponding XXXX_ServiceInd-function
*********************************************************************************/

void MBX_MailboxWriteInd(TMBX MBXMEM *pMbx)
{
    UINT8 result = 0;
    UINT8 mbxCounter = pMbx->MbxHeader.Flags[MBX_OFFS_COUNTER] >> MBX_SHIFT_COUNTER;
    UINT16 MbxLen = SWAPWORD(pMbx->MbxHeader.Length);

    if(MbxLen > MAX_MBX_SIZE)
    {
        /* Mailbox error response: size specified in mailbox header too large*/
        pMbx->MbxHeader.Length     = 4;
        pMbx->MbxHeader.Flags[MBX_OFFS_TYPE]        &= ~MBX_MASK_TYPE;
        pMbx->Data[0]                        = SWAPWORD(MBXSERVICE_MBXERRORCMD);
        pMbx->Data[1]                        = SWAPWORD(MBXERR_INVALIDSIZE);
        MBX_MailboxSendReq(pMbx, 0);
    }
    else
    /* if the mailbox datagram counter (Bit 4-6 of Byte 5 of the mailbox header) is unequal zero,
       the master supports the mailbox data link layer,
        in that case a repeated mailbox write request will be detected, if the counter is unequal zero
        and unchanged */
    if ( mbxCounter == 0 || mbxCounter != u8MbxWriteCounter )
    {
        /* new mailbox service received */
        /* mbxCounter = 0: old EtherCAT master */
        /* new MBX service received, store the new mailbox counter */
        u8MbxWriteCounter = mbxCounter;

        /* check the protocol type and call the XXXX_ServiceInd-function */
        result = PutInMbxQueue(pMbx, &sMbxReceiveQueue);

        if ( result != 0 )
        {
            /* Mailbox error response: type 0 (mailbox service protocol) */
            pMbx->MbxHeader.Length                = 4;
            pMbx->MbxHeader.Flags[MBX_OFFS_TYPE] &= ~MBX_MASK_TYPE;
            pMbx->Data[0]                         = SWAPWORD(MBXSERVICE_MBXERRORCMD);
            pMbx->Data[1]                         = SWAPWORD(result);
            MBX_MailboxSendReq(pMbx, 0);
        }
    }
    // the mailbox buffer has to be freed here
    else
    {
       APPL_FreeMailboxBuffer(pMbx);
       pMbx = NULL;
    }
}

/*********************************************************************************
 \brief This function is called when the Master has read the Send-Mailbox.
*********************************************************************************/
void MBX_MailboxReadInd(void)
{
    bSendMbxIsFull = FALSE;

    // HBu 02.05.06: the pointer psRepeatMbx is only free if there is no stored
    //               mailbox service from the last repeat
    if ( psRepeatMbx && psStoreMbx == NULL )
    {
    /* the last sent service is not stored for repeat any longer */
        APPL_FreeMailboxBuffer(psRepeatMbx);
        psRepeatMbx = NULL;
    }

    /* the actual sent service has to be stored for repeat */
    psRepeatMbx = psReadMbx;

    if ( psStoreMbx )
    {
        /* there was a buffer stored */
        MBX_CopyToSendMailbox(psStoreMbx);
        /* no more buffer to be stored any more */
        psStoreMbx = NULL;
    }
    else
    {
        TMBX MBXMEM *pMbx = GetOutOfMbxQueue(&sMbxSendQueue);
        if (pMbx)
        {
            MBX_CopyToSendMailbox(pMbx);
        }
    }

    if ( u8MailboxSendReqStored )
    {
        /* there are mailbox services stored to be sent */
        if ( u8MailboxSendReqStored & EMCY_SERVICE )
        {
            /* call EMCY function that will send the stored Emergency service */
            EMCY_ContinueInd(psWriteMbx);
            if (EMCY_IsQueueEmpty())
            {
                u8MailboxSendReqStored &= ~EMCY_SERVICE;
            }
        }
        else if ( u8MailboxSendReqStored & COE_SERVICE )
        {
            UINT8 result = 0;
            /* reset the flag indicating that CoE service to be sent was stored */
            u8MailboxSendReqStored &= ~COE_SERVICE;

            /* call CoE function that will send the stored CoE service */
            result = COE_ContinueInd(psWriteMbx);

            if (result != 0)
            {
                /*Set the pending CoE indication is an error occurred during the continue indication*/
                u8MailboxSendReqStored |= COE_SERVICE;
            }
        }
        else if ( u8MailboxSendReqStored & FOE_SERVICE )
        {
            /* reset the flag indicating that FoE service to be sent was stored */
            u8MailboxSendReqStored &= ~FOE_SERVICE;
            /* call FoE function that will send the stored FoE service */
            FOE_ContinueInd(psWriteMbx);
        }
        else
        {

        }
    }
}

/*********************************************************************************
 \brief This function is called if the Master has requested a resending of the last
 \brief sent mailbox
*********************************************************************************/
void MBX_MailboxRepeatReq(void)
{
    if (psRepeatMbx)
    {
        TMBX MBXMEM *pMbx = psRepeatMbx;
        /* send mailbox service stored for repeat */
        /* HBu 13.10.06: if a repeat request is received (again) before the previously repeated mailbox telegram
           was read from the master (psStoreMbx != NULL) the next mailbox telegram to be sent is still in the
           read mailbox so it has not to updated exchanged */
        ENTER_MBX_CRITICAL;

        if (bSendMbxIsFull && psStoreMbx == NULL)
        {
            /* mailbox is full, take the buffer off */
            DisableSyncManChannel(MAILBOX_READ);

            /* store the buffer to be sent next */
            psStoreMbx = psReadMbx;
            /* enable the mailbox again */
            EnableSyncManChannel(MAILBOX_READ);

            /* HBu 15.02.06: flag has to be reset otherwise the mailbox service
                             will not be copied by MBX_CopyToSendMailbox */
            bSendMbxIsFull = FALSE;
        }


        MBX_CopyToSendMailbox(pMbx);
        // HBu 17.06.06: psRepeatMbx has to be set to 0, when it was repeated, otherwise it would be returned twice
        // to the empty queue (MAILBOX_QUEUE=1) or a buffer get lost, if the the next repeat request will happen before
        // the repeated buffer was read
        psRepeatMbx = NULL;
        LEAVE_MBX_CRITICAL;
    }

    // Repeat was finished, toggle the acknowledge bit
    bMbxRepeatToggle = !bMbxRepeatToggle;
}

/*********************************************************************************
 \param pMbx            Pointer to a Mailbox command to be sent (read by the Master)
 \param flags            Bit 0-6:    mailbox protocol type:
                                        0x01 - emergency service
                                        0x02 - CoE service
                                        0x04 - SoE service
                                        0x80 - EoE service
                                        0x10 - AoE service
                                        0x20 - VoE service
                             Bit 7:   0 - no more fragments to be sent for the requested mailbox service
                                       1 - additional fragments to be sent for the mailbox service, the
                                            corresponding XXXX_ContinueInd-function will be called to get
                                            the next fragment

 \return    0: Success - mailbox command could be stored in the send mailbox
            1: Failed - mailbox command could not be stored in the send mailbox, the
                            XXXX_ContinueInd service will be called when the mailbox was
                            read from the master to

 \brief        This function puts a new Mailbox service in the Send Mailbox
*********************************************************************************/

UINT8 MBX_MailboxSendReq( TMBX MBXMEM * pMbx, UINT8 flags )
{
    UINT8 result = 0;

    /* HBu 06.02.06: in INIT-state a mailbox send request shall be refused */
    if ( (nAlStatus & STATE_MASK) == STATE_INIT )
        return ERROR_INVALIDSTATE;


    ENTER_MBX_CRITICAL;
    DISABLE_MBX_INT;

    /* the counter in the mailbox header has to be incremented with every new mailbox service to be sent
       if the mailbox data link layer is supported (software switch MAILBOX_REPEAT_SUPPORTED set)*/
    pMbx->MbxHeader.Flags[MBX_OFFS_COUNTER] &= ~MBX_MASK_COUNTER;
    /* HBu 13.02.06: Repeat-Counter was incremented too much if the mailbox service could not be sent */
    /* u8MbxCounter holds the actual counter for the mailbox header, only the values
       1-7 are allowed if the mailbox data link layer is supported  */
    if ((u8MbxReadCounter & 0x07) == 0 )
        u8MbxReadCounter = 1;

    pMbx->MbxHeader.Flags[MBX_OFFS_COUNTER] |= u8MbxReadCounter << MBX_SHIFT_COUNTER;

    /* try to copy the mailbox command in the ESC */
    if ( MBX_CopyToSendMailbox(pMbx) != 0 )
    {
        /* no success, send mailbox was full, set flag  */
        result = PutInMbxQueue(pMbx, &sMbxSendQueue);
        if (result != 0)
            flags |= FRAGMENTS_FOLLOW;
        else
            u8MbxReadCounter++;
    }
    /* HBu 13.02.06: Repeat-Counter was incremented too much if the mailbox service could not be sent */
    else
    {
        u8MbxReadCounter++;
    }

    if ( flags & FRAGMENTS_FOLLOW )
    {
        /* store the mailbox service that the corresponding XXX_ContinueInd function will
           be called when the send mailbox will have been read by the master because there
           are mailbox commands to be sent for this service */
        u8MailboxSendReqStored |= (flags & ((UINT8) ~FRAGMENTS_FOLLOW));
    }

    ENABLE_MBX_INT;
    LEAVE_MBX_CRITICAL;

    return result;
}

/*********************************************************************************
 \brief    This function is used to check if the received mailbox command can be processed.
           Also the contents of the Receive Mailbox will be copied in the variable sMbx.
*********************************************************************************/

void MBX_CheckAndCopyMailbox( void )
{
    UINT16 mbxLen;
		VARVOLATILE UINT16 smstate;

    /* get the size of the received mailbox command and acknowledge the event*/
    HW_EscReadWord(mbxLen,u16EscAddrReceiveMbx);
    
    /* the size has to be swapped here, all other bytes of the mailbox service will be swapped later */
    mbxLen = SWAPWORD(mbxLen);

    if(bNoMbxMemoryAvailable == TRUE)
    {
        /* Return a no memory error in case of any mailbox request*/
        TMBX MBXMEM *pMbx = (TMBX MBXMEM *) APPL_AllocMailboxBuffer(10); /* a mailbox error datagram length*/
       
        if(pMbx != NULL)
        {
            HMEMSET(pMbx,0x00,10);

            /* Mailbox error response: type 0 (mailbox service protocol) */
            pMbx->MbxHeader.Length               = 4;
            pMbx->MbxHeader.Flags[MBX_OFFS_TYPE]&= ~(MBX_MASK_TYPE);
            pMbx->Data[0]                        = SWAPWORD(MBXSERVICE_MBXERRORCMD);
            pMbx->Data[1]                        = SWAPWORD(MBXERR_NOMOREMEMORY);
            MBX_MailboxSendReq(pMbx, 0);

            APPL_FreeMailboxBuffer(pMbx);
        }
    }

    /* the length of the mailbox data is in the first two bytes of the mailbox,
       so the length of the mailbox header has to be added */
    mbxLen += MBX_HEADER_SIZE;

    /* in this example there are only two mailbox buffers available in the firmware (one for processing and
       one to stored the last sent response for a possible repeat request), so a
       received mailbox service can only be processed if a free buffer is available */
    if ((bSendMbxIsFull)               /* a received mailbox service will not be processed
                                              as long as the send mailbox is still full
                                              (waits to be read from the master) */
        ||( u8MailboxSendReqStored )    /* a mailbox service to be sent is still stored
                                              so the received mailbox service will not be processed
                                              until all stored mailbox services are sent */
        )
    {
        /* set flag that the processing of the mailbox service will be checked in the
            function MBX_Main (called from ECAT_Main) */

        bReceiveMbxIsLocked = TRUE;
    }
    else
    {
        /* received mailbox command can be processed, reset flag */
        bReceiveMbxIsLocked = FALSE;

        /* if the read mailbox size is too big for the buffer, set the copy size to the maximum buffer size, otherwise
           memory could be overwritten,
           the evaluation of the mailbox size will be done in the mailbox protocols called from MBX_WriteMailboxInd */

        if (mbxLen > u16ReceiveMbxSize)
            mbxLen = u16ReceiveMbxSize;

        memset(psWriteMbx,0,u16ReceiveMbxSize);

        /* if there is no more memory for mailbox buffer, the mailbox should not be read */
        if (psWriteMbx == NULL)
        {
            /* set flag that the processing of the mailbox service will be checked in the
                function MBX_Main (called from ECAT_Main) */
            bReceiveMbxIsLocked = TRUE;
            return;
        }
        /* copy the mailbox header and data*/
        HW_EscReadMbxMem((UINT8 MBXMEM *) psWriteMbx,u16EscAddrReceiveMbx,mbxLen);

        /*Read Control and Status of SyncManager 0 to check if the buffer is unlocked*/
      //  VARVOLATILE UINT16 smstate = 0x00;
			  smstate = 0x00;
        HW_EscReadWord(smstate,ESC_SYNCMAN_CONTROL_OFFSET);

        smstate = SWAPWORD(smstate);

        if(smstate & SM_STATUS_MBX_BUFFER_FULL)
        {
            /*Unlock the mailbox SyncManger buffer*/
            u16dummy = 0;
            HW_EscReadWord(u16dummy,(u16EscAddrReceiveMbx + u16ReceiveMbxSize - 2));

        }

        /* in MBX_MailboxWriteInd the mailbox protocol will be processed */
        MBX_MailboxWriteInd( psWriteMbx );
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param     pMbx        Pointer to the Mailbox command to be send to the master.

 \brief    This function copies data to the Send Mailbox.
*////////////////////////////////////////////////////////////////////////////////////////

UINT8 MBX_CopyToSendMailbox( TMBX MBXMEM *pMbx )
{
	 VARVOLATILE UINT16 smstate;
	
    if ( (nAlStatus & STATE_MASK) == STATE_INIT)
    {
        /* the mailbox is disabled if the slave is in the INIT state */
        return( ERROR_INVALIDSTATE );
    }

    if ( !bMbxRunning )
    {
        /* the mailbox is disabled if the slave is in the INIT state */
        return( ERROR_INVALIDSTATE );
    }

    if ( bSendMbxIsFull )
    {
        /* mailbox service cannot be sent because the send mailbox is still full */
        return MBXERR_NOMOREMEMORY;
    }
    else
    {
        /* the variable mbxSize contains the size of the mailbox data to be sent */
        UINT16 mbxSize = pMbx->MbxHeader.Length;
        HW_EscWriteMbxMem((UINT8 *)pMbx, u16EscAddrSendMbx, (mbxSize + MBX_HEADER_SIZE));

        /*Read Control and Status of SyncManager 1 to check if the buffer is still marked as empty*/
        //VARVOLATILE UINT16 smstate = 0x00;
			smstate = 0x00;

        HW_EscReadWord(smstate,(ESC_SYNCMAN_CONTROL_OFFSET + SIZEOF_SM_REGISTER));
        smstate = SWAPWORD(smstate);

        if(!(smstate & SM_STATUS_MBX_BUFFER_FULL))
        {
            UINT8 BytesLeft = u16SendMbxSize - (mbxSize + MBX_HEADER_SIZE);

            /*Write last Byte to trigger mailbox full flag*/
            /*Read last 2 Bytes and write them again (required if low Byte of the WORD were written before)*/
            u16dummy = 0;

            if(BytesLeft < 2)
            {
                /*The last 2Bytes are overlapping the already written buffer*/
                                
                /*Get the valid 16Bit address*/
                UINT32 LastDataAddress = ((mbxSize + MBX_HEADER_SIZE)/2)*2;
            
                /*Copy the buffer to overwrite*/
                MEMCPY((UINT16 *)&u16dummy,(((UINT8 *)pMbx) + LastDataAddress),(2 - BytesLeft));
            }

            HW_EscWriteWord(u16dummy,(u16EscAddrSendMbx + u16SendMbxSize - 2));
        }

        /* store last send mailbox service for a possible repeat
            one buffer includes the last send service (psRepeatMbx),
            the other one the actual service to be sent (psReadMbx),
            there is no buffer available for a mailbox receive service
            until the last sent buffer was read from the master
            the exception is after the INIT2PREOP transition, in that
            case there is no last sent service (psReadMbx = 0) */
        if(psReadMbx)
        {
            ;
        }
        else
        {
            /* only the first time after the INIT2PREOP-transition */
            psWriteMbx = &asMbx[1];
        }
        // HBu 17.06.06: psRepeatMbx was already updated in MBX_MailboxReadInd
        psReadMbx = pMbx;

        /* set flag that send mailbox is full now */
        bSendMbxIsFull = TRUE;

        return 0;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    This function is called cyclically to check if a received Mailbox service was
             stored.
*////////////////////////////////////////////////////////////////////////////////////////

void MBX_Main(void)
{
    TMBX MBXMEM *pMbx = NULL;

    do
    {
        UINT8 result = 0;

        pMbx = GetOutOfMbxQueue(&sMbxReceiveQueue);

        if ( pMbx )
            result = MailboxServiceInd(pMbx);

        if ( result != 0 )
        {
            /* Mailbox error response: type 0 (mailbox service protocol) */
            pMbx->MbxHeader.Length                = 4;
            pMbx->MbxHeader.Flags[MBX_OFFS_TYPE] &= ~(MBX_MASK_TYPE);
            pMbx->Data[0]                         = SWAPWORD(MBXSERVICE_MBXERRORCMD);
            pMbx->Data[1]                         = SWAPWORD(result);
            MBX_MailboxSendReq(pMbx, 0);
        }
    }while ( pMbx != NULL );

    //dump queued emcy message if send mailbox buffer is empty
    if(bMbxRunning && !bSendMbxIsFull && !EMCY_IsQueueEmpty())
    {
        TEMCYMESSAGE EMCYMEM *pEmcy = GetOutOfSendEmcyQueue();
        EMCY_SendEmergency(pEmcy);
    }

    if ( bReceiveMbxIsLocked )
    {
        /* the work on the receive mailbox is locked, check if it can be unlocked (if all
           mailbox commands has been sent */
        MBX_CheckAndCopyMailbox();
    }
}

