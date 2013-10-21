/*
 * neptune_hitachi_interface.h
 */

#ifndef NEPTUNE_HITACHI_INTERFACE_H_
#define NEPTUNE_HITACHI_INTERFACE_H_


/*******************  WAPI Log Levels **************************
Log Level 0: Disabled. 
Log Level 1 (Default): Only Wrapper Error Messages (TLOG_ERROR). 
Log Level 2: All Wrapper Messages (TLOG_ERROR , TLOG_ENTRY, TLOG_EXIT, TLOG_TRACE)
Log Level 3: a) All Wrapper Messages (TLOG_ERROR , TLOG_ENTRY, TLOG_EXIT, TLOG_TRACE) b) SIO Journal on error (100 SIO Journal entries)
Log Level 4: a) All Wrapper Messages (TLOG_ERROR , TLOG_ENTRY, TLOG_EXIT, TLOG_TRACE) b) SIO Journal on error (100 SIO Journal entries) c) SIO Journal in siFinalize()
****************************************************************/

#define  WAPI_DEFAULT_LOG_LEVEL   1

#define TLOG_ENTRY(fmt, ...)   if(siLogLevel>1) \
							   {terPrintf(fmt, ## __VA_ARGS__);}
#define TLOG_TRACE(fmt, ...)   if(siLogLevel>1) \
                               {terPrintf(fmt, ## __VA_ARGS__);}
#define TLOG_EXIT(fmt, ...)    if(siLogLevel>1) \
							   {terPrintf(fmt, ## __VA_ARGS__);}
#define TLOG_WARNING(fmt, ...) terPrintf(fmt, ## __VA_ARGS__)

#define TLOG_ERROR(fmt, ...)   if(siLogLevel>=1) \
                               terPrintf(fmt, ## __VA_ARGS__);	\


#define TLOG_BUFFER(txt,buf,size)   if(siLogLevel>1)\
									{printBuffer((txt),(buf),(size));}

#define WAPI_RPC_LAST_ATTEMPT 2
#define WAPI_CALL_RPC_WITh_RETRY(SIO_API)  	SIO_API;             \
 	if (status == TER_Status_rpc_fail) {                         \
       TLOG_TRACE("ERROR: TER_Status_rpc_fail. Trying to reconnect.. \n"); \
	   for(int cnt = 1; cnt <= WAPI_RPC_LAST_ATTEMPT; ++cnt) {   \
    	   rc = terSio2Reconnect(bCellNo);                  \
		   if( rc != Success ) {                                 \
	    	   TLOG_ERROR("ERROR: Could not reconnect to socket \n"); return(TerError); \
           }                                          \
	       SIO_API;                                   \
		   if( status != TER_Status_rpc_fail ) break; \
	   } \
	}


typedef enum TER_WAPI_Error						
{
	Success = 0,
	TerError = 1,
	DriveError = 2,
    SIO_Not_Reachable=3,         		/* Either SIO is down or network error */
	SIO_Socket_Error=4,             	/* SIO is not accepting Socket connection */
	DIO_Non_Responsive=5,      			/* Cannot talk to DIO */
	DIO_App_Error=6,                 	/* DIO is Bootloader, not running App f/w */
	DIO_Firmware_Update_Error=7 ,       /* DIO f/w update failed */	
	DriveAckSuccess = 0x80,
	DriveAckReceiverOverrun = 0x81,
	DriveAckDataUnstable = 0x82,
	DriveAckFrameError = 0x84,
	DriveAckInvalidSyncPacket = 0x88,
	DriveAckInvalidLengthPacket = 0x90,
	DriveAckCommandChecksumError = 0xA0,
	DriveAckFlowControlError = 0xA1,
	DriveAckInvalidState = 0xC0,
	DriveAckCommandReject = 0xC1
};


extern void terSetWapiTestMode(Byte bCellNo, Byte bMode);
extern Byte terGetWapiTestMode(Byte bCellNo);

#endif /* NEPTUNE_HITACHI_INTERFACE_H_ */
