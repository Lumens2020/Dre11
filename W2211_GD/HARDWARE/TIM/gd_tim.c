#include "gd_tim.h"
#include "config.h"

uint16_t TimCnt1 = 0;
uint16_t TimCnt2 = 0;
uint16_t TimCnt3 = 0;
uint16_t TimCnt4 = 0;


void gd_tim0_init(void)
{

    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;
			rcu_periph_clock_enable(RCU_TIMER0);	
    timer_deinit(TIMER0);


	
	  timer_initpara.prescaler         = 2;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 2400;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER0,&timer_initpara);
	
    timer_ocintpara.ocpolarity  = TIMER_OC_POLARITY_LOW;
    timer_ocintpara.outputstate = TIMER_CCX_ENABLE;
    timer_channel_output_config(TIMER0, TIMER_CH_1, &timer_ocintpara);

    timer_channel_output_pulse_value_config(TIMER0, TIMER_CH_1, 1000);
    timer_channel_output_mode_config(TIMER0, TIMER_CH_1, TIMER_OC_MODE_PWM1);
    timer_channel_output_shadow_config(TIMER0, TIMER_CH_1, TIMER_OC_SHADOW_DISABLE);
    timer_primary_output_config(TIMER0, ENABLE);
    /* auto-reload preload enable */
//    timer_auto_reload_shadow_enable(TIMER0);	
    timer_auto_reload_shadow_enable(TIMER0);	

}





#if BRUSH_4956_DRIVE_ENABLE==1
void gd_tim1_init(void)		//RGM
{
    /*Configure PA8(TIMER0_CH0) as alternate function*/

    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;
    rcu_periph_clock_enable(RCU_TIMER1);
    rcu_periph_clock_enable(RCU_GPIOA);

    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_0);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_0);
    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_0);	

//    gpio_mode_set(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_2);
//    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_2);
////    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_2);		
//		GPIO_BC(GPIOA)=GPIO_PIN_2;
	
	  timer_initpara.prescaler         = 2;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 2400;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER1,&timer_initpara);
	
    timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER1,TIMER_CH_0,&timer_ocintpara);	
//    timer_channel_output_config(TIMER1,TIMER_CH_2,&timer_ocintpara);	
		
    timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_0,0);
	  timer_channel_output_mode_config(TIMER1,TIMER_CH_0,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1,TIMER_CH_0,TIMER_OC_SHADOW_DISABLE);
		
//    timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_2,0);
//    timer_channel_output_mode_config(TIMER1,TIMER_CH_2,TIMER_OC_MODE_PWM0);		
//    timer_channel_output_shadow_config(TIMER1,TIMER_CH_2,TIMER_OC_SHADOW_DISABLE);		


    timer_auto_reload_shadow_enable(TIMER1);
    timer_enable(TIMER1);
		
}


//Ë«¹ö
void gd_tim14_init(void)			//FGM
{
    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;
    rcu_periph_clock_enable(RCU_TIMER14);
    rcu_periph_clock_enable(RCU_GPIOB);

    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_14);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_14);
    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_14);	

//    gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_15);
//    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_15);
////    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_15);	
//		GPIO_BC(GPIOB) = GPIO_PIN_15; 
		
	  timer_initpara.prescaler         = 2;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 2400;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER14,&timer_initpara);
	
    timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER14,TIMER_CH_0,&timer_ocintpara);	
//    timer_channel_output_config(TIMER14,TIMER_CH_1,&timer_ocintpara);	
		
    timer_channel_output_pulse_value_config(TIMER14,TIMER_CH_0,0);
	  timer_channel_output_mode_config(TIMER14,TIMER_CH_0,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER14,TIMER_CH_0,TIMER_OC_SHADOW_DISABLE);
		
//    timer_channel_output_pulse_value_config(TIMER14,TIMER_CH_1,0);
//    timer_channel_output_mode_config(TIMER14,TIMER_CH_1,TIMER_OC_MODE_PWM0);		
//    timer_channel_output_shadow_config(TIMER14,TIMER_CH_1,TIMER_OC_SHADOW_DISABLE);		
    timer_primary_output_config(TIMER14,ENABLE);
    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER14);
    timer_enable(TIMER14);	



}

