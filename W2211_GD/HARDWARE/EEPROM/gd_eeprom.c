#include "gd_eeprom.h"
#include "voice.h"
#include "control.h"
#include "commvoice.h"

Eeprom_TypeDef E2prom;

extern WorkError      ErrorVar;
extern VoicePara      Voice;

extern VoicetoMCUData VoiceToMCU;
extern MCUtoVoiceData McuToVoice;
extern TimePara       TimeVar;
void gd_read_eeprom(void)  
{
		uint16_t num=256;
//    uint32_t *ptr = (uint32_t *)ERASE_PAGE_START_ADDR;
//		fmc_state_enum FlashStatus;
		uint16_t *data=&E2prom.uiReadDataFlash[0];
		uint16_t *temp_addr =(uint16_t *)ERASE_PAGE_START_ADDR; 
	
		while(num --)
		{
			*data ++ = *temp_addr ++;
		}		
		
//		__disable_irq();
//		__disable_fault_irq();
		
		if(E2prom.uiReadDataFlash[EE_HEADER]==EEPROM_HEADADD)
		{
			if(E2prom.uiReadDataFlash[EE_VOICEFUN]>0)Voice.ucFunctionValue= E2prom.uiReadDataFlash[EE_VOICEFUN]; 
			else Voice.ucFunctionValue= E2prom.uiReadDataFlash[EE_VOICEFUN]; 
			Voice.ucLanguageCount 		             = E2prom.uiReadDataFlash[EE_LANGUAGE];
			
			E2prom.uiWriteDataFlash[EE_VOICEFUN] 	 = E2prom.uiReadDataFlash[EE_VOICEFUN]; 
			E2prom.uiWriteDataFlash[EE_LANGUAGE] 	 = E2prom.uiReadDataFlash[EE_LANGUAGE];		
			E2prom.uiWriteDataFlash[EE_VOICEFUN]	 = E2prom.uiWriteDataFlash[EE_VOICEFUN]; 
			E2prom.uiWriteDataFlash[EE_LANGUAGE]	 = E2prom.uiWriteDataFlash[EE_LANGUAGE];	
			
#if TEST_AD_ENABLE==1
        E2prom.uiWriteDataFlash[WARN_CNT]	 = E2prom.uiReadDataFlash[WARN_CNT]; 
        E2prom.uiWriteDataFlash[WARN_TYPE0]	 = E2prom.uiReadDataFlash[WARN_TYPE0]; 
        E2prom.uiWriteDataFlash[WARN_AD_WaterPump0]	 = E2prom.uiReadDataFlash[WARN_AD_WaterPump0]; 	
        E2prom.uiWriteDataFlash[WARN_AD_Brush0]	 = E2prom.uiReadDataFlash[WARN_AD_Brush0]; 
        E2prom.uiWriteDataFlash[WARN_AD_Key0]	 = E2prom.uiReadDataFlash[WARN_AD_Key0]; 	
        E2prom.uiWriteDataFlash[WARN_AD_SewageLV0]	 = E2prom.uiReadDataFlash[WARN_AD_SewageLV0]; 
        E2prom.uiWriteDataFlash[WARN_AD_SewageStage0]	 = E2prom.uiReadDataFlash[WARN_AD_SewageStage0]; 	
        E2prom.uiWriteDataFlash[WARN_AD_CHGVol0]	 = E2prom.uiReadDataFlash[WARN_AD_CHGVol0]; 
        E2prom.uiWriteDataFlash[WARN_AD_WaterLV0]	 = E2prom.uiReadDataFlash[WARN_AD_WaterLV0]; 	
        E2prom.uiWriteDataFlash[WARN_TYPE1]	 = E2prom.uiReadDataFlash[WARN_TYPE1]; 
        E2prom.uiWriteDataFlash[WARN_AD_WaterPump1]	 = E2prom.uiReadDataFlash[WARN_AD_WaterPump1]; 	
        E2prom.uiWriteDataFlash[WARN_AD_Brush1]	 = E2prom.uiReadDataFlash[WARN_AD_Brush1]; 
        E2prom.uiWriteDataFlash[WARN_AD_Key1]	 = E2prom.uiReadDataFlash[WARN_AD_Key1]; 	
        E2prom.uiWriteDataFlash[WARN_AD_SewageLV1]	 = E2prom.uiReadDataFlash[WARN_AD_SewageLV1]; 
        E2prom.uiWriteDataFlash[WARN_AD_SewageStage1]	 = E2prom.uiReadDataFlash[WARN_AD_SewageStage1]; 	
        E2prom.uiWriteDataFlash[WARN_AD_CHGVol1]	 = E2prom.uiReadDataFlash[WARN_AD_CHGVol1]; 
        E2prom.uiWriteDataFlash[WARN_AD_WaterLV1]	 = E2prom.uiReadDataFlash[WARN_AD_WaterLV1]; 	
        E2prom.uiWriteDataFlash[WARN_TYPE2]	 = E2prom.uiReadDataFlash[WARN_TYPE2]; 
        E2prom.uiWriteDataFlash[WARN_AD_WaterPump2]	 = E2prom.uiReadDataFlash[WARN_AD_WaterPump2]; 	
        E2prom.uiWriteDataFlash[WARN_AD_Brush2]	 = E2prom.uiReadDataFlash[WARN_AD_Brush2]; 
        E2prom.uiWriteDataFlash[WARN_AD_Key2]	 = E2prom.uiReadDataFlash[WARN_AD_Key2]; 	
        E2prom.uiWriteDataFlash[WARN_AD_SewageLV2]	 = E2prom.uiReadDataFlash[WARN_AD_SewageLV2]; 
        E2prom.uiWriteDataFlash[WARN_AD_SewageStage2]	 = E2prom.uiReadDataFlash[WARN_AD_SewageStage2]; 	
        E2prom.uiWriteDataFlash[WARN_AD_CHGVol2]	 = E2prom.uiReadDataFlash[WARN_AD_CHGVol2]; 
        E2prom.uiWriteDataFlash[WARN_AD_WaterLV2]	 = E2prom.uiReadDataFlash[WARN_AD_WaterLV2]; 	
        E2prom.uiWriteDataFlash[WARN_TYPE3]	 = E2prom.uiReadDataFlash[WARN_TYPE3]; 
        E2prom.uiWriteDataFlash[WARN_AD_WaterPump3]	 = E2prom.uiReadDataFlash[WARN_AD_WaterPump3]; 	
        E2prom.uiWriteDataFlash[WARN_AD_Brush3]	 = E2prom.uiReadDataFlash[WARN_AD_Brush3]; 
        E2prom.uiWriteDataFlash[WARN_AD_Key3]	 = E2prom.uiReadDataFlash[WARN_AD_Key3]; 	
        E2prom.uiWriteDataFlash[WARN_AD_SewageLV3]	 = E2prom.uiReadDataFlash[WARN_AD_SewageLV3]; 
        E2prom.uiWriteDataFlash[WARN_AD_SewageStage3]	 = E2prom.uiReadDataFlash[WARN_AD_SewageStage3]; 	
        E2prom.uiWriteDataFlash[WARN_AD_CHGVol3]	 = E2prom.uiReadDataFlash[WARN_AD_CHGVol3]; 
        E2prom.uiWriteDataFlash[WARN_AD_WaterLV3]	 = E2prom.uiReadDataFlash[WARN_AD_WaterLV3]; 	
        E2prom.uiWriteDataFlash[WARN_TYPE4]	 = E2prom.uiReadDataFlash[WARN_TYPE4]; 
        E2prom.uiWriteDataFlash[WARN_AD_WaterPump4]	 = E2prom.uiReadDataFlash[WARN_AD_WaterPump4]; 	
        E2prom.uiWriteDataFlash[WARN_AD_Brush4]	 = E2prom.uiReadDataFlash[WARN_AD_Brush4]; 
        E2prom.uiWriteDataFlash[WARN_AD_Key4]	 = E2prom.uiReadDataFlash[WARN_AD_Key4]; 	
        E2prom.uiWriteDataFlash[WARN_AD_SewageLV4]	 = E2prom.uiReadDataFlash[WARN_AD_SewageLV4]; 
        E2prom.uiWriteDataFlash[WARN_AD_SewageStage4]	 = E2prom.uiReadDataFlash[WARN_AD_SewageStage4]; 	
        E2prom.uiWriteDataFlash[WARN_AD_CHGVol4]	 = E2prom.uiReadDataFlash[WARN_AD_CHGVol4]; 
        E2prom.uiWriteDataFlash[WARN_AD_WaterLV4]	 = E2prom.uiReadDataFlash[WARN_AD_WaterLV4]; 	
		ErrorVar.xpErrorMemoryCnt=(uint8_t)E2prom.uiWriteDataFlash[WARN_CNT];

//			__enable_irq();
//      __enable_fault_irq();

#else

#endif
		if((Voice.ucFunctionValue==0)||(Voice.ucFunctionValue==2))
			{
						 Voice.u8VoiceGrade = HIGH_VOICE;
						 voice_uart_volume(HIGH_VOICE_ADJUST);
						 VoiceToMCU.u8VoiceSendStauts = 1;		
						 McuToVoice.u8NoVoiceFlag = 0;	
			}
			else if(Voice.ucFunctionValue==1)
			{
						 Voice.u8VoiceGrade = NO_VOICE;
						 voice_uart_volume(NO_VOICE_ADJUST);
						 	McuToVoice.u8NoVoiceFlag = 1;
			}
			else if(Voice.ucFunctionValue==3)
			{
						Voice.u8VoiceGrade = LOW_VOICE;		
						 voice_uart_volume(LOW_VOICE_ADJUST);	
							VoiceToMCU.u8VoiceSendStauts = 1;
						 McuToVoice.u8NoVoiceFlag = 0;
			}
			else
			{
						Voice.u8VoiceGrade = LOW_VOICE;		
					 voice_uart_volume(LOW_VOICE_ADJUST);	
						VoiceToMCU.u8VoiceSendStauts = 1;
						McuToVoice.u8NoVoiceFlag = 0;
			}
	}
	else
	{		
			Voice.u8VoiceGrade = LOW_VOICE;		
		 voice_uart_volume(LOW_VOICE_ADJUST);	
			VoiceToMCU.u8VoiceSendStauts = 1;
			McuToVoice.u8NoVoiceFlag = 0;
	}
	E2prom.bEnableEEpromFlag=1;
	TimeVar.u16_Write_Flash_Count = 0;
		
	
}


