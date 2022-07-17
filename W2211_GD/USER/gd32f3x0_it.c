/*!
    \file  gd32f3x0_it.c
    \brief interrupt service routines
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-28, V1.0.0, demo for GD32F3x0
*/

#include "gd32f3x0_it.h"
#include "systick.h"
#include "main.h"
#include "gd_exit.h"

extern FCTtoMCUData     FCTtoMData;
extern FCT_UART1Comm    FctUART1COMMpara;
extern MCUtoFCTData     MtoFCTData;

extern UART1Comm    UART1COMMpara;
extern UART2Comm     UART2COMMpara;
extern MCUtoTESTData MtoTESTData;

extern BMStoMCUData BMStoMData;


extern BLDCtoMCUData BLDCtoMData;
extern MCUtoBLDCData MtoBLDCData;
extern MCUtoLCDData MtoLCDData;
extern MCUtoBMSData MtoBMSData;
			 
extern DRYtoMCUData DRYtoMData;	
extern TimePara       TimeVar;

/*!
    \brief      this function handles NMI exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void NMI_Handler(void)
{
}

/*!
    \brief      this function handles HardFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void HardFault_Handler(void)
{
    /* if Hard Fault exception occurs, go to infinite loop */
//    while (1);
	NVIC_SystemReset();
}

/*!
    \brief      this function handles MemManage exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void MemManage_Handler(void)
{
    /* if Memory Manage exception occurs, go to infinite loop */
    while (1);
}

/*!
    \brief      this function handles BusFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void BusFault_Handler(void)
{
    /* if Bus Fault exception occurs, go to infinite loop */
    while (1);
}

/*!
    \brief      this function handles UsageFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void UsageFault_Handler(void)
{
    /* if Usage Fault exception occurs, go to infinite loop */
    while (1);
}

/*!
    \brief      this function handles SVC exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SVC_Handler(void)
{
}

/*!
    \brief      this function handles DebugMon exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DebugMon_Handler(void)
{
}

/*!
    \brief      this function handles PendSV exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PendSV_Handler(void)
{
}

/*!
    \brief      this function handles SysTick exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SysTick_Handler(void)
{

	if(TimCnt1<60000)
	{
		TimCnt1++;
	}
	else
	{
		TimCnt1 = 0;
	}
	
	if(TimCnt2<60000)
	{
		TimCnt2++;
	}	
//	
//	if(TimCnt3<60000)
//	{
//		TimCnt3++;
//	}	

	
 if(++TimeVar.u16_Write_Flash_Count>2000)
 	{
		TimeVar.u8_Write_Flash_2S_Flag=1;
		TimeVar.u16_Write_Flash_Count = 0;
	}		
 TimeVar.bTmr01msFlag=1;
 TimeVar.bTmrSysFlag=1;// 20220227
 if(++TimeVar.bTmr02msCount>1)
 	{
    TimeVar.bTmr02msFlag=1;
		TimeVar.bTmr02msCount=0;
 	}
	
	if(TimeVar.u16VoiceDelayCnt<300)
	{
		TimeVar.u16VoiceDelayCnt++;
		TimeVar.u16VoiceDelay100msFlag = 0;
	}
	else
	{
		TimeVar.u16VoiceDelay100msFlag = 1;
	}
	
	if(++TimeVar.bTmr10msCount>9)
 	{
		if(++TimeVar.bTmr500msCount>100)//50)
 		{
			TimeVar.bTmr500msFlag=1;
			TimeVar.bFLASH500msFlag=1;
			TimeVar.bTmr500msCount=0;
 		}
    TimeVar.bTmr10msFlag=1;
		TimeVar.bTmr10msCount=0;
 	}
	if(++TimeVar.bTmr100msCount>99)//50)
	{
		TimeVar.bTmr100msFlag=1;
		TimeVar.bTmr100msCount=0;
	}
 if(TimeVar.bPowerOn1sCount<2000)
 {
		TimeVar.bPowerOn1sCount++;
		if(TimeVar.bPowerOn1sCount==500)
		{
			TimeVar.bPowerOnmsFlag=1;
		}
 }

	if(TimeVar.u16TimFwdgtTestCnt<60000)
	{
		TimeVar.u16TimFwdgtTestCnt++;
	}
}


void USART0_IRQHandler(void)
{
    if(RESET != usart_interrupt_flag_get(USART0, USART_INT_FLAG_RBNE))
		{
				Deal_ReceDryUartData(&DRYtoMData,&UART2COMMpara);
    }
				usart_interrupt_flag_clear(USART0,USART_INT_FLAG_RBNE);

}


void USART1_IRQHandler(void)
{
    if(RESET != usart_interrupt_flag_get(USART1, USART_INT_FLAG_RBNE))
		{

			  Deal_ReceBMSUartData(&BMStoMData,&BLDCtoMData,&UART1COMMpara,&FCTtoMData,&FctUART1COMMpara);
				Deal_ReceFCTUartData(&FCTtoMData,&FctUART1COMMpara);
//        usart_interrupt_disable(USART0, USART_INT_RBNE);

    }
				usart_interrupt_flag_clear(USART1,USART_INT_FLAG_RBNE);

}


void ADC_CMP_IRQHandler(void)
{
#if  DEBUG_TEST_ENABLE==1
	GPIO_BOP(GPIOB) = GPIO_PIN_3;
#else

#endif
	ADC_Interrupt_Handle();

    if(adc_interrupt_flag_get( ADC_INT_FLAG_EOC)==SET)
   {

        adc_interrupt_flag_clear( ADC_INT_FLAG_EOC);
    }
}

void EXTI2_3_IRQHandler(void)
{
    if(RESET != exti_interrupt_flag_get(EXTI_2))
		{

				Pump_Project();
			  exti_interrupt_flag_clear(EXTI_2);
    }
    
    if(RESET != exti_interrupt_flag_get(EXTI_3))
		{
				Brush_Second_Project();
			
			  exti_interrupt_flag_clear(EXTI_3);
    }
}


void EXTI4_15_IRQHandler(void)
{
    if(RESET != exti_interrupt_flag_get(EXTI_9))
		{
				Brush_First_Project();
			
			  exti_interrupt_flag_clear(EXTI_9);
    }
    

}



