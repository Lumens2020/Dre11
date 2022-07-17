#include "gd_exit.h"
#include "control.h"
#include "separate.h"

extern BrushPara      BrushVar;
extern SEPARATE SEPAR;
extern PumpPara       PumpVar;


void gd_exit_init(void)
{
    rcu_periph_clock_enable(RCU_GPIOA);
	  rcu_periph_clock_enable(RCU_GPIOB);
	  rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_CFGCMP);


   gpio_mode_set(PORT_FGM_EXIT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, PIN_FGM_EXIT);	
   gpio_mode_set(PORT_PM_EXIT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, PIN_PM_EXIT);			
	
   gpio_mode_set(PORT_RGM_EXIT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, PIN_RGM_EXIT);		 
//   gpio_mode_set(PORT_SM_EXIT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, PIN_SM_EXIT);			
	
    /* configure button pin as input */
    gpio_mode_set(GPIOB, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO_PIN_2);
    gpio_mode_set(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO_PIN_3);
    gpio_mode_set(GPIOC, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO_PIN_9);
//    gpio_mode_set(GPIOC, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO_PIN_15);
    /* enable and set key temper EXTI interrupt to the lower priority */
    nvic_irq_enable(EXTI2_3_IRQn, 0U, 1U);
    nvic_irq_enable(EXTI4_15_IRQn, 0U, 1U);
    /* connect key temper EXTI line to key GPIO pin */
    syscfg_exti_line_config(EXTI_SOURCE_GPIOB, EXTI_SOURCE_PIN2);
    syscfg_exti_line_config(EXTI_SOURCE_GPIOA, EXTI_SOURCE_PIN3);
	  syscfg_exti_line_config(EXTI_SOURCE_GPIOC, EXTI_SOURCE_PIN9);
//	  syscfg_exti_line_config(EXTI_SOURCE_GPIOC, EXTI_SOURCE_PIN15);
    /* configure key temper EXTI line */
    exti_init(EXTI_2, EXTI_INTERRUPT, EXTI_TRIG_RISING);
	  exti_init(EXTI_3, EXTI_INTERRUPT, EXTI_TRIG_FALLING);
		exti_init(EXTI_9, EXTI_INTERRUPT, EXTI_TRIG_FALLING);
//		exti_init(EXTI_2, EXTI_INTERRUPT, EXTI_TRIG_RISING);
    exti_interrupt_flag_clear(EXTI_2);
    exti_interrupt_flag_clear(EXTI_3);		
    exti_interrupt_flag_clear(EXTI_9);
//		exti_interrupt_flag_clear(EXTI_15);
}







//FGM
void Brush_First_Project(void)
{
		BRUSH_FPWM1 = 0;
	#if BRUSH_4956_DRIVE_ENABLE==1
	#else
		BRUSH_FPWM2 = 0;
	#endif
		rcu_periph_clock_enable(RCU_GPIOB);
    gpio_af_set(GPIOB, GPIO_AF_6, GPIO_PIN_14);		
	  gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_14);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_14);
		GPIO_BC(GPIOB) = GPIO_PIN_14; 
	
	#if DEBUG_TEST_ENABLE==1
	if(BrushVar.u16EXITBrushFCnt<60000)
	{
		BrushVar.u16EXITBrushFCnt++;
	}
	#else
	
	#endif
		BrushVar.ulBrushshortperiod=0;
		BrushVar.bBrushResetFlag=1;

}

void Brush_First_Recover(void)
{
	   rcu_periph_clock_enable(RCU_GPIOB);
    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_14);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_14);
    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_14);	
//	gd_tim14_init();
//    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_15);
//    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_15);
//    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_15);	
}

//RGM
void Brush_Second_Project(void)
{
		BRUSH_RPWM1 = 0;
	#if BRUSH_4956_DRIVE_ENABLE==1
		#else
		BRUSH_RPWM2 = 0;
	#endif
	   rcu_periph_clock_enable(RCU_GPIOA);
    gpio_af_set(GPIOA, GPIO_AF_6, GPIO_PIN_0);		
	  gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_0);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_0);
		GPIO_BC(GPIOA) = GPIO_PIN_0; 
	
	
	
	#if DEBUG_TEST_ENABLE==1
	if(BrushVar.u16EXITBrushRCnt<60000)
	{
		BrushVar.u16EXITBrushRCnt++;
	}
	#else
	
	#endif
		BrushVar.ulBrushshortperiod=0;
		BrushVar.bBrushResetFlag=1;
		
}

void Brush_Second_Recover(void)
{
		rcu_periph_clock_enable(RCU_GPIOA);
	  gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_0);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_0);
    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_0);	
//	gd_tim1_init();
//    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_2);
//    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_2);
//    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_2);		

}

void Pump_Project(void)
{
//		WaterPump_PWM = 0;
//    gpio_af_set(GPIOB, GPIO_AF_6, GPIO_PIN_0);		
//	  gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_0);
//    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_0);
//		GPIO_BC(GPIOB) = GPIO_PIN_0; 	
//		PumpVar.bPumpResetFlag=1;
	
			WaterPump_PWM = 0;	
	    GPIO_AFSEL0(GPIOB)&=0xFFFFFFF0;
				GPIO_AFSEL0(GPIOB)|=0x00000006;
			GPIO_CTL(GPIOB)&=0xFFFFFFFD;
			GPIO_OMODE(GPIOB) &= 0xFFFFFFFE;
			GPIO_BC(GPIOB) = GPIO_PIN_0;
			PumpVar.bPumpResetFlag=1;
}

void Pump_Recover(void)
{
    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_0);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_0);
    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_0);		 

}

void Separate_Project(void)
{
		SEPAR_PWM = 0;
    gpio_af_set(GPIOA, GPIO_AF_6, GPIO_PIN_7);		
	  gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_7);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_7);
		GPIO_BC(GPIOA) = GPIO_PIN_7; 	
	SEPAR.bSeparResetFlag =1;
}

void Separate_Recover(void)
{
	  gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_7);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_7);
    gpio_af_set(GPIOA, GPIO_AF_4, GPIO_PIN_7);	
}