#else
//Ë«¹ö
void gd_tim1_init(void)
{
    /*Configure PA8(TIMER0_CH0) as alternate function*/

    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;
    rcu_periph_clock_enable(RCU_TIMER1);
    rcu_periph_clock_enable(RCU_GPIOA);

    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_0);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_0);
    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_0);	

    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_2);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_2);
    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_2);		
	
	  timer_initpara.prescaler         = 2;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 2400;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER1,&timer_initpara);
	
    timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER1,TIMER_CH_0,&timer_ocintpara);	
    timer_channel_output_config(TIMER1,TIMER_CH_2,&timer_ocintpara);	
		
    timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_0,0);
	  timer_channel_output_mode_config(TIMER1,TIMER_CH_0,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1,TIMER_CH_0,TIMER_OC_SHADOW_DISABLE);
		
    timer_channel_output_pulse_value_config(TIMER1,TIMER_CH_2,0);
    timer_channel_output_mode_config(TIMER1,TIMER_CH_2,TIMER_OC_MODE_PWM0);		
    timer_channel_output_shadow_config(TIMER1,TIMER_CH_2,TIMER_OC_SHADOW_DISABLE);		
//    timer_primary_output_config(TIMER1,ENABLE);
    /* auto-reload preload enable */

    timer_auto_reload_shadow_enable(TIMER1);
    timer_enable(TIMER1);
		
}


//Ë«¹ö
void gd_tim14_init(void)
{
    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;
    rcu_periph_clock_enable(RCU_TIMER14);
    rcu_periph_clock_enable(RCU_GPIOB);

    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_14);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_14);
    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_14);	

    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_15);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_15);
    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_15);	

		
	  timer_initpara.prescaler         = 2;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 2400;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER14,&timer_initpara);
	
    timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER14,TIMER_CH_0,&timer_ocintpara);	
    timer_channel_output_config(TIMER14,TIMER_CH_1,&timer_ocintpara);	
		
    timer_channel_output_pulse_value_config(TIMER14,TIMER_CH_0,0);
	  timer_channel_output_mode_config(TIMER14,TIMER_CH_0,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER14,TIMER_CH_0,TIMER_OC_SHADOW_DISABLE);
		
    timer_channel_output_pulse_value_config(TIMER14,TIMER_CH_1,0);
    timer_channel_output_mode_config(TIMER14,TIMER_CH_1,TIMER_OC_MODE_PWM0);		
    timer_channel_output_shadow_config(TIMER14,TIMER_CH_1,TIMER_OC_SHADOW_DISABLE);		
    timer_primary_output_config(TIMER14,ENABLE);
    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER14);
    timer_enable(TIMER14);	



}

#endif

//Ë®±Ã
void gd_tim2_init(void)
{
    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;
    rcu_periph_clock_enable(RCU_TIMER2);
    rcu_periph_clock_enable(RCU_GPIOB);

    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_0);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_0);
    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_0);		

	  timer_initpara.prescaler         = 7199;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 2000;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER2,&timer_initpara);
	
    timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER2,TIMER_CH_2,&timer_ocintpara);	
//    timer_channel_output_config(TIMER2,TIMER_CH_1,&timer_ocintpara);	
		
    timer_channel_output_pulse_value_config(TIMER2,TIMER_CH_2,0);
	  timer_channel_output_mode_config(TIMER2,TIMER_CH_2,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER2,TIMER_CH_2,TIMER_OC_SHADOW_DISABLE);
		
//    timer_channel_output_pulse_value_config(TIMER14,TIMER_CH_1,1000);
//    timer_channel_output_mode_config(TIMER14,TIMER_CH_1,TIMER_OC_MODE_PWM0);		
//    timer_channel_output_shadow_config(TIMER14,TIMER_CH_1,TIMER_OC_SHADOW_DISABLE);		
//    timer_primary_output_config(TIMER14,ENABLE);
    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER2);
    timer_enable(TIMER2);		

}


//·ÖÀëµç»ú
void gd_tim13_init(void)
{
    timer_oc_parameter_struct timer_ocintpara;
    timer_parameter_struct timer_initpara;
    rcu_periph_clock_enable(RCU_TIMER13);
    rcu_periph_clock_enable(RCU_GPIOA);

	  gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_7);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_7);
    gpio_af_set(GPIOA, GPIO_AF_4, GPIO_PIN_7);	

	  timer_initpara.prescaler         = 2;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 2400;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER13,&timer_initpara);
	
    timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER13,TIMER_CH_0,&timer_ocintpara);		
		
    timer_channel_output_pulse_value_config(TIMER13,TIMER_CH_0,0);
	  timer_channel_output_mode_config(TIMER13,TIMER_CH_0,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER13,TIMER_CH_0,TIMER_OC_SHADOW_DISABLE);
		

    timer_auto_reload_shadow_enable(TIMER13);
    timer_enable(TIMER13);		
	
}







void delay_nms(uint16_t time)
{
	uint16_t i=0;
	while(time--)
	{
		i=14500; //
		while(i--);
	}
}






