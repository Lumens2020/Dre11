#include "commvoice.h"
#include "control.h"

VoicetoMCUData VoiceToMCU;
MCUtoVoiceData McuToVoice;

extern VoicePara      Voice;

uint8_t VoiceFlag;

//256вж╫зртоб
void Updata_SendVoiceUartData(MCUtoVoiceData* MToVoiceD)
{

	uint16_t uiTempCheckSum;
	uint8_t  uclenth,i;

	MToVoiceD->xpMcuToVoiceBuff[Voice_HEAD]    = MCU_TO_VOICE_HEAD;
	MToVoiceD->xpMcuToVoiceBuff[TVoiceLength]      = MCU_TO_VOICE_LENGTH_DATA;
	MToVoiceD->xpMcuToVoiceBuff[Voice_CMD]   = FLASH_PLAY_CMD;
	MToVoiceD->xpMcuToVoiceBuff[TxAddH] =0x00;
	if(McuToVoice.VoiceAddr > 0x1D)
	{
		MToVoiceD->xpMcuToVoiceBuff[TxAddL] =McuToVoice.VoiceAddr+(LANGUAGE_BASE_ADDR*Voice.ucLanguageCount);
	}
	else
	{
		MToVoiceD->xpMcuToVoiceBuff[TxAddL] =McuToVoice.VoiceAddr;	
	}


	uclenth = sizeof(MToVoiceD->xpMcuToVoiceBuff)-2;
	uiTempCheckSum = 0;
	for(i=1;i<uclenth;i++)
	{
		uiTempCheckSum += MToVoiceD->xpMcuToVoiceBuff[i];
	}
//	MToVoiceD->xpMcuToVoiceBuff[M_CHECKSUM_H] = (uint8_t)((uiTempCheckSum&0xFF00)>>8);
	MToVoiceD->xpMcuToVoiceBuff[CheckSum] = (uint8_t)(uiTempCheckSum&0x00FF);
	MToVoiceD->xpMcuToVoiceBuff[TxEnd] =MCU_TO_VOICE_END;
}


void Updata_SendVoiceDoubleUartData(MCUtoVoiceData* MToVoiceD)
{

	uint16_t uiTempCheckSum;
	uint8_t  uclenth,i;

	MToVoiceD->xpMcuToVoiceDoubleBuff[dVoice_HEAD]    = MCU_TO_VOICE_DOUBLE_HEAD;
	MToVoiceD->xpMcuToVoiceDoubleBuff[dTVoiceLength]      = MCU_TO_VOICE_DOUBLE_LENGTH_DATA;
	MToVoiceD->xpMcuToVoiceDoubleBuff[dVoice_CMD]   = DOUBLE_FLASH_PLAY_CMD;
	MToVoiceD->xpMcuToVoiceDoubleBuff[dTxNum] =0x02;
	if(McuToVoice.VoiceAddr > 0x1D)
	{
		MToVoiceD->xpMcuToVoiceDoubleBuff[dTxAdd1] =McuToVoice.VoiceAddr+(LANGUAGE_BASE_ADDR*Voice.ucLanguageCount);
	}
	else
	{
		MToVoiceD->xpMcuToVoiceDoubleBuff[dTxAdd1] =McuToVoice.VoiceAddr;	
	}
	
	if(McuToVoice.VoiceAddr > 0x1D)
	{
		MToVoiceD->xpMcuToVoiceDoubleBuff[dTxAdd2] =McuToVoice.VoiceAddr2+(LANGUAGE_BASE_ADDR*Voice.ucLanguageCount);
	}
	else
	{
		MToVoiceD->xpMcuToVoiceDoubleBuff[dTxAdd2] =McuToVoice.VoiceAddr2;	
	}


	uclenth = sizeof(MToVoiceD->xpMcuToVoiceDoubleBuff)-2;
	uiTempCheckSum = 0;
	for(i=1;i<uclenth;i++)
	{
		uiTempCheckSum += MToVoiceD->xpMcuToVoiceDoubleBuff[i];
	}
//	MToVoiceD->xpMcuToVoiceBuff[M_CHECKSUM_H] = (uint8_t)((uiTempCheckSum&0xFF00)>>8);
	MToVoiceD->xpMcuToVoiceDoubleBuff[dCheckSum] = (uint8_t)(uiTempCheckSum&0x00FF);
	MToVoiceD->xpMcuToVoiceDoubleBuff[dTxEnd] =MCU_TO_VOICE_END;
}

