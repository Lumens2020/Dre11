#ifndef __GD_GPIO_H__
#define __GD_GPIO_H__

#include "config.h"
#include "gd_config.h"

///////////////output////////////////////


#if BRUSH_4956_DRIVE_ENABLE==1

#define  BRUSH_F_DIRECT_ON						(GPIO_BOP(GPIOB)=GPIO_PIN_15)
#define BRUSH_F_DIRECT_ERR 						(GPIO_BC(GPIOB)=GPIO_PIN_15)

#define  BRUSH_R_DIRECT_ON			(GPIO_BOP(GPIOA)=GPIO_PIN_2)
#define BRUSH_R_DIRECT_ERR 			(GPIO_BC(GPIOA)=GPIO_PIN_2)

#else

#endif


//污水箱
#define PORT_WASTE					GPIOF
#define PIN_WASTE_IO1				GPIO_PIN_0
#define PIN_WASTE_IO2				GPIO_PIN_1



//充电mos
#define PORT_CHARGE_SW			GPIOC
#define PIN_CHARGE_SW				GPIO_PIN_8

//放点mos
#define PORT_P_SW						GPIOF
#define PIN_P_SW						GPIO_PIN_6

//语音使能
#define PORT_VOICE_EN				GPIOA
#define PIN_VOICE_EN				GPIO_PIN_9


#define PORT_LED_TEST				GPIOA
#define PIN_LED_TEST				GPIO_PIN_12


//驱动芯片mode
#define PORT_FGM_MODE			GPIOB
#define PIN_FGM_MODE			GPIO_PIN_10

#define PORT_RGM_MODE   	GPIOB
#define PIN_RGM_MODE			GPIO_PIN_11

//功放开关
#define PORT_GF_KEY      GPIOA
#define PIN_GF_KEY       GPIO_PIN_10


//电解水
#define PORT_ELE_WATER			GPIOC
#define PIN_ELE_WATER_PWM1	GPIO_PIN_10
#define PIN_ELE_WATER_PWM2	GPIO_PIN_11

//脏污传感器
#define PORT_LED_TRANSMIT_IO	GPIOF
#define PIN_LED_TRANSMIT_IO		GPIO_PIN_7

//////////////////input/////////////////////

//语音按键IO
#define	PORT_SPK_IO					GPIOA
#define	PIN_SPK_IO					GPIO_PIN_6

//倾倒
#define PORT_TILT						GPIOF
#define PIN_TILT						GPIO_PIN_4

//#define	PORT_CLEAR_WATER		PIOC
//#define PIN_CLEAR_WATER			GPIO_PIN_9


//语音busy输入MCU
#define PORT_VOICE_BUSY_CHECK		GPIOB
#define PIN_VOICE_BUSY_CHECK		GPIO_PIN_13
#define VOICE_BUSY_LEVEL gpio_input_bit_get(PORT_VOICE_BUSY_CHECK,PIN_VOICE_BUSY_CHECK)




//语音使能
#define pbVOICE_OPEN		 (GPIO_BOP(PORT_VOICE_EN) = PIN_VOICE_EN)
#define pbVOICE_CLOSE	   (GPIO_BC(PORT_VOICE_EN) = PIN_VOICE_EN)
#define pbSpk_VOICE			 gpio_input_bit_get(PORT_VOICE_EN,PIN_VOICE_EN)


//脏污
#define pbLED_Tr_OPEN		 			(GPIO_BOP(PORT_LED_TRANSMIT_IO) = PIN_LED_TRANSMIT_IO)
#define pbLED_Tr_CLOSE	    	(GPIO_BC(PORT_LED_TRANSMIT_IO) = PIN_LED_TRANSMIT_IO)

//倾倒
#define pbTilt_Key		     gpio_input_bit_get(PORT_TILT,PIN_TILT)

//污水箱
#define pbFull_Test1_ON	    (GPIO_BOP(PORT_WASTE) = PIN_WASTE_IO1)
#define pbFull_Test1_OFF     (GPIO_BC(PORT_WASTE) = PIN_WASTE_IO1)

#define pbFull_Test2_ON	    (GPIO_BOP(PORT_WASTE) = PIN_WASTE_IO2)
#define pbFull_Test2_OFF    (GPIO_BC(PORT_WASTE) = PIN_WASTE_IO2)

//电解水
#define pbPWM1	 	         gpio_input_bit_get(PORT_ELE_WATER,PIN_ELE_WATER_PWM1)
#define pbPWM1_ON			 (GPIO_BOP(PORT_ELE_WATER) = PIN_ELE_WATER_PWM1)	
#define pbPWM1_OFF			 (GPIO_BC(PORT_ELE_WATER) = PIN_ELE_WATER_PWM1)

#define pbPWM2	 	         gpio_input_bit_get(PORT_ELE_WATER,PIN_ELE_WATER_PWM2)
#define pbPWM2_ON			 (GPIO_BOP(PORT_ELE_WATER) = PIN_ELE_WATER_PWM2)	
#define pbPWM2_OFF			  (GPIO_BC(PORT_ELE_WATER) = PIN_ELE_WATER_PWM2)

//放电mos
#define pbPsw_ON	        (GPIO_BOP(PORT_P_SW) = PIN_P_SW)	
#define pbPsw_OFF	         (GPIO_BC(PORT_P_SW) = PIN_P_SW)
#define pbPsw	 	         gpio_input_bit_get(PORT_P_SW,PIN_P_SW)

//充电mos
#define pbDCsw_ON	    	 (GPIO_BOP(PORT_CHARGE_SW) = PIN_CHARGE_SW)	
#define pbDCsw_OFF	    	  (GPIO_BC(PORT_CHARGE_SW) = PIN_CHARGE_SW)
#define pbDCsw				  gpio_input_bit_get(PORT_CHARGE_SW,PIN_CHARGE_SW)


/////////////////////////////no use//////////////////

#define pbKey_Spk			gpio_input_bit_get(PORT_SPK_IO,PIN_SPK_IO) 
#define pbWater_Level	gpio_input_bit_get(PORT_CHARGE_SW,PIN_CHARGE_SW) 
#define CHG_PIN					gpio_input_bit_get(PORT_CHARGE_SW,PIN_CHARGE_SW) 

void gd_gpio_test_init(void);
void gd_gpio_init(void);
#endif 

