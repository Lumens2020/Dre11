#include "gd_gpio.h"
#include "config.h"




void gd_gpio_init(void)
{	
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_GPIOB);
	rcu_periph_clock_enable(RCU_GPIOC);
	rcu_periph_clock_enable(RCU_GPIOF);
	//////////////////////////////gpioa output///////////////////////////////////////////

	gpio_mode_set(PORT_VOICE_EN, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_VOICE_EN);
	gpio_output_options_set(PORT_VOICE_EN, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_VOICE_EN);
	GPIO_BC(PORT_VOICE_EN) = PIN_VOICE_EN;   
	
		gpio_mode_set(PORT_GF_KEY, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_GF_KEY);
	gpio_output_options_set(PORT_GF_KEY, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_GF_KEY);
	GPIO_BC(PORT_GF_KEY) = PIN_GF_KEY;   
	
	//////////////////////////////gpiob output///////////////////////////////////////////	
	
	gpio_mode_set(PORT_FGM_MODE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_FGM_MODE);
	gpio_output_options_set(PORT_FGM_MODE, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_FGM_MODE);
	GPIO_BOP(PORT_FGM_MODE) = PIN_FGM_MODE; 
	
	gpio_mode_set(PORT_RGM_MODE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_RGM_MODE);
	gpio_output_options_set(PORT_RGM_MODE, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_RGM_MODE);
	GPIO_BOP(PORT_RGM_MODE) = PIN_RGM_MODE; 
	
	//////////////////////////////gpioc output///////////////////////////////////////////	

	gpio_mode_set(PORT_CHARGE_SW, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_CHARGE_SW);
	gpio_output_options_set(PORT_CHARGE_SW, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_CHARGE_SW);
	GPIO_BC(PORT_CHARGE_SW) = PIN_CHARGE_SW;   
	
	gpio_mode_set(PORT_ELE_WATER, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_ELE_WATER_PWM1);
	gpio_output_options_set(PORT_ELE_WATER, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_ELE_WATER_PWM1);
	GPIO_BC(PORT_ELE_WATER) = PIN_ELE_WATER_PWM1; 
	
	gpio_mode_set(PORT_ELE_WATER, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_ELE_WATER_PWM2);
	gpio_output_options_set(PORT_ELE_WATER, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_ELE_WATER_PWM2);
	GPIO_BC(PORT_ELE_WATER) = PIN_ELE_WATER_PWM2;  		
	
	//////////////////////////////gpiof output///////////////////////////////////////////	

	gpio_mode_set(PORT_WASTE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_WASTE_IO1);
	gpio_output_options_set(PORT_WASTE, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_WASTE_IO1);
	GPIO_BC(PORT_WASTE) = PIN_WASTE_IO1; 	
	
	gpio_mode_set(PORT_WASTE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_WASTE_IO2);
	gpio_output_options_set(PORT_WASTE, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_WASTE_IO2);
	GPIO_BC(PORT_WASTE) = PIN_WASTE_IO2; 
	
	gpio_mode_set(PORT_P_SW, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_P_SW);
	gpio_output_options_set(PORT_P_SW, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_P_SW);
	GPIO_BC(PORT_P_SW) = PIN_P_SW;   


	gpio_mode_set(PORT_LED_TRANSMIT_IO, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED_TRANSMIT_IO);
	gpio_output_options_set(PORT_LED_TRANSMIT_IO, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_LED_TRANSMIT_IO);
	GPIO_BC(PORT_LED_TRANSMIT_IO) = PIN_LED_TRANSMIT_IO; 	
	//////////////////////////////input///////////////////////////////////////////
	
   gpio_mode_set(PORT_TILT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, PIN_TILT);	
	
   gpio_mode_set(PORT_SPK_IO, GPIO_MODE_INPUT, GPIO_PUPD_NONE, PIN_SPK_IO);			
 
#if BRUSH_4956_DRIVE_ENABLE==1 
    gpio_mode_set(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_2);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_2);
//    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_2);		
//		GPIO_BC(GPIOA)=GPIO_PIN_2; 
    gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_15);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_15);
//    gpio_af_set(GPIOB, GPIO_AF_1, GPIO_PIN_15);	
//		GPIO_BC(GPIOB) = GPIO_PIN_15; 		
 #else
 
 #endif
 
#if	VOICE_BUSY_CHECK_ENABLE ==1
   gpio_mode_set(PORT_VOICE_BUSY_CHECK, GPIO_MODE_INPUT, GPIO_PUPD_NONE, PIN_VOICE_BUSY_CHECK);						
#else
#endif

	pbVOICE_OPEN;
#if  DEBUG_TEST_ENABLE==1

//	gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_3);
//	gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_3);
//	GPIO_BC(GPIOB) = GPIO_PIN_3;   
//	//GPIO_BOP(GPIOB) = GPIO_PIN_3;
//	gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_4);
//	gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_4);
//	GPIO_BC(GPIOB) = GPIO_PIN_4;   

#else

#endif





}




void gd_gpio_test_init(void)
{
	rcu_periph_clock_enable(RCU_GPIOA);	
	gpio_mode_set(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_4);
	gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_4);
	GPIO_BC(GPIOA) = GPIO_PIN_4;  	

}








