#include "ecat_def.h"
#include "ecatslv.h"

#define    _ECATFOE_ 1
#include "ecatfoe.h"
#undef    _ECATFOE_
#define    _ECATFOE_ 0

#include "foeappl.h"

#define USE_FOE_COMPONENT

extern UINT16  is_update;
//extern UINT16  cpu_select;
extern UINT16  write_ok;

extern UINT16 FoEWriteFileInd(UINT16* ptData,UINT16 uLen,UINT16 end_flag);
extern void   Flash_UpdateStart(UINT16 is_ok);

void FOE_Init(void)
{
    /* no file transmission sequence is running */
    u16FileAccessState    = FOE_READY;
    /* initialize the expected packet number */
    u32PacketNo    = 0;
    pFoeSendStored = NULL;
}


/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param     pFoeInd      Pointer to the received mailbox data from the master.
 \return    result of the operation (0 (success) or mailbox error code (MBXERR_.... defined in
            mailbox.h))
 \brief    This function is called when a FoE (File Access over EtherCAT) service is received from
             the master.
*////////////////////////////////////////////////////////////////////////////////////////
TMBX MBXMEM  pfoeMbx;
UINT8 FOE_ServiceInd(TFOEMBX MBXMEM * pFoeInd)
{
    UINT8 lRet = 0;
    /* initialize the result of the service checking */
    UINT16 nextState = ECAT_FOE_ERRCODE_ILLEGAL;
    /* dataSize contains the size of the file data */
    UINT16 dataSize = SWAPWORD(pFoeInd->MbxHeader.Length) - FOE_HEADER_SIZE;

    /* it has to be checked if the mailbox protocol is correct, the sent mailbox data length has to
       great enough for the service header of the FoE service */
    if ( SWAPWORD(pFoeInd->MbxHeader.Length) < FOE_HEADER_SIZE )
        return MBXERR_SIZETOOSHORT;

    switch ( SWAPWORD(pFoeInd->FoeHeader.OpCode) )
    {
    case ECAT_FOE_OPCODE_RRQ:
        /* file read is requested */
        if ( u16FileAccessState == FOE_READY )
        {
            UINT32 u32Password = SWAPDWORD(pFoeInd->FoeHeader.Cmd.Password);
            /* last FoE sequence was finished, call application function */
            nextState = FOE_Read(pFoeInd->Data, dataSize, pFoeInd->Data, SWAPDWORD(u32Password));

            /* u32LastFileOffset contains the offset of the file which is sent now */
            u32LastFileOffset = 0;

            if (nextState <= FOE_MAXDATA)
            {
                /* the first data packet shall be sent */
                u32PacketNo    = 1;
                /* u32FileOffset contains the offset of the file which shall be sent when the next FoE ACK is received */
                u32FileOffset = nextState;
            }
            else if (nextState <= FOE_MAXBUSY)
            {
                u32PacketNo    = 0;
                u32FileOffset = 0;
                u16FileAccessState = FOE_WAIT_FOR_ACK;
            }
        }
        break;

    case ECAT_FOE_OPCODE_WRQ:
        /* file write is requested */
        if ( u16FileAccessState == FOE_READY )
        {
//            UINT32 u32Password = SWAPDWORD(pFoeInd->FoeHeader.Cmd.Password);
            /* last FoE sequence was finished, call application function */

#ifdef USE_FOE_COMPONENT
					
            nextState = FoEWriteFileInd(&pFoeInd->Data[0],dataSize,u16FileAccessState);//FOE_Write(pFoeInd->Data, dataSize, SWAPDWORD(u32Password));
#else
            nextState = 0;
#endif

            if ( nextState == 0 )
            {
                /* checking was successful, sent a FoE Ack service */
                nextState = FOE_ACK;
            }
            /* initialize the packet number */
            u32PacketNo    = 0;
        }
        break;

    case ECAT_FOE_OPCODE_DATA:
        /* file data is received */
        if ( u16FileAccessState == FOE_WAIT_FOR_DATA
          || u16FileAccessState == FOE_WAIT_FOR_LAST_DATA )
        {
            UINT32 u32CmdPacketNo = SWAPDWORD(pFoeInd->FoeHeader.Cmd.PacketNo);
            /* we are waiting for file data, service is correct */
            if ( u32CmdPacketNo == u32PacketNo )
            {
                /* the packet number is correct, call application function to store the file data */
#ifdef USE_FOE_COMPONENT	
							if((pFoeInd->Data[4] == 0x3230)&&(pFoeInd->Data[5] == 0x3438))
								nextState = 0;
                nextState = FoEWriteFileInd(&pFoeInd->Data[0],dataSize,u16FileAccessState);//FOE_Data(pFoeInd->Data, dataSize);                
							#else
                nextState = 0;
#endif
                if ( nextState == 0 )
                {
                    /* checking was successful, sent a FoE Ack service */
                    nextState = FOE_ACK;
                }
            }
            else
                nextState = ECAT_FOE_ERRCODE_PACKENO;
        }
        break;

    case ECAT_FOE_OPCODE_ACK:
        /* acknowledge is received, next file part can be sent */
        if ( u16FileAccessState == FOE_WAIT_FOR_ACK )
        {
            /* we are waiting for an acknowledge, service is correct, call the application function
               to get the next part of the file */
            nextState = FOE_Ack( u32FileOffset, pFoeInd->Data );
            /* u32LastFileOffset contains the offset of the file which is sent now */
            u32LastFileOffset = u32FileOffset;

            if (nextState <= FOE_MAXDATA) 
            {
                /* u32FileOffset contains the offset of the file which shall be sent when the next FoE ACK is received */
                u32FileOffset += nextState;
                /* increment the packet number */
                u32PacketNo++;
            }
        }
        else if ( u16FileAccessState == FOE_WAIT_FOR_LAST_ACK )
        {
            /* we were waiting for the last acknowledge, now the sequence is finished */
            nextState = FOE_FINISHED_NOACK;
        }
        break;

    case ECAT_FOE_OPCODE_ERR:
        /* a FoE Error service is received */
        if ( u16FileAccessState != FOE_READY )
        {
            UINT32 u32CmdErrorCode = SWAPDWORD(pFoeInd->FoeHeader.Cmd.ErrorCode);
            /* a file transmission sequence is active, inform the application, that this sequence
               was stopped */
            FOE_Error( u32CmdErrorCode );
            nextState = FOE_FINISHED;
        }
        break;

    case ECAT_FOE_OPCODE_BUSY:
        /* a FoE Busy service is received */
        if ( u16FileAccessState == FOE_WAIT_FOR_ACK
          || u16FileAccessState == FOE_WAIT_FOR_LAST_ACK )
        {
            /* we are waiting for an acknowledge, service is correct, call the application function
               to resend the last part of the file */
            nextState = FOE_Busy( SWAPWORD(pFoeInd->FoeHeader.Cmd.Busy.Done), u32LastFileOffset, pFoeInd->Data );
        }
        break;
    }

    if ( nextState <= FOE_MAXDATA )
    {
        /* we send DATA and wait for ACK */
        UINT32 d = SWAPDWORD(u32PacketNo);

        /* store the OpCode in the mailbox buffer */
        pFoeInd->FoeHeader.OpCode           = SWAPWORD(ECAT_FOE_OPCODE_DATA);
        /* store the packet number in the mailbox buffer */
        pFoeInd->FoeHeader.Cmd.PacketNo     = d;
     
        /* store the size of the mailbox data in the mailbox buffer */
        pFoeInd->MbxHeader.Length           = FOE_HEADER_SIZE + nextState;

        if ( nextState == u16SendMbxSize - FOE_HEADER_SIZE - MBX_HEADER_SIZE )
        {
            /* packets still following, we wait for an ACK */
            u16FileAccessState = FOE_WAIT_FOR_ACK;
        }
        else
        {
            /* it was the last Packet, we wait for the last ACK */
            u16FileAccessState = FOE_WAIT_FOR_LAST_ACK;
        }
    }
    else if ( nextState <= FOE_MAXBUSY )
    {
        /* we are still storing the received file data (in flash for example) and
           send BUSY and wait for the DATA to be sent again */
        /* store the OpCode in the mailbox buffer */
        pFoeInd->FoeHeader.OpCode                   = SWAPWORD(ECAT_FOE_OPCODE_BUSY);
        /* store the information how much progress we made until we can receive file data again */
        pFoeInd->FoeHeader.Cmd.Busy.Done            = SWAPWORD(nextState-FOE_MAXBUSY_ZERO);

        pFoeInd->FoeHeader.Cmd.Busy.Entire          = 0;
        /* store the size of the mailbox data in the mailbox buffer */

        pFoeInd->MbxHeader.Length                   = FOE_HEADER_SIZE;
    }
    else if ( nextState == FOE_ACK || nextState == FOE_ACKFINISHED )
    {
        /* we send ACK and wait for DATA
           the next file data is expected with an incremented packet number, but
           we have to acknowledge the old packet first */
        UINT32 d = SWAPDWORD(u32PacketNo);
        u32PacketNo++;
        /* store the OpCode in the mailbox buffer */
        pFoeInd->FoeHeader.OpCode                   = SWAPWORD(ECAT_FOE_OPCODE_ACK);
        /* store the packet number in the mailbox buffer */
        pFoeInd->FoeHeader.Cmd.PacketNo             = d;
        /* store the size of the mailbox data in the mailbox buffer */
        pFoeInd->MbxHeader.Length                   = FOE_HEADER_SIZE;//SIZEOF(TFOEHEADER);2019.4.24

        /* we wait for the next data part */
        if ( nextState == FOE_ACK )
            /* we wait for the next data part */
            u16FileAccessState = FOE_WAIT_FOR_DATA;
        else
            /* the last data part was received */
            u16FileAccessState = FOE_READY;
    }
    else if ( nextState < FOE_ERROR )
    {
        /* the file transmission sequence is finished, we have to send nothing */
        u16FileAccessState = FOE_READY;
        APPL_FreeMailboxBuffer(pFoeInd);
        return 0;
    }
    else
    {
        UINT32 d = SWAPDWORD(nextState);
        UINT8 b = 0;

        /* store the OpCode in the mailbox buffer */
        pFoeInd->FoeHeader.OpCode                    = SWAPWORD(ECAT_FOE_OPCODE_ERR);
        /* store the ErrorCode in the mailbox buffer */
        pFoeInd->FoeHeader.Cmd.ErrorCode            = d;
        /* store the size of the mailbox data in the mailbox buffer */
        pFoeInd->MbxHeader.Length                   = FOE_HEADER_SIZE;//SIZEOF(TFOEHEADER);2019.4.24

        /* Error Text is returned in pFoeInd->Data */
        while (b < 32)
        {
            UINT16 data = ((UINT16 MBXMEM *) pFoeInd->Data)[(b >> 1)];

            if ((data & 0x00FF) == 0)
                break;
            b++;
        
            if ((data & 0xFF00) == 0)
                break;
            b++;
        }
        if ( b < 32 )
        {
            pFoeInd->MbxHeader.Length    += b+1;
        }

        /* the file transmission sequence is finished */
        u16FileAccessState = FOE_READY;
    }

    pfoeMbx.MbxHeader.Length   =   pFoeInd->MbxHeader.Length;
    pfoeMbx.MbxHeader.Address  =   pFoeInd->MbxHeader.Address;
    pfoeMbx.MbxHeader.Flags[0] =   pFoeInd->MbxHeader.Flags[0];
    pfoeMbx.Data[0]            =   pFoeInd->FoeHeader.OpCode&0xff;
    pfoeMbx.Data[1]            =  (pFoeInd->FoeHeader.Cmd.PacketNo>> 0)&0xffff;
    pfoeMbx.Data[2]            =  (pFoeInd->FoeHeader.Cmd.PacketNo>>16)&0xffff;
    memcpy(&(pfoeMbx.Data[3]),&(pFoeInd->Data[0]),(pFoeInd->MbxHeader.Length-6));

    if ( bBootMode )
    {
        /* in BOOT mode the mailbox buffer is not sent via the mailbox functions
           because only FoE is allowed in BOOT mode, so we have to include the
            mailbox data link layer counter */
        pFoeInd->MbxHeader.Flags[MBX_OFFS_COUNTER] &= ~MBX_MASK_COUNTER;
        if ( (u8MbxReadCounter & 0x07) == 0 )
            /* counter 0 is not allowed if mailbox data link layer is supported */
            u8MbxReadCounter = 1;
        /* store the counter in the mailbox header */
        pFoeInd->MbxHeader.Flags[MBX_OFFS_COUNTER] |= u8MbxReadCounter << MBX_SHIFT_COUNTER;
        /* increment the counter for the next service */

        u8MbxReadCounter++;
        /* call the function to send the mailbox service directly,
           in BOOT mode we can be sure that the send mailbox is empty
           because no parallel services are allowed */
        lRet = MBX_CopyToSendMailbox(&pfoeMbx);
    }
    else
    {
        lRet = MBX_MailboxSendReq(&pfoeMbx, FOE_SERVICE);

        if (lRet != 0 )
        {
            /* if the mailbox service could not be sent (or stored), the response will be
               stored in the variable pFoeSendStored and will be sent automatically
                from the mailbox handler (FOE_ContinueInd) when the send mailbox will be read
                the next time from the master */
            pFoeSendStored = &pfoeMbx;//(TMBX MBXMEM *) pFoeInd;
        }
    }

#ifdef USE_FOE_COMPONENT

    if(0 == lRet)
    {
        if(1 == is_update)
        {
            is_update = 0;
            Flash_UpdateStart(write_ok);
        }
    }

#endif

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param     pMbx      Pointer to the free mailbox buffer

 \brief    This function is called when the next mailbox fragment can be sent.
*////////////////////////////////////////////////////////////////////////////////////////

void FOE_ContinueInd(TMBX MBXMEM * pMbx)
{
    if ( pFoeSendStored )
    {
        /* send the stored FoE service which could not be sent before */
        MBX_MailboxSendReq(pFoeSendStored, 0);
        pFoeSendStored = 0;
    }
}
