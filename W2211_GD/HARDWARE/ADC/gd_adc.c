
#include "config.h"
#if	W2211_ENABLE
#include "adc.h"
#else
#include "gd_adc.h"
#endif

void gd_adc_gpio_init(void)
{
    rcu_periph_clock_enable(RCU_GPIOA);
		rcu_periph_clock_enable(RCU_GPIOC);
    gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_1);
    gpio_mode_set(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5);

}


void gd_adc_init(void)
{
	  rcu_periph_clock_enable(RCU_ADC);
		rcu_adc_clock_config(RCU_ADCCK_APB2_DIV6);

    adc_channel_length_config(ADC_REGULAR_CHANNEL, 7);

    /* ADC regular channel config */

    adc_regular_channel_config(0, ADC_CHANNEL_1, ADC_SAMPLETIME_41POINT5);     	//RGM_AD
    adc_regular_channel_config(1, ADC_CHANNEL_10, ADC_SAMPLETIME_28POINT5);			//污水箱
    adc_regular_channel_config(2, ADC_CHANNEL_11, ADC_SAMPLETIME_28POINT5);			//充电
    adc_regular_channel_config(3, ADC_CHANNEL_12, ADC_SAMPLETIME_28POINT5);			//KEY
    adc_regular_channel_config(4, ADC_CHANNEL_13, ADC_SAMPLETIME_28POINT5);			//脏污
    adc_regular_channel_config(5, ADC_CHANNEL_14, ADC_SAMPLETIME_41POINT5);			//FGM_AD
	  adc_regular_channel_config(6, ADC_CHANNEL_15, ADC_SAMPLETIME_28POINT5);			//清水AD
    /* ADC external trigger enable */
    adc_external_trigger_config(ADC_REGULAR_CHANNEL, ENABLE);
    /* ADC external trigger source config */
    adc_external_trigger_source_config(ADC_REGULAR_CHANNEL, ADC_EXTTRIG_REGULAR_T0_CH1);
    /* ADC data alignment config */
    adc_data_alignment_config(ADC_DATAALIGN_RIGHT);
    /* enable ADC interface */
	    adc_enable();	
			delay_nms(1);
    /* ADC calibration and reset calibration */
    adc_calibration_enable();
		adc_dma_mode_enable();
    /* ADC SCAN function enable */
    adc_special_function_config(ADC_SCAN_MODE, ENABLE);
//		adc_special_function_config(ADC_CONTINUOUS_MODE, ENABLE);
    /* ADC DMA function enable */
//    adc_dma_mode_enable();
    nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
    nvic_irq_enable(ADC_CMP_IRQn, 0U, 2U);
		
		adc_interrupt_enable(ADC_INT_EOC);
		timer_enable(TIMER0);
}




