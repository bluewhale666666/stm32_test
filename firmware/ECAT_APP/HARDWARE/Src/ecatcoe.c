#include "ecat_def.h"

#include "sdoserv.h"
#define    _ECATCOE_    1
#include "ecatcoe.h"
#undef      _ECATCOE_

#define    ECATCOE        0x4300
#define    ECATCOEMAX     0x02


/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    This function intialize the CoE Interface.
*////////////////////////////////////////////////////////////////////////////////////////

void COE_Init(void)
{
    pCoeSendStored        = 0;
    nSdoInfoFragmentsLeft = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param     pCoeMbx      Pointer to the received mailbox data from the master.

 \return    result of the operation (0 (success) or mailbox error code (MBXERR_.... defined in
            mailbox.h))

 \brief    This function is called when a CoE (CAN application layer over EtherCAT) service is received from
             the master.
*////////////////////////////////////////////////////////////////////////////////////////

UINT8 COE_ServiceInd(TCOEMBX MBXMEM *pCoeMbx)
{
    UINT8 result = 0;

    switch ((pCoeMbx->CoeHeader & COEHEADER_COESERVICEMASK) >> COEHEADER_COESERVICESHIFT)
    {
    case COESERVICE_SDOREQUEST:
        /* SDO-Request received, call SDOS_SdoInd to process the SDO-Request
           if an existing SDO-Stack shall be used, the corresponding function
            should be called */
        result = SDOS_SdoInd( (TINITSDOMBX MBXMEM *) pCoeMbx );
        break;

    case COESERVICE_SDOINFO:
        /* SDO-Information Request received, call SDOS_SdoInfoInd to process the SDO-Request */
        result = SDOS_SdoInfoInd( (TSDOINFORMATION MBXMEM *) pCoeMbx );
        /*NOERROR_INWORK is never returned by SDOS_SdoInfoInd() => delete return code handling*/
        break;


    case COESERVICE_SDORESPONSE:
    case COESERVICE_EMERGENCY:
    case COESERVICE_TXPDO:
    case COESERVICE_RXPDO:
    case COESERVICE_TXPDOREMREQ:
    case COESERVICE_RXPDOREMREQ:
        /* these CoE services are not supported yet */
        result = MBXERR_SERVICENOTSUPPORTED;
        break;

    default:
        result = MBXERR_INVALIDHEADER;
        break;
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param     pMbx      Pointer to the free mailbox to sent.

 \return    result of the operation (0 (success)

 \brief    This function is called when a CoE service to be sent is stored and can
 \brief  be put in the send mailbox.
*////////////////////////////////////////////////////////////////////////////////////////

UINT8 COE_ContinueInd(TMBX MBXMEM * pMbx)
{
    if (pCoeSendStored)
    {
        /* send the stored CoE service which could not be sent before */
        MBX_MailboxSendReq(pCoeSendStored, 0);
        pCoeSendStored = 0;
    }
    else
    {
        /* send the next fragment of the last CoE service (only for SDO-Information possible) */
        /* in mailbox queue mode pMbx is always 0, so a mailbox buffer shall be get */

        memset(pMbx,0,(SIZEOF(TMBX)<<1));

        /* it shall be checked if a valid pointer was returned */
        if (pMbx == NULL)
        {
            return MBXERR_NOMOREMEMORY;
        }
        else
        {
            /* copy the stored SDO-Info-Header in the request */
            MBXMEMCPY(pMbx, aSdoInfoHeader, SDO_INFO_HEADER_BYTE_SIZE);
            /* call SDOS_SdoInfoInd to generate and send the next fragment */
            SDOS_SdoInfoInd( (TSDOINFORMATION MBXMEM *) pMbx );
        }
    }

    return 0;
}

