/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _NEPTUNE_SIO2_RPC_H_RPCGEN
#define _NEPTUNE_SIO2_RPC_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#include "neptune_sio2.h"

typedef char okBuffer[2];

typedef char timeStamp[8];

typedef u_int XTER_Status;

typedef char DIO_COMMAND[8];

typedef char DIO_RESPONSE[8];

typedef struct {
	u_int SEND_BUFFER_len;
	char *SEND_BUFFER_val;
} SEND_BUFFER;

typedef struct {
	u_int RECEIVE_BUFFER_len;
	char *RECEIVE_BUFFER_val;
} RECEIVE_BUFFER;

typedef char POLL_ARRAY[8];

enum XTER_ResetType {
	XTER_ResetType_Reset_None = 0x0,
	XTER_ResetType_Reset_SendBuffer = 0x1,
	XTER_ResetType_Reset_ReceiveBuffer = 0x2,
	XTER_ResetType_Reset_Slot = 0x4,
	XTER_ResetType_Reset_FPGA = 0x8,
	XTER_ResetType_Reset_DioSoftReset = 0x10,
	XTER_ResetType_Reset_DioReboot = 0x20,
};
typedef enum XTER_ResetType XTER_ResetType;

typedef char SLOT_MASKc[20];

struct TER_DioMultiCmd_cmd {
	SLOT_MASKc dio_slot_mask;
	DIO_COMMAND dio_command;
};
typedef struct TER_DioMultiCmd_cmd TER_DioMultiCmd_cmd;

struct TER_DioMultiCmd_resp {
	int slotid;
	XTER_Status status;
};
typedef struct TER_DioMultiCmd_resp TER_DioMultiCmd_resp;

struct TER_StartSlotPoll_cmd {
	int slotid;
	struct {
		u_int dio_command_len;
		DIO_COMMAND *dio_command_val;
	} dio_command;
};
typedef struct TER_StartSlotPoll_cmd TER_StartSlotPoll_cmd;

struct TER_StartSlotPoll_resp {
	int slotid;
	XTER_Status status;
};
typedef struct TER_StartSlotPoll_resp TER_StartSlotPoll_resp;

struct TER_GetSlotPoll_cmd {
	int slotid;
};
typedef struct TER_GetSlotPoll_cmd TER_GetSlotPoll_cmd;

struct TER_GetSlotPoll_resp {
	int slotid;
	XTER_Status status;
	struct {
		u_int dio_response_len;
		DIO_RESPONSE *dio_response_val;
	} dio_response;
};
typedef struct TER_GetSlotPoll_resp TER_GetSlotPoll_resp;

struct TER_SetSignal_cmd {
	int slotid;
	timeStamp ts;
	int signal_mask;
	int signal_state;
};
typedef struct TER_SetSignal_cmd TER_SetSignal_cmd;

struct TER_SetSignal_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SetSignal_resp TER_SetSignal_resp;

struct TER_GetErrorLog_cmd {
	int slotid;
};
typedef struct TER_GetErrorLog_cmd TER_GetErrorLog_cmd;

struct TER_GetErrorLog_resp {
	int cmdidx;
	int slotid;
	XTER_Status status;
	struct {
		u_int error_string_len;
		char *error_string_val;
	} error_string;
};
typedef struct TER_GetErrorLog_resp TER_GetErrorLog_resp;

struct TER_IsDrivePresent_cmd {
	int slotid;
	timeStamp ts;
};
typedef struct TER_IsDrivePresent_cmd TER_IsDrivePresent_cmd;

struct TER_IsDrivePresent_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
	int slot_information;
};
typedef struct TER_IsDrivePresent_resp TER_IsDrivePresent_resp;

struct TER_GetUserString_cmd {
	int slotid;
	timeStamp ts;
};
typedef struct TER_GetUserString_cmd TER_GetUserString_cmd;

struct TER_GetUserString_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
	char py_string[156];
};
typedef struct TER_GetUserString_resp TER_GetUserString_resp;

struct TER_SetUserString_cmd {
	int slotid;
	timeStamp ts;
	char py_string[156];
};
typedef struct TER_SetUserString_cmd TER_SetUserString_cmd;

struct TER_SetUserString_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SetUserString_resp TER_SetUserString_resp;

struct TER_GetSlotInfo_cmd {
	int slotid;
	timeStamp ts;
};
typedef struct TER_GetSlotInfo_cmd TER_GetSlotInfo_cmd;

struct TER_GetSlotInfo_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
	char sio_pcb_serial_num[9];
	char sio_app_ver[17];
	char sio_fpga_ver[17];
	char slot_pcb_serial_num[9];
	char slot_app_ver[17];
	char sio_pcb_part_num[17];
	char slot_pcb_part_num[17];
};
typedef struct TER_GetSlotInfo_resp TER_GetSlotInfo_resp;

struct TER_SetPowerVoltage_cmd {
	int slotid;
	timeStamp ts;
	int select_mask;
	int supply_value_mv;
};
typedef struct TER_SetPowerVoltage_cmd TER_SetPowerVoltage_cmd;

struct TER_SetPowerVoltage_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SetPowerVoltage_resp TER_SetPowerVoltage_resp;

struct TER_GetSlotStatus_cmd {
	int slotid;
	timeStamp ts;
};
typedef struct TER_GetSlotStatus_cmd TER_GetSlotStatus_cmd;

struct TER_GetSlotStatus_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
	int slot_errors;
	int slot_status_bits;
	int temp_drive_x10;
	int temp_slot_x10;
	int cool_demand_percent;
	int heat_demand_percent;
	int blower_rpm;
	int voltage_actual_3v_mv;
	int voltage_actual_5v_mv;
	int voltage_actual_12v_mv;
	int voltage_actual_18v_mv;
	int voltage_actual_heat_mv;
	int current_actual_3a_mv;
	int current_actual_5a_mv;
	int current_actual_12a_mv;
	int current_actual_heat_mv;
};
typedef struct TER_GetSlotStatus_resp TER_GetSlotStatus_resp;

