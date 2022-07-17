#ifndef __COMM_VOICE_H__
#define __COMM_VOICE_H__

#include "main.h"

#if  NEW_VOICE_ADDR_ENABLE == 1
#define LANGUAGE_BASE_ADDR   0x4C
#else
#define LANGUAGE_BASE_ADDR   0x34
#endif





///////////////////////音量///////////////////////////////////////////////////////////
#define HIGH_VOICE_ADJUST 0x18
#define LOW_VOICE_ADJUST	0x12
#define NO_VOICE_ADJUST 0x00
#define HAVE_VOICE_ADJUST 0x18

////////////////////////////////////////UART//////////////////////////////////////////
#define VOICE_TO_MCU_LENGTH	6
#define MCU_TO_VOICE_LENGTH 7
#define MCU_TO_VOICE_DOUBLELENGTH 8


#define MCU_TO_VOICE_DOUBLE_HEAD 					0x7E
#define MCU_TO_VOICE_DOUBLE_LENGTH_DATA 		0x06
#define DOUBLE_FLASH_PLAY_CMD  						0xB0

#define MCU_TO_VOICE_HEAD 			0x7E
#define MCU_TO_VOICE_LENGTH_DATA 		0x05
#define FLASH_PLAY_CMD  				0xA0
#define MCU_TO_VOICE_END   			0xEF
////////////DAC//////////////
#define VOICE_DAC_LENGTH 6
#define DAC_LENGTH 0x04
#define DAC_CMD  0xB6
#define DAC_PARAM 0x01
#define DAC_CHECK 0xBB
#define DAC_END 0xEF

////////////volume//////////////
#define VOICE_VOLUME_LENGTH 6
#define VOLUME_LENGTH		0x04
#define VOLUME_CMD			0xAE
//#define VOLUME_PARAM		0x1F
//#define VOLUME_CHECK	
//#define VOLUME_END


#define MCU_TO_VOICE_CONTROL_LENGTH 6

#define MCU_TO_VOICE_CHENKSUM_H	6
#define MCU_TO_VOICE_CHECKSUM_L	5
////////////////////////////////////////UART//////////////////////////////////////////

typedef enum{
	VoiceStop=0,
	NormalVoice,
	VolumeType,


}VoiceTxType;



typedef enum{
	Voice_HEAD=0,
	TVoiceLength,
	Voice_CMD,
	TxAddH,
	TxAddL,
	CheckSum,
	TxEnd,

}McuVoiceTxData;

typedef enum{
	dVoice_HEAD=0,
	dTVoiceLength,
	dVoice_CMD,
	dTxNum,
	dTxAdd1,
	dTxAdd2,
	dCheckSum,
	dTxEnd,
}McuVoiceTxDoubleData;

typedef enum{
	DAC_HEAD_0=0,
	DAC_LENGTH_1,
	DAC_CMD_2,
	DAC_PARAM_3,
	DAC_CHECK_4,
	DAC_END_5,

}McuVoiceDAC;

typedef struct{
	uint8_t Voice_u8Uart2RecData[VOICE_TO_MCU_LENGTH];
    uint8_t u8VoiceDryswitchFlag;     // 烘干状态
	uint8_t u8VoiceSendStauts;  //发送顺序标志位

//	uint8_t xpErrorStates;   // 错误状态
//	uint8_t xpDryTempVal;    // 烘干环境温度
//    uint8_t reserve0;        // 预留
//    uint8_t reserve1;        // 预留
}VoicetoMCUData;

typedef struct{
 uint8_t xpMcuToVoiceBuff[MCU_TO_VOICE_LENGTH];
 uint8_t xpMcuToVoiceDoubleBuff[MCU_TO_VOICE_DOUBLELENGTH];
//	uint8_t xpMcuToVoiceControlBuff[];
	uint8_t u8McuToVoiceDAC[VOICE_DAC_LENGTH];
	uint8_t u8McuToVoiceVolume[VOICE_VOLUME_LENGTH];
	uint8_t u8PowerOnEnableDACFlag;
	uint16_t VoiceAddr;
	uint16_t VoiceAddr2;	
	uint8_t u8VoiceType;
	uint8_t u8NoVoiceFlag;			//静音发送标志位
	uint16_t u16NoVoiceCnt;			//静音计时标志位
	uint32_t u32Open_Voice_Cnt;
	uint32_t u32Close_Voice_Cnt;
	uint32_t u32DelayCheckVoiceCnt;
// uint8_t xpDryStates; // 烘干状态
// uint8_t xpDryMode;   // 烘干挡位
// uint8_t xpClearDryError;// 清除烘干故障
// uint8_t reserve0;	  // 预留
// uint8_t reserve1;	  // 预留
}MCUtoVoiceData;

typedef enum{
		LOW_VOICE= 0,
	HIGH_VOICE=1,
	NO_VOICE,
	HAVE_VOICE
	

}VoiceGradeStatus;


void Updata_SendVoiceUartData(MCUtoVoiceData* MToVoiceD);
void voice_uart_cmd_init(void);
void voice_uart_volume(uint8_t v_volume);
void no_voice_handle(void);
void Updata_SendVoiceDoubleUartData(MCUtoVoiceData* MToVoiceD);
#endif



