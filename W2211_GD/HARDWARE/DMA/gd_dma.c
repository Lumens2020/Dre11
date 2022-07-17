#include "gd_dma.h"
#include "control.h"
#include "commdry.h"
#include "commbms.h"
#include "commvoice.h"
#include "commfct.h"
#include "commtest.h"

extern MCUtoBMSData   MtoBMSData;
extern MCUtoDRYData MtoDRYData;
//extern VoicetoMCUData VoiceToMCU;
extern MCUtoVoiceData McuToVoice;
extern MCUtoFCTData     MtoFCTData;
extern MCUtoTESTData MtoTESTData;

uint16_t adc_value[7];




void dma_ch3_usart1_bms_config(void)
{
    dma_parameter_struct dma_init_struct;
    /* enable the DMA clock */
    rcu_periph_clock_enable(RCU_DMA);
    /* configure the USART TX DMA channel */
    dma_deinit(DMA_CH3);
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_addr = (uint32_t)MtoBMSData.xpMcuToBmsBuff;
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;
    dma_init_struct.number = 29;
    dma_init_struct.periph_addr = USART1_TDATA_ADDRESS;
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA_CH3, dma_init_struct);
    dma_circulation_disable(DMA_CH3);
    dma_memory_to_memory_disable(DMA_CH3);
		dma_channel_enable(DMA_CH3);
		usart_dma_transmit_config(USART1, USART_DENT_ENABLE);			

}


void dma_ch3_usart1_fct_config(void)
{
    dma_parameter_struct dma_init_struct;
    /* enable the DMA clock */
    rcu_periph_clock_enable(RCU_DMA);
    /* configure the USART TX DMA channel */
    dma_deinit(DMA_CH3);
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_addr = (uint32_t)MtoFCTData.xpMcuToFCTBuff;
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;
    dma_init_struct.number = 35;
    dma_init_struct.periph_addr = USART1_TDATA_ADDRESS;
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA_CH3, dma_init_struct);
    dma_circulation_disable(DMA_CH3);
    dma_memory_to_memory_disable(DMA_CH3);
		dma_channel_enable(DMA_CH3);
		usart_dma_transmit_config(USART1, USART_DENT_ENABLE);			

}


void dma_config(dma_channel_enum DMA_CHx,uint32_t peraddr,uint32_t base_addr,uint16_t buffersize,uint32_t USARTx)
{
    dma_parameter_struct dma_init_struct;
		rcu_periph_clock_enable(RCU_DMA);
		dma_deinit(DMA_CHx);
		dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;
		dma_init_struct.memory_addr = base_addr;
		dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
		dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;
		dma_init_struct.number = buffersize;
//		dma_init_struct.periph_addr = USART0_TDATA_ADDRESS;
		dma_init_struct.periph_addr = peraddr;
		dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
		dma_init_struct.memory_width = DMA_PERIPHERAL_WIDTH_8BIT;
		dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
		dma_init(DMA_CHx,dma_init_struct);
		dma_circulation_disable(DMA_CHx);
		dma_memory_to_memory_disable(DMA_CHx);
		dma_channel_enable(DMA_CHx);
		usart_dma_transmit_config(USARTx, USART_DENT_ENABLE);			

}

void dma_adc_config(void)
{
    dma_parameter_struct dma_data_parameter;
    rcu_periph_clock_enable(RCU_DMA);
    /* ADC DMA_channel configuration */
    dma_deinit(DMA_CH0);

    /* initialize DMA single data mode */
    dma_data_parameter.periph_addr  = (uint32_t)(&ADC_RDATA);
    dma_data_parameter.periph_inc   = DMA_PERIPH_INCREASE_DISABLE;
    dma_data_parameter.memory_addr  = (uint32_t)(&adc_value);
    dma_data_parameter.memory_inc   = DMA_MEMORY_INCREASE_ENABLE;
    dma_data_parameter.periph_width = DMA_PERIPHERAL_WIDTH_16BIT;
    dma_data_parameter.memory_width = DMA_MEMORY_WIDTH_16BIT;
    dma_data_parameter.direction    = DMA_PERIPHERAL_TO_MEMORY;
    dma_data_parameter.number       = 7U;
    dma_data_parameter.priority     = DMA_PRIORITY_HIGH;
    dma_init(DMA_CH0, dma_data_parameter);

    dma_circulation_enable(DMA_CH0);

    /* enable DMA channel */
    dma_channel_enable(DMA_CH0);	

}