struct TER_SetTempControlEnable_cmd {
	int slotid;
	timeStamp ts;
	bool_t enable;
};
typedef struct TER_SetTempControlEnable_cmd TER_SetTempControlEnable_cmd;

struct TER_SetTempControlEnable_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SetTempControlEnable_resp TER_SetTempControlEnable_resp;

struct TER_SetTargetTemperature_cmd {
	int slotid;
	timeStamp ts;
	int temp_target_x10;
	int cool_ramp_rate_x10;
	int heat_ramp_rate_x10;
	bool_t cooler_enable;
	bool_t heater_enable;
};
typedef struct TER_SetTargetTemperature_cmd TER_SetTargetTemperature_cmd;

struct TER_SetTargetTemperature_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SetTargetTemperature_resp TER_SetTargetTemperature_resp;

struct TER_GetTargetTemperature_cmd {
	int slotid;
	timeStamp ts;
};
typedef struct TER_GetTargetTemperature_cmd TER_GetTargetTemperature_cmd;

struct TER_GetTargetTemperature_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
	int temp_target_x10;
	int cool_ramp_rate_x10;
	int heat_ramp_rate_x10;
	bool_t cooler_enable;
	bool_t heater_enable;
};
typedef struct TER_GetTargetTemperature_resp TER_GetTargetTemperature_resp;

struct TER_GetSlotSettings_cmd {
	int slotid;
	timeStamp ts;
};
typedef struct TER_GetSlotSettings_cmd TER_GetSlotSettings_cmd;

struct TER_GetSlotSettings_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
	int power_supply_on_off;
	int baud_rate;
	int serial_logic_levels_mv;
	int temperature_target_x10;
	int temp_ramp_rate_cool_x10;
	int temp_ramp_rate_heat_x10;
	int slot_status_bits;
	int voltage_margin_3v_mv;
	int voltage_margin_5v_mv;
	int voltage_margin_12v_mv;
};
typedef struct TER_GetSlotSettings_resp TER_GetSlotSettings_resp;

struct TER_SetSerialLevels_cmd {
	int slotid;
	timeStamp ts;
	int logic_levels_mv;
};
typedef struct TER_SetSerialLevels_cmd TER_SetSerialLevels_cmd;

struct TER_SetSerialLevels_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SetSerialLevels_resp TER_SetSerialLevels_resp;

struct TER_IsSlotThere_cmd {
	int slotid;
	timeStamp ts;
};
typedef struct TER_IsSlotThere_cmd TER_IsSlotThere_cmd;

struct TER_IsSlotThere_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_IsSlotThere_resp TER_IsSlotThere_resp;

struct TER_GetDioInfoStatus_cmd {
	int slotid;
};
typedef struct TER_GetDioInfoStatus_cmd TER_GetDioInfoStatus_cmd;

struct TER_GetDioInfoStatus_resp {
	XTER_Status status;
	struct {
		u_int response_len;
		DIO_RESPONSE *response_val;
	} response;
};
typedef struct TER_GetDioInfoStatus_resp TER_GetDioInfoStatus_resp;

struct TER_SetSerialSelect_cmd {
	int slotid;
	timeStamp ts;
	int val;
};
typedef struct TER_SetSerialSelect_cmd TER_SetSerialSelect_cmd;

struct TER_SetSerialSelect_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SetSerialSelect_resp TER_SetSerialSelect_resp;

struct TER_SioReboot_cmd {
	timeStamp ts;
};
typedef struct TER_SioReboot_cmd TER_SioReboot_cmd;