void voice_uart_cmd_init(void)
{
	McuToVoice.u8McuToVoiceDAC[DAC_HEAD_0] = MCU_TO_VOICE_HEAD;	
	McuToVoice.u8McuToVoiceDAC[DAC_LENGTH_1] = DAC_LENGTH;	
	McuToVoice.u8McuToVoiceDAC[DAC_CMD_2] = DAC_CMD;		
	McuToVoice.u8McuToVoiceDAC[DAC_PARAM_3] = DAC_PARAM;	
	McuToVoice.u8McuToVoiceDAC[DAC_CHECK_4] = DAC_CHECK;	
	McuToVoice.u8McuToVoiceDAC[DAC_END_5] = DAC_END;	
}

void voice_uart_volume(uint8_t v_volume)
{
	uint16_t uiTempCheckSum;
	uint8_t  uclenth,i;
	McuToVoice.u8McuToVoiceVolume[0] = MCU_TO_VOICE_HEAD;	
	McuToVoice.u8McuToVoiceVolume[1] = VOLUME_LENGTH;	
	McuToVoice.u8McuToVoiceVolume[2] = VOLUME_CMD;		
	McuToVoice.u8McuToVoiceVolume[3] = v_volume;	
//	McuToVoice.u8McuToVoiceVolume[DAC_CHECK_4] = DAC_CHECK;	
	McuToVoice.u8McuToVoiceVolume[5] = DAC_END;		

	uclenth = sizeof(McuToVoice.u8McuToVoiceVolume)-2;
	uiTempCheckSum = 0;
	for(i=1;i<uclenth;i++)
	{
		uiTempCheckSum += McuToVoice.u8McuToVoiceVolume[i];
	}
//	MToVoiceD->xpMcuToVoiceBuff[M_CHECKSUM_H] = (uint8_t)((uiTempCheckSum&0xFF00)>>8);
	McuToVoice.u8McuToVoiceVolume[4] = (uint8_t)(uiTempCheckSum&0x00FF);

}

void no_voice_handle(void)
{
	if(McuToVoice.u8NoVoiceFlag == 1)
	{
		if(McuToVoice.u16NoVoiceCnt<1500)
		{
			McuToVoice.u16NoVoiceCnt++;
		}
		else
		{
			VoiceToMCU.u8VoiceSendStauts = 1; 
			McuToVoice.u16NoVoiceCnt = 0;
			McuToVoice.u8NoVoiceFlag = 0;
		}

	}
	else
	{
		McuToVoice.u16NoVoiceCnt = 0;
	}

}


void voice_reload_enable(void)
{
	if(VOICE_BUSY_LEVEL==1)
	{
		VoiceFlag=1;
	}		
	
	if(VOICE_BUSY_LEVEL==0)
	{	
		if(++McuToVoice.u32Open_Voice_Cnt>(500000/VOICE_TICKS_INTERVAL))// 500ms
		{
			pbVOICE_OPEN;
			McuToVoice.u32Open_Voice_Cnt=0;
		}
	}
	else
	{
			McuToVoice.u32Open_Voice_Cnt=0;
	}
	
	if(McuToVoice.u32DelayCheckVoiceCnt>0&&VOICE_BUSY_LEVEL==0)
	{
		if(++McuToVoice.u32DelayCheckVoiceCnt>(400000/VOICE_TICKS_INTERVAL))// 400ms
		{
				if(VOICE_BUSY_LEVEL==0)
				{
						if(++McuToVoice.u32Close_Voice_Cnt>(300000/VOICE_TICKS_INTERVAL))// 300ms
						{
							pbVOICE_CLOSE;
						}
				}
				else
				{
					McuToVoice.u32Close_Voice_Cnt=0;
				}
				if(McuToVoice.u32DelayCheckVoiceCnt>(1000000/VOICE_TICKS_INTERVAL))// 1000ms
				{
					McuToVoice.u32DelayCheckVoiceCnt=0;
					McuToVoice.u32Close_Voice_Cnt=0;
				}
			}
	}
	else
	{
			McuToVoice.u32Close_Voice_Cnt=0;
			McuToVoice.u32DelayCheckVoiceCnt=0;
	}	
	
	
}



void Updata_ReceVoiceUartData(void)
{
	

}




void Deal_ReceVoiceUartData(void)
{



}