void dma_ch1_usart0_dry_config(void)
{
    dma_parameter_struct dma_init_struct;
    /* enable the DMA clock */
    rcu_periph_clock_enable(RCU_DMA);
    /* configure the USART TX DMA channel */
    dma_deinit(DMA_CH1);
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_addr = (uint32_t)MtoDRYData.xpMcuToDRYBuff;
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;
    dma_init_struct.number = 10;
    dma_init_struct.periph_addr = USART0_TDATA_ADDRESS;
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA_CH1, dma_init_struct);
    dma_circulation_disable(DMA_CH1);
    dma_memory_to_memory_disable(DMA_CH1);
		dma_channel_enable(DMA_CH1);
		usart_dma_transmit_config(USART0, USART_DENT_ENABLE);			

}

void dma_ch1_usart0_check_config(void)
{
    dma_parameter_struct dma_init_struct;
    /* enable the DMA clock */
    rcu_periph_clock_enable(RCU_DMA);
    /* configure the USART TX DMA channel */
    dma_deinit(DMA_CH1);
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_addr = (uint32_t)MtoTESTData.xpMcuToTestBuff;
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;
    dma_init_struct.number = 35;
    dma_init_struct.periph_addr = USART0_TDATA_ADDRESS;
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA_CH1, dma_init_struct);
    dma_circulation_disable(DMA_CH1);
    dma_memory_to_memory_disable(DMA_CH1);
		dma_channel_enable(DMA_CH1);
		usart_dma_transmit_config(USART0, USART_DENT_ENABLE);			

}

void dma_ch1_usart0_voice_config(void)
{
    dma_parameter_struct dma_init_struct;
    /* enable the DMA clock */
    rcu_periph_clock_enable(RCU_DMA);
    /* configure the USART TX DMA channel */
    dma_deinit(DMA_CH1);
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_addr = (uint32_t)McuToVoice.xpMcuToVoiceBuff;
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;
    dma_init_struct.number = 7;
    dma_init_struct.periph_addr = USART0_TDATA_ADDRESS;
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA_CH1, dma_init_struct);
    dma_circulation_disable(DMA_CH1);
    dma_memory_to_memory_disable(DMA_CH1);
		dma_channel_enable(DMA_CH1);
		usart_dma_transmit_config(USART0, USART_DENT_ENABLE);			

}

void dma_ch1_usart0_voice_double_config(void)
{
    dma_parameter_struct dma_init_struct;
    /* enable the DMA clock */
    rcu_periph_clock_enable(RCU_DMA);
    /* configure the USART TX DMA channel */
    dma_deinit(DMA_CH1);
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_addr = (uint32_t)McuToVoice.xpMcuToVoiceDoubleBuff;
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;
    dma_init_struct.number = 8;
    dma_init_struct.periph_addr = USART0_TDATA_ADDRESS;
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA_CH1, dma_init_struct);
    dma_circulation_disable(DMA_CH1);
    dma_memory_to_memory_disable(DMA_CH1);
		dma_channel_enable(DMA_CH1);
		usart_dma_transmit_config(USART0, USART_DENT_ENABLE);			

}




void dma_ch1_usart0_voice_dac_config(void)
{
    dma_parameter_struct dma_init_struct;
    /* enable the DMA clock */
    rcu_periph_clock_enable(RCU_DMA);
    /* configure the USART TX DMA channel */
    dma_deinit(DMA_CH1);
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_addr = (uint32_t)McuToVoice.u8McuToVoiceDAC;
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;
    dma_init_struct.number = 6;
    dma_init_struct.periph_addr = USART0_TDATA_ADDRESS;
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA_CH1, dma_init_struct);
    dma_circulation_disable(DMA_CH1);
    dma_memory_to_memory_disable(DMA_CH1);
		dma_channel_enable(DMA_CH1);
		usart_dma_transmit_config(USART0, USART_DENT_ENABLE);			

}



void dma_ch1_usart0_config(uint32_t addr,uint32_t number_num)
{
    dma_parameter_struct dma_init_struct;
    /* enable the DMA clock */
    rcu_periph_clock_enable(RCU_DMA);
    /* configure the USART TX DMA channel */
    dma_deinit(DMA_CH1);
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_addr = (uint32_t)addr;
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;
    dma_init_struct.number = number_num;
    dma_init_struct.periph_addr = USART0_TDATA_ADDRESS;
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA_CH1, dma_init_struct);
    dma_circulation_disable(DMA_CH1);
    dma_memory_to_memory_disable(DMA_CH1);
		dma_channel_enable(DMA_CH1);
		usart_dma_transmit_config(USART0, USART_DENT_ENABLE);			

}