void gd_write_eeprom(void)
{
		uint16_t num=256;
//    uint32_t *ptr = (uint32_t *)ERASE_PAGE_START_ADDR;
		fmc_state_enum FlashStatus;
		uint16_t *data=&E2prom.uiWriteDataFlash[0];
		uint32_t temp_addr =ERASE_PAGE_START_ADDR; 
	
    if(E2prom.bEnableEEpromFlag)
    {
//			__disable_irq();
			__disable_fault_irq();
			
//			usart_interrupt_flag_clear(USART0,USART_INT_FLAG_RBNE);
//			usart_interrupt_flag_clear(USART1,USART_INT_FLAG_RBNE);
    	E2prom.bEEpromRunFlag=1;
			/* unlock the flash program/erase controller */
			fmc_unlock();
			/* clear all pending flags */
			fmc_flag_clear(FMC_FLAG_END | FMC_FLAG_WPERR | FMC_FLAG_PGERR);			
			FlashStatus =  fmc_page_erase(ERASE_PAGE_START_ADDR);
			if(FlashStatus != FMC_READY)
			{
				/* lock the main FMC after the operation */
				fmc_lock();				
			}
			
			while(num --)
			{
				FlashStatus = fmc_halfword_program(temp_addr,*data);	//FLASH_ProgramHalfWord(temp_addr,*data);
			if(FlashStatus != FMC_READY)
			{
				/* lock the main FMC after the operation */
				fmc_lock();				
			}
				temp_addr += 2;
				data++;
			}		
			
			fmc_flag_clear(FMC_FLAG_END | FMC_FLAG_WPERR | FMC_FLAG_PGERR);			
			fmc_lock();		
			
//	    __enable_irq();	
			 __enable_fault_irq();
			
			E2prom.bEnableEEpromFlag = 0;		
    	E2prom.bEEpromRunFlag=0;
			
    }	
	
}


