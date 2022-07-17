/*!
    \file  main.c
    \brief GPIO running led
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-28, V1.0.0, demo for GD32F3x0
*/

//#include "gd32f3x0.h"
////#include "gd32f350r_eval.h"
//#include "systick.h"
#include "main.h"

extern KeyPara        KeyVar;
extern VoicePara      Voice;
extern Eeprom_TypeDef E2prom;
extern ADCPara        ADCVar; 
extern TimePara       TimeVar;
extern VoiceList      VoiceListpara;
extern WorkPara       WorkVar;
extern SewagePara     SewageVar;
extern WaterBoxStatus WaterBSta;
extern FCT_UART1Comm  FctUART1COMMpara;
extern RccReadPara RccTestPara;
extern MCUtoBLDCData  MtoBLDCData;
extern MCUtoBMSData   MtoBMSData;

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{ 
	
    gd_system_init();
    while(1)
		{
			
			#if  DEBUG_TEST_ENABLE==1
//				GPIO_BC(GPIOB) = GPIO_PIN_3;
			#else

			#endif
			
			#if  IWDGOnOffENABLE==1	
			fwdgt_reload();
			#endif
			
			Main_Running();
			
			if(TimeVar.bTmr02msFlag)
			{ 
				ControlAndCheck_Load();                    // 负载检测控制处理
				TimeVar.bTmr02msFlag=0;
			}
			if(TimeVar.bTmr10msFlag)
			{
					Deal_UartComm();                          // 串口通讯控制处理	 
				 TimeVar.bTmr10msFlag=0;
			}
		
//		Clock_Recover();

		}
}

void Main_Running(void)
{
	  if(TimeVar.bTmr200usFlag)
	  {
	    Eimination_AdValue(&ADCVar);						// AD采样消抖
			Check_SewageStageAverage(&WaterBSta,&SewageVar,&ADCVar);
			TimeVar.bTmr200usFlag=0;
	  }
		
	  if(TimeVar.bTmr500usFlag)
		{
//		 Check_SewageStage1(&WaterBSta,&SewageVar,&ADCVar);   // 污水箱水位检测
		 TimeVar.bTmr500usFlag=0;
		}

	 if(TimeVar.bTmr01msFlag)
	  {	
		  if(TimeVar.bPowerOnmsFlag)
			{// 上电1S后开始处理			  
				button_ticks();                                      // IO口按键处理
				ADbutton_ticks();                                    // AD按键处理
//				Play_WT588F(&KeyVar,&Voice,&E2prom,&VoiceListpara);  // 语音处理

				Play_VoiceList(&VoiceListpara,&Voice,&KeyVar);
		  }
			Check_SewageLV(&ADCVar,&TimeVar,&SewageVar,&KeyVar);	   // 脏污检测
	  	TimeVar.bTmr01msFlag=0;
		 #if	W2211_ENABLE==1
						 
		 #else			
			no_voice_handle();
			#endif
			
			#if		VOICE_BUSY_CHECK_ENABLE ==1
			voice_reload_enable();
			#else
			#endif
	  }
		
		
		if(TimeVar.bTmr500msFlag)
	  {
			if(TimeVar.bPowerOn1sCount>=1000)
			{
				if(WorkVar.ucChangeStateCnt5==0&&FctUART1COMMpara.bTestModeFlag==0)
				{
		        Play_Service_ERROR();
		        Play_Running_ERROR();
		        Play_SOC_ERROR();
				}
				
			}
	  	TimeVar.bTmr500msFlag=0;
	  }
		
		if(TimeVar.u8_Write_Flash_2S_Flag==1)
		{
			gd_write_eeprom();
			TimeVar.u8_Write_Flash_2S_Flag = 0;
		}
}			
			