struct TER_SioReboot_resp {
	okBuffer ok;
	int cmdidx;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SioReboot_resp TER_SioReboot_resp;

struct TER_SetDioPollOptions_cmd {
	int refresh_period;
	POLL_ARRAY poll_array;
};
typedef struct TER_SetDioPollOptions_cmd TER_SetDioPollOptions_cmd;

struct TER_SetDioPollOptions_resp {
	int cmdidx;
	XTER_Status status;
};
typedef struct TER_SetDioPollOptions_resp TER_SetDioPollOptions_resp;

struct TER_ResetSlot_cmd {
	int slotid;
	timeStamp ts;
	enum XTER_ResetType reset_type;
};
typedef struct TER_ResetSlot_cmd TER_ResetSlot_cmd;

struct TER_ResetSlot_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_ResetSlot_resp TER_ResetSlot_resp;

struct TER_PingXDR_cmd {
	int slotid;
	timeStamp ts;
};
typedef struct TER_PingXDR_cmd TER_PingXDR_cmd;

struct TER_PingXDR_resp {
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_PingXDR_resp TER_PingXDR_resp;

struct TER_SetPowerEnabled_cmd {
	int slotid;
	timeStamp ts;
	int selectMask;
	int powerOnOff;
};
typedef struct TER_SetPowerEnabled_cmd TER_SetPowerEnabled_cmd;

struct TER_SetPowerEnabled_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SetPowerEnabled_resp TER_SetPowerEnabled_resp;

struct TER_SetSerialEnable_cmd {
	int slotid;
	timeStamp ts;
	bool_t enable;
};
typedef struct TER_SetSerialEnable_cmd TER_SetSerialEnable_cmd;

struct TER_SetSerialEnable_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SetSerialEnable_resp TER_SetSerialEnable_resp;

struct TER_SetSerialParameters_cmd {
	int slotid;
	timeStamp ts;
	int baudrate;
	int numstopbits;
};
typedef struct TER_SetSerialParameters_cmd TER_SetSerialParameters_cmd;

struct TER_SetSerialParameters_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SetSerialParameters_resp TER_SetSerialParameters_resp;

struct TER_ReceiveBuffer_cmd {
	int slotid;
	timeStamp ts;
	int timeoutMilliSeconds;
	int expectedLength;
};
typedef struct TER_ReceiveBuffer_cmd TER_ReceiveBuffer_cmd;

struct TER_ReceiveBuffer_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
	RECEIVE_BUFFER buffer;
	bool_t buffer_overflow;
	u_int received_status_word_1;
};
typedef struct TER_ReceiveBuffer_resp TER_ReceiveBuffer_resp;

struct TER_SendBuffer_cmd {
	int slotid;
	timeStamp ts;
	SEND_BUFFER buffer;
};
typedef struct TER_SendBuffer_cmd TER_SendBuffer_cmd;

struct TER_SendBuffer_resp {
	okBuffer ok;
	int cmdidx;
	int slotid;
	timeStamp ts;
	XTER_Status status;
};
typedef struct TER_SendBuffer_resp TER_SendBuffer_resp;

struct TER_WriteFpgaRegister_cmd {
	u_int addr;
	u_int data;
};
typedef struct TER_WriteFpgaRegister_cmd TER_WriteFpgaRegister_cmd;

struct TER_WriteFpgaRegister_resp {
	XTER_Status status;
};
typedef struct TER_WriteFpgaRegister_resp TER_WriteFpgaRegister_resp;

struct TER_ReadFpgaRegister_cmd {
	u_int addr;
};
typedef struct TER_ReadFpgaRegister_cmd TER_ReadFpgaRegister_cmd;

struct TER_ReadFpgaRegister_resp {
	XTER_Status status;
	u_int response;
};
typedef struct TER_ReadFpgaRegister_resp TER_ReadFpgaRegister_resp;

struct TER_ReadNFpgaRegister_cmd {
	struct {
		u_int addr_len;
		u_int *addr_val;
	} addr;
};
typedef struct TER_ReadNFpgaRegister_cmd TER_ReadNFpgaRegister_cmd;

struct TER_ReadNFpgaRegister_resp {
	XTER_Status status;
	struct {
		u_int response_len;
		u_int *response_val;
	} response;
};
typedef struct TER_ReadNFpgaRegister_resp TER_ReadNFpgaRegister_resp;

struct dio_cmd {
	int slotid;
	DIO_COMMAND cmd;
};
typedef struct dio_cmd dio_cmd;

struct dio_cmd_resp {
	int slotid;
	XTER_Status status;
	DIO_COMMAND resp;
};
typedef struct dio_cmd_resp dio_cmd_resp;

#define YPBINDPROG 1
#define YPBINDVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define XTER_DioCommand XTER_TCP_COMMAND_Dio_Command
extern  dio_cmd_resp * xter_diocommand_1(dio_cmd *, CLIENT *);
extern  dio_cmd_resp * xter_diocommand_1_svc(dio_cmd *, struct svc_req *);
#define XTER_Read_Fpga_Register XTER_TCP_COMMAND_Read_Fpga_Register
extern  TER_ReadFpgaRegister_resp * xter_read_fpga_register_1(TER_ReadFpgaRegister_cmd *, CLIENT *);
extern  TER_ReadFpgaRegister_resp * xter_read_fpga_register_1_svc(TER_ReadFpgaRegister_cmd *, struct svc_req *);
#define XTER_Read_N_Fpga_Register XTER_TCP_COMMAND_Read_N_Fpga_Register
extern  TER_ReadNFpgaRegister_resp * xter_read_n_fpga_register_1(TER_ReadNFpgaRegister_cmd *, CLIENT *);
extern  TER_ReadNFpgaRegister_resp * xter_read_n_fpga_register_1_svc(TER_ReadNFpgaRegister_cmd *, struct svc_req *);
#define XTER_Write_Fpga_Register XTER_TCP_COMMAND_Write_Fpga_Register
extern  TER_WriteFpgaRegister_resp * xter_write_fpga_register_1(TER_WriteFpgaRegister_cmd *, CLIENT *);
extern  TER_WriteFpgaRegister_resp * xter_write_fpga_register_1_svc(TER_WriteFpgaRegister_cmd *, struct svc_req *);
#define XTER_Send_Buffer XTER_TCP_COMMAND_Sio_Send_Buffer
extern  TER_SendBuffer_resp * xter_send_buffer_1(TER_SendBuffer_cmd *, CLIENT *);
extern  TER_SendBuffer_resp * xter_send_buffer_1_svc(TER_SendBuffer_cmd *, struct svc_req *);
#define XTER_Receive_Buffer XTER_TCP_COMMAND_Sio_Receive_Buffer
extern  TER_ReceiveBuffer_resp * xter_receive_buffer_1(TER_ReceiveBuffer_cmd *, CLIENT *);
extern  TER_ReceiveBuffer_resp * xter_receive_buffer_1_svc(TER_ReceiveBuffer_cmd *, struct svc_req *);
#define XTER_Set_Serial_Parameters XTER_TCP_COMMAND_Set_Serial_Parameters
extern  TER_SetSerialParameters_resp * xter_set_serial_parameters_1(TER_SetSerialParameters_cmd *, CLIENT *);
extern  TER_SetSerialParameters_resp * xter_set_serial_parameters_1_svc(TER_SetSerialParameters_cmd *, struct svc_req *);
#define XTER_Set_Serial_Enable XTER_TCP_COMMAND_Set_Serial_Enable
extern  TER_SetSerialEnable_resp * xter_set_serial_enable_1(TER_SetSerialEnable_cmd *, CLIENT *);
extern  TER_SetSerialEnable_resp * xter_set_serial_enable_1_svc(TER_SetSerialEnable_cmd *, struct svc_req *);
#define XTER_Set_Power_Enabled XTER_TCP_COMMAND_Set_Power_Enabled
extern  TER_SetPowerEnabled_resp * xter_set_power_enabled_1(TER_SetPowerEnabled_cmd *, CLIENT *);
extern  TER_SetPowerEnabled_resp * xter_set_power_enabled_1_svc(TER_SetPowerEnabled_cmd *, struct svc_req *);
#define XTER_PingXDR XTER_TCP_COMMAND_PingXDR
extern  TER_PingXDR_resp * xter_pingxdr_1(TER_PingXDR_cmd *, CLIENT *);
extern  TER_PingXDR_resp * xter_pingxdr_1_svc(TER_PingXDR_cmd *, struct svc_req *);
#define XTER_ResetSlot XTER_TCP_COMMAND_ResetSlot
extern  TER_ResetSlot_resp * xter_resetslot_1(TER_ResetSlot_cmd *, CLIENT *);
extern  TER_ResetSlot_resp * xter_resetslot_1_svc(TER_ResetSlot_cmd *, struct svc_req *);
#define XTER_SetDioPollOptions XTER_TCP_COMMAND_SetDioPollOptions
extern  TER_SetDioPollOptions_resp * xter_setdiopolloptions_1(TER_SetDioPollOptions_cmd *, CLIENT *);
extern  TER_SetDioPollOptions_resp * xter_setdiopolloptions_1_svc(TER_SetDioPollOptions_cmd *, struct svc_req *);
#define XTER_SioReboot XTER_TCP_COMMAND_SioReboot
extern  TER_SioReboot_resp * xter_sioreboot_1(TER_SioReboot_cmd *, CLIENT *);
extern  TER_SioReboot_resp * xter_sioreboot_1_svc(TER_SioReboot_cmd *, struct svc_req *);
#define XTER_SetSerialSelect XTER_TCP_COMMAND_SetSerialSelect
extern  TER_SetSerialSelect_resp * xter_setserialselect_1(TER_SetSerialSelect_cmd *, CLIENT *);
extern  TER_SetSerialSelect_resp * xter_setserialselect_1_svc(TER_SetSerialSelect_cmd *, struct svc_req *);
#define XTER_GetDIOInfoStatus XTER_TCP_COMMAND_GetDIOInfoStatus
extern  TER_GetDioInfoStatus_resp * xter_getdioinfostatus_1(TER_GetDioInfoStatus_cmd *, CLIENT *);
extern  TER_GetDioInfoStatus_resp * xter_getdioinfostatus_1_svc(TER_GetDioInfoStatus_cmd *, struct svc_req *);
#define XTER_IsSlotThere XTER_TCP_COMMAND_IsSlotThere
extern  TER_IsSlotThere_resp * xter_isslotthere_1(TER_IsSlotThere_cmd *, CLIENT *);
extern  TER_IsSlotThere_resp * xter_isslotthere_1_svc(TER_IsSlotThere_cmd *, struct svc_req *);
#define XTER_SetSerialLevels XTER_TCP_COMMAND_SetSerialLevels
extern  TER_SetSerialLevels_resp * xter_setseriallevels_1(TER_SetSerialLevels_cmd *, CLIENT *);
extern  TER_SetSerialLevels_resp * xter_setseriallevels_1_svc(TER_SetSerialLevels_cmd *, struct svc_req *);
#define XTER_GetSlotSettings XTER_TCP_COMMAND_GetSlotSettings
extern  TER_GetSlotSettings_resp * xter_getslotsettings_1(TER_GetSlotSettings_cmd *, CLIENT *);
extern  TER_GetSlotSettings_resp * xter_getslotsettings_1_svc(TER_GetSlotSettings_cmd *, struct svc_req *);
#define XTER_SetTargetTemperature XTER_TCP_COMMAND_SetTargetTemperature
extern  TER_SetTargetTemperature_resp * xter_settargettemperature_1(TER_SetTargetTemperature_cmd *, CLIENT *);
extern  TER_SetTargetTemperature_resp * xter_settargettemperature_1_svc(TER_SetTargetTemperature_cmd *, struct svc_req *);
#define XTER_GetTargetTemperature XTER_TCP_COMMAND_GetTargetTemperature
extern  TER_GetTargetTemperature_resp * xter_gettargettemperature_1(TER_GetTargetTemperature_cmd *, CLIENT *);
extern  TER_GetTargetTemperature_resp * xter_gettargettemperature_1_svc(TER_GetTargetTemperature_cmd *, struct svc_req *);
#define XTER_SetTempControlEnable XTER_TCP_COMMAND_SetTempControlEnable
extern  TER_SetTempControlEnable_resp * xter_settempcontrolenable_1(TER_SetTempControlEnable_cmd *, CLIENT *);
extern  TER_SetTempControlEnable_resp * xter_settempcontrolenable_1_svc(TER_SetTempControlEnable_cmd *, struct svc_req *);
#define XTER_GetSlotStatus XTER_TCP_COMMAND_GetSlotStatus
extern  struct TER_GetSlotStatus_resp * xter_getslotstatus_1(struct TER_GetSlotStatus_cmd *, CLIENT *);
extern  struct TER_GetSlotStatus_resp * xter_getslotstatus_1_svc(struct TER_GetSlotStatus_cmd *, struct svc_req *);
#define XTER_SetPowerVoltage XTER_TCP_COMMAND_SetPowerVoltage
extern  struct TER_SetPowerVoltage_resp * xter_setpowervoltage_1(struct TER_SetPowerVoltage_cmd *, CLIENT *);
extern  struct TER_SetPowerVoltage_resp * xter_setpowervoltage_1_svc(struct TER_SetPowerVoltage_cmd *, struct svc_req *);
#define XTER_GetSlotInfo XTER_TCP_COMMAND_GetSlotInfo
extern  struct TER_GetSlotInfo_resp * xter_getslotinfo_1(struct TER_GetSlotInfo_cmd *, CLIENT *);
extern  struct TER_GetSlotInfo_resp * xter_getslotinfo_1_svc(struct TER_GetSlotInfo_cmd *, struct svc_req *);
#define XTER_GetUserString XTER_TCP_COMMAND_GetUserString
extern  struct TER_GetUserString_resp * xter_getuserstring_1(struct TER_GetUserString_cmd *, CLIENT *);
extern  struct TER_GetUserString_resp * xter_getuserstring_1_svc(struct TER_GetUserString_cmd *, struct svc_req *);
#define XTER_SetUserString XTER_TCP_COMMAND_SetUserString
extern  struct TER_SetUserString_resp * xter_setuserstring_1(struct TER_SetUserString_cmd *, CLIENT *);
extern  struct TER_SetUserString_resp * xter_setuserstring_1_svc(struct TER_SetUserString_cmd *, struct svc_req *);
#define XTER_IsDrivePresent XTER_TCP_COMMAND_IsDrivePresent
extern  struct TER_IsDrivePresent_resp * xter_isdrivepresent_1(struct TER_IsDrivePresent_cmd *, CLIENT *);
extern  struct TER_IsDrivePresent_resp * xter_isdrivepresent_1_svc(struct TER_IsDrivePresent_cmd *, struct svc_req *);
#define XTER_GetErrorLog XTER_TCP_COMMAND_GetErrorLog
extern  struct TER_GetErrorLog_resp * xter_geterrorlog_1(struct TER_GetErrorLog_cmd *, CLIENT *);
extern  struct TER_GetErrorLog_resp * xter_geterrorlog_1_svc(struct TER_GetErrorLog_cmd *, struct svc_req *);
#define XTER_SetSignal XTER_TCP_COMMAND_SetSignal
extern  struct TER_SetSignal_resp * xter_setsignal_1(struct TER_SetSignal_cmd *, CLIENT *);
extern  struct TER_SetSignal_resp * xter_setsignal_1_svc(struct TER_SetSignal_cmd *, struct svc_req *);
#define XTER_StartSlotPoll XTER_TCP_COMMAND_StartSlotPoll
extern  struct TER_StartSlotPoll_resp * xter_startslotpoll_1(struct TER_StartSlotPoll_cmd *, CLIENT *);
extern  struct TER_StartSlotPoll_resp * xter_startslotpoll_1_svc(struct TER_StartSlotPoll_cmd *, struct svc_req *);
#define XTER_GetSlotPoll XTER_TCP_COMMAND_GetSlotPoll
extern  struct TER_GetSlotPoll_resp * xter_getslotpoll_1(struct TER_GetSlotPoll_cmd *, CLIENT *);
extern  struct TER_GetSlotPoll_resp * xter_getslotpoll_1_svc(struct TER_GetSlotPoll_cmd *, struct svc_req *);
#define XTER_DioMultiCmd XTER_TCP_COMMAND_DioMultiCmd
extern  struct TER_DioMultiCmd_resp_resp * xter_diomulticmd_1(struct TER_DioMultiCmd_cmd *, CLIENT *);
extern  struct TER_DioMultiCmd_resp_resp * xter_diomulticmd_1_svc(struct TER_DioMultiCmd_cmd *, struct svc_req *);
extern int ypbindprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define XTER_DioCommand XTER_TCP_COMMAND_Dio_Command
extern  dio_cmd_resp * xter_diocommand_1();
extern  dio_cmd_resp * xter_diocommand_1_svc();
#define XTER_Read_Fpga_Register XTER_TCP_COMMAND_Read_Fpga_Register
extern  TER_ReadFpgaRegister_resp * xter_read_fpga_register_1();
extern  TER_ReadFpgaRegister_resp * xter_read_fpga_register_1_svc();
#define XTER_Read_N_Fpga_Register XTER_TCP_COMMAND_Read_N_Fpga_Register
extern  TER_ReadNFpgaRegister_resp * xter_read_n_fpga_register_1();
extern  TER_ReadNFpgaRegister_resp * xter_read_n_fpga_register_1_svc();
#define XTER_Write_Fpga_Register XTER_TCP_COMMAND_Write_Fpga_Register
extern  TER_WriteFpgaRegister_resp * xter_write_fpga_register_1();
extern  TER_WriteFpgaRegister_resp * xter_write_fpga_register_1_svc();
#define XTER_Send_Buffer XTER_TCP_COMMAND_Sio_Send_Buffer
extern  TER_SendBuffer_resp * xter_send_buffer_1();
extern  TER_SendBuffer_resp * xter_send_buffer_1_svc();
#define XTER_Receive_Buffer XTER_TCP_COMMAND_Sio_Receive_Buffer
extern  TER_ReceiveBuffer_resp * xter_receive_buffer_1();
extern  TER_ReceiveBuffer_resp * xter_receive_buffer_1_svc();
#define XTER_Set_Serial_Parameters XTER_TCP_COMMAND_Set_Serial_Parameters
extern  TER_SetSerialParameters_resp * xter_set_serial_parameters_1();
extern  TER_SetSerialParameters_resp * xter_set_serial_parameters_1_svc();
#define XTER_Set_Serial_Enable XTER_TCP_COMMAND_Set_Serial_Enable
extern  TER_SetSerialEnable_resp * xter_set_serial_enable_1();
extern  TER_SetSerialEnable_resp * xter_set_serial_enable_1_svc();
#define XTER_Set_Power_Enabled XTER_TCP_COMMAND_Set_Power_Enabled
extern  TER_SetPowerEnabled_resp * xter_set_power_enabled_1();
extern  TER_SetPowerEnabled_resp * xter_set_power_enabled_1_svc();
#define XTER_PingXDR XTER_TCP_COMMAND_PingXDR
extern  TER_PingXDR_resp * xter_pingxdr_1();
extern  TER_PingXDR_resp * xter_pingxdr_1_svc();
#define XTER_ResetSlot XTER_TCP_COMMAND_ResetSlot
extern  TER_ResetSlot_resp * xter_resetslot_1();
extern  TER_ResetSlot_resp * xter_resetslot_1_svc();
#define XTER_SetDioPollOptions XTER_TCP_COMMAND_SetDioPollOptions
extern  TER_SetDioPollOptions_resp * xter_setdiopolloptions_1();
extern  TER_SetDioPollOptions_resp * xter_setdiopolloptions_1_svc();
#define XTER_SioReboot XTER_TCP_COMMAND_SioReboot
extern  TER_SioReboot_resp * xter_sioreboot_1();
extern  TER_SioReboot_resp * xter_sioreboot_1_svc();
#define XTER_SetSerialSelect XTER_TCP_COMMAND_SetSerialSelect
extern  TER_SetSerialSelect_resp * xter_setserialselect_1();
extern  TER_SetSerialSelect_resp * xter_setserialselect_1_svc();
#define XTER_GetDIOInfoStatus XTER_TCP_COMMAND_GetDIOInfoStatus
extern  TER_GetDioInfoStatus_resp * xter_getdioinfostatus_1();
extern  TER_GetDioInfoStatus_resp * xter_getdioinfostatus_1_svc();
#define XTER_IsSlotThere XTER_TCP_COMMAND_IsSlotThere
extern  TER_IsSlotThere_resp * xter_isslotthere_1();
extern  TER_IsSlotThere_resp * xter_isslotthere_1_svc();
#define XTER_SetSerialLevels XTER_TCP_COMMAND_SetSerialLevels
extern  TER_SetSerialLevels_resp * xter_setseriallevels_1();
extern  TER_SetSerialLevels_resp * xter_setseriallevels_1_svc();
#define XTER_GetSlotSettings XTER_TCP_COMMAND_GetSlotSettings
extern  TER_GetSlotSettings_resp * xter_getslotsettings_1();
extern  TER_GetSlotSettings_resp * xter_getslotsettings_1_svc();
#define XTER_SetTargetTemperature XTER_TCP_COMMAND_SetTargetTemperature
extern  TER_SetTargetTemperature_resp * xter_settargettemperature_1();
extern  TER_SetTargetTemperature_resp * xter_settargettemperature_1_svc();
#define XTER_GetTargetTemperature XTER_TCP_COMMAND_GetTargetTemperature
extern  TER_GetTargetTemperature_resp * xter_gettargettemperature_1();
extern  TER_GetTargetTemperature_resp * xter_gettargettemperature_1_svc();
#define XTER_SetTempControlEnable XTER_TCP_COMMAND_SetTempControlEnable
extern  TER_SetTempControlEnable_resp * xter_settempcontrolenable_1();
extern  TER_SetTempControlEnable_resp * xter_settempcontrolenable_1_svc();
#define XTER_GetSlotStatus XTER_TCP_COMMAND_GetSlotStatus
extern  struct TER_GetSlotStatus_resp * xter_getslotstatus_1();
extern  struct TER_GetSlotStatus_resp * xter_getslotstatus_1_svc();
#define XTER_SetPowerVoltage XTER_TCP_COMMAND_SetPowerVoltage
extern  struct TER_SetPowerVoltage_resp * xter_setpowervoltage_1();
extern  struct TER_SetPowerVoltage_resp * xter_setpowervoltage_1_svc();
#define XTER_GetSlotInfo XTER_TCP_COMMAND_GetSlotInfo
extern  struct TER_GetSlotInfo_resp * xter_getslotinfo_1();
extern  struct TER_GetSlotInfo_resp * xter_getslotinfo_1_svc();
#define XTER_GetUserString XTER_TCP_COMMAND_GetUserString
extern  struct TER_GetUserString_resp * xter_getuserstring_1();
extern  struct TER_GetUserString_resp * xter_getuserstring_1_svc();
#define XTER_SetUserString XTER_TCP_COMMAND_SetUserString
extern  struct TER_SetUserString_resp * xter_setuserstring_1();
extern  struct TER_SetUserString_resp * xter_setuserstring_1_svc();
#define XTER_IsDrivePresent XTER_TCP_COMMAND_IsDrivePresent
extern  struct TER_IsDrivePresent_resp * xter_isdrivepresent_1();
extern  struct TER_IsDrivePresent_resp * xter_isdrivepresent_1_svc();
#define XTER_GetErrorLog XTER_TCP_COMMAND_GetErrorLog
extern  struct TER_GetErrorLog_resp * xter_geterrorlog_1();
extern  struct TER_GetErrorLog_resp * xter_geterrorlog_1_svc();
#define XTER_SetSignal XTER_TCP_COMMAND_SetSignal
extern  struct TER_SetSignal_resp * xter_setsignal_1();
extern  struct TER_SetSignal_resp * xter_setsignal_1_svc();
#define XTER_StartSlotPoll XTER_TCP_COMMAND_StartSlotPoll
extern  struct TER_StartSlotPoll_resp * xter_startslotpoll_1();
extern  struct TER_StartSlotPoll_resp * xter_startslotpoll_1_svc();
#define XTER_GetSlotPoll XTER_TCP_COMMAND_GetSlotPoll
extern  struct TER_GetSlotPoll_resp * xter_getslotpoll_1();
extern  struct TER_GetSlotPoll_resp * xter_getslotpoll_1_svc();
#define XTER_DioMultiCmd XTER_TCP_COMMAND_DioMultiCmd
extern  struct TER_DioMultiCmd_resp_resp * xter_diomulticmd_1();
extern  struct TER_DioMultiCmd_resp_resp * xter_diomulticmd_1_svc();
extern int ypbindprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_okBuffer (XDR *, okBuffer);
extern  bool_t xdr_timeStamp (XDR *, timeStamp);
extern  bool_t xdr_XTER_Status (XDR *, XTER_Status*);
extern  bool_t xdr_DIO_COMMAND (XDR *, DIO_COMMAND);
extern  bool_t xdr_DIO_RESPONSE (XDR *, DIO_RESPONSE);
extern  bool_t xdr_SEND_BUFFER (XDR *, SEND_BUFFER*);
extern  bool_t xdr_RECEIVE_BUFFER (XDR *, RECEIVE_BUFFER*);
extern  bool_t xdr_POLL_ARRAY (XDR *, POLL_ARRAY);
extern  bool_t xdr_XTER_ResetType (XDR *, XTER_ResetType*);
extern  bool_t xdr_SLOT_MASKc (XDR *, SLOT_MASKc);
extern  bool_t xdr_TER_DioMultiCmd_cmd (XDR *, TER_DioMultiCmd_cmd*);
extern  bool_t xdr_TER_DioMultiCmd_resp (XDR *, TER_DioMultiCmd_resp*);
extern  bool_t xdr_TER_StartSlotPoll_cmd (XDR *, TER_StartSlotPoll_cmd*);
extern  bool_t xdr_TER_StartSlotPoll_resp (XDR *, TER_StartSlotPoll_resp*);
extern  bool_t xdr_TER_GetSlotPoll_cmd (XDR *, TER_GetSlotPoll_cmd*);
extern  bool_t xdr_TER_GetSlotPoll_resp (XDR *, TER_GetSlotPoll_resp*);
extern  bool_t xdr_TER_SetSignal_cmd (XDR *, TER_SetSignal_cmd*);
extern  bool_t xdr_TER_SetSignal_resp (XDR *, TER_SetSignal_resp*);
extern  bool_t xdr_TER_GetErrorLog_cmd (XDR *, TER_GetErrorLog_cmd*);
extern  bool_t xdr_TER_GetErrorLog_resp (XDR *, TER_GetErrorLog_resp*);
extern  bool_t xdr_TER_IsDrivePresent_cmd (XDR *, TER_IsDrivePresent_cmd*);
extern  bool_t xdr_TER_IsDrivePresent_resp (XDR *, TER_IsDrivePresent_resp*);
extern  bool_t xdr_TER_GetUserString_cmd (XDR *, TER_GetUserString_cmd*);
extern  bool_t xdr_TER_GetUserString_resp (XDR *, TER_GetUserString_resp*);
extern  bool_t xdr_TER_SetUserString_cmd (XDR *, TER_SetUserString_cmd*);
extern  bool_t xdr_TER_SetUserString_resp (XDR *, TER_SetUserString_resp*);
extern  bool_t xdr_TER_GetSlotInfo_cmd (XDR *, TER_GetSlotInfo_cmd*);
extern  bool_t xdr_TER_GetSlotInfo_resp (XDR *, TER_GetSlotInfo_resp*);
extern  bool_t xdr_TER_SetPowerVoltage_cmd (XDR *, TER_SetPowerVoltage_cmd*);
extern  bool_t xdr_TER_SetPowerVoltage_resp (XDR *, TER_SetPowerVoltage_resp*);
extern  bool_t xdr_TER_GetSlotStatus_cmd (XDR *, TER_GetSlotStatus_cmd*);
extern  bool_t xdr_TER_GetSlotStatus_resp (XDR *, TER_GetSlotStatus_resp*);
extern  bool_t xdr_TER_SetTempControlEnable_cmd (XDR *, TER_SetTempControlEnable_cmd*);
extern  bool_t xdr_TER_SetTempControlEnable_resp (XDR *, TER_SetTempControlEnable_resp*);
extern  bool_t xdr_TER_SetTargetTemperature_cmd (XDR *, TER_SetTargetTemperature_cmd*);
extern  bool_t xdr_TER_SetTargetTemperature_resp (XDR *, TER_SetTargetTemperature_resp*);
extern  bool_t xdr_TER_GetTargetTemperature_cmd (XDR *, TER_GetTargetTemperature_cmd*);
extern  bool_t xdr_TER_GetTargetTemperature_resp (XDR *, TER_GetTargetTemperature_resp*);
extern  bool_t xdr_TER_GetSlotSettings_cmd (XDR *, TER_GetSlotSettings_cmd*);
extern  bool_t xdr_TER_GetSlotSettings_resp (XDR *, TER_GetSlotSettings_resp*);
extern  bool_t xdr_TER_SetSerialLevels_cmd (XDR *, TER_SetSerialLevels_cmd*);
extern  bool_t xdr_TER_SetSerialLevels_resp (XDR *, TER_SetSerialLevels_resp*);
extern  bool_t xdr_TER_IsSlotThere_cmd (XDR *, TER_IsSlotThere_cmd*);
extern  bool_t xdr_TER_IsSlotThere_resp (XDR *, TER_IsSlotThere_resp*);
extern  bool_t xdr_TER_GetDioInfoStatus_cmd (XDR *, TER_GetDioInfoStatus_cmd*);
extern  bool_t xdr_TER_GetDioInfoStatus_resp (XDR *, TER_GetDioInfoStatus_resp*);
extern  bool_t xdr_TER_SetSerialSelect_cmd (XDR *, TER_SetSerialSelect_cmd*);
extern  bool_t xdr_TER_SetSerialSelect_resp (XDR *, TER_SetSerialSelect_resp*);
extern  bool_t xdr_TER_SioReboot_cmd (XDR *, TER_SioReboot_cmd*);
extern  bool_t xdr_TER_SioReboot_resp (XDR *, TER_SioReboot_resp*);
extern  bool_t xdr_TER_SetDioPollOptions_cmd (XDR *, TER_SetDioPollOptions_cmd*);
extern  bool_t xdr_TER_SetDioPollOptions_resp (XDR *, TER_SetDioPollOptions_resp*);
extern  bool_t xdr_TER_ResetSlot_cmd (XDR *, TER_ResetSlot_cmd*);
extern  bool_t xdr_TER_ResetSlot_resp (XDR *, TER_ResetSlot_resp*);
extern  bool_t xdr_TER_PingXDR_cmd (XDR *, TER_PingXDR_cmd*);
extern  bool_t xdr_TER_PingXDR_resp (XDR *, TER_PingXDR_resp*);
extern  bool_t xdr_TER_SetPowerEnabled_cmd (XDR *, TER_SetPowerEnabled_cmd*);
extern  bool_t xdr_TER_SetPowerEnabled_resp (XDR *, TER_SetPowerEnabled_resp*);
extern  bool_t xdr_TER_SetSerialEnable_cmd (XDR *, TER_SetSerialEnable_cmd*);
extern  bool_t xdr_TER_SetSerialEnable_resp (XDR *, TER_SetSerialEnable_resp*);
extern  bool_t xdr_TER_SetSerialParameters_cmd (XDR *, TER_SetSerialParameters_cmd*);
extern  bool_t xdr_TER_SetSerialParameters_resp (XDR *, TER_SetSerialParameters_resp*);
extern  bool_t xdr_TER_ReceiveBuffer_cmd (XDR *, TER_ReceiveBuffer_cmd*);
extern  bool_t xdr_TER_ReceiveBuffer_resp (XDR *, TER_ReceiveBuffer_resp*);
extern  bool_t xdr_TER_SendBuffer_cmd (XDR *, TER_SendBuffer_cmd*);
extern  bool_t xdr_TER_SendBuffer_resp (XDR *, TER_SendBuffer_resp*);
extern  bool_t xdr_TER_WriteFpgaRegister_cmd (XDR *, TER_WriteFpgaRegister_cmd*);
extern  bool_t xdr_TER_WriteFpgaRegister_resp (XDR *, TER_WriteFpgaRegister_resp*);
extern  bool_t xdr_TER_ReadFpgaRegister_cmd (XDR *, TER_ReadFpgaRegister_cmd*);
extern  bool_t xdr_TER_ReadFpgaRegister_resp (XDR *, TER_ReadFpgaRegister_resp*);
extern  bool_t xdr_TER_ReadNFpgaRegister_cmd (XDR *, TER_ReadNFpgaRegister_cmd*);
extern  bool_t xdr_TER_ReadNFpgaRegister_resp (XDR *, TER_ReadNFpgaRegister_resp*);
extern  bool_t xdr_dio_cmd (XDR *, dio_cmd*);
extern  bool_t xdr_dio_cmd_resp (XDR *, dio_cmd_resp*);

#else /* K&R C */
extern bool_t xdr_okBuffer ();
extern bool_t xdr_timeStamp ();
extern bool_t xdr_XTER_Status ();
extern bool_t xdr_DIO_COMMAND ();
extern bool_t xdr_DIO_RESPONSE ();
extern bool_t xdr_SEND_BUFFER ();
extern bool_t xdr_RECEIVE_BUFFER ();
extern bool_t xdr_POLL_ARRAY ();
extern bool_t xdr_XTER_ResetType ();
extern bool_t xdr_SLOT_MASKc ();
extern bool_t xdr_TER_DioMultiCmd_cmd ();
extern bool_t xdr_TER_DioMultiCmd_resp ();
extern bool_t xdr_TER_StartSlotPoll_cmd ();
extern bool_t xdr_TER_StartSlotPoll_resp ();
extern bool_t xdr_TER_GetSlotPoll_cmd ();
extern bool_t xdr_TER_GetSlotPoll_resp ();
extern bool_t xdr_TER_SetSignal_cmd ();
extern bool_t xdr_TER_SetSignal_resp ();
extern bool_t xdr_TER_GetErrorLog_cmd ();
extern bool_t xdr_TER_GetErrorLog_resp ();
extern bool_t xdr_TER_IsDrivePresent_cmd ();
extern bool_t xdr_TER_IsDrivePresent_resp ();
extern bool_t xdr_TER_GetUserString_cmd ();
extern bool_t xdr_TER_GetUserString_resp ();
extern bool_t xdr_TER_SetUserString_cmd ();
extern bool_t xdr_TER_SetUserString_resp ();
extern bool_t xdr_TER_GetSlotInfo_cmd ();
extern bool_t xdr_TER_GetSlotInfo_resp ();
extern bool_t xdr_TER_SetPowerVoltage_cmd ();
extern bool_t xdr_TER_SetPowerVoltage_resp ();
extern bool_t xdr_TER_GetSlotStatus_cmd ();
extern bool_t xdr_TER_GetSlotStatus_resp ();
extern bool_t xdr_TER_SetTempControlEnable_cmd ();
extern bool_t xdr_TER_SetTempControlEnable_resp ();
extern bool_t xdr_TER_SetTargetTemperature_cmd ();
extern bool_t xdr_TER_SetTargetTemperature_resp ();
extern bool_t xdr_TER_GetTargetTemperature_cmd ();
extern bool_t xdr_TER_GetTargetTemperature_resp ();
extern bool_t xdr_TER_GetSlotSettings_cmd ();
extern bool_t xdr_TER_GetSlotSettings_resp ();
extern bool_t xdr_TER_SetSerialLevels_cmd ();
extern bool_t xdr_TER_SetSerialLevels_resp ();
extern bool_t xdr_TER_IsSlotThere_cmd ();
extern bool_t xdr_TER_IsSlotThere_resp ();
extern bool_t xdr_TER_GetDioInfoStatus_cmd ();
extern bool_t xdr_TER_GetDioInfoStatus_resp ();
extern bool_t xdr_TER_SetSerialSelect_cmd ();
extern bool_t xdr_TER_SetSerialSelect_resp ();
extern bool_t xdr_TER_SioReboot_cmd ();
extern bool_t xdr_TER_SioReboot_resp ();
extern bool_t xdr_TER_SetDioPollOptions_cmd ();
extern bool_t xdr_TER_SetDioPollOptions_resp ();
extern bool_t xdr_TER_ResetSlot_cmd ();
extern bool_t xdr_TER_ResetSlot_resp ();
extern bool_t xdr_TER_PingXDR_cmd ();
extern bool_t xdr_TER_PingXDR_resp ();
extern bool_t xdr_TER_SetPowerEnabled_cmd ();
extern bool_t xdr_TER_SetPowerEnabled_resp ();
extern bool_t xdr_TER_SetSerialEnable_cmd ();
extern bool_t xdr_TER_SetSerialEnable_resp ();
extern bool_t xdr_TER_SetSerialParameters_cmd ();
extern bool_t xdr_TER_SetSerialParameters_resp ();
extern bool_t xdr_TER_ReceiveBuffer_cmd ();
extern bool_t xdr_TER_ReceiveBuffer_resp ();
extern bool_t xdr_TER_SendBuffer_cmd ();
extern bool_t xdr_TER_SendBuffer_resp ();
extern bool_t xdr_TER_WriteFpgaRegister_cmd ();
extern bool_t xdr_TER_WriteFpgaRegister_resp ();
extern bool_t xdr_TER_ReadFpgaRegister_cmd ();
extern bool_t xdr_TER_ReadFpgaRegister_resp ();
extern bool_t xdr_TER_ReadNFpgaRegister_cmd ();
extern bool_t xdr_TER_ReadNFpgaRegister_resp ();
extern bool_t xdr_dio_cmd ();
extern bool_t xdr_dio_cmd_resp ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_NEPTUNE_SIO2_RPC_H_RPCGEN */
