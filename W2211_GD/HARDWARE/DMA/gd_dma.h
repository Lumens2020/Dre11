#ifndef __GD_DMA_H__
#define __GD_DMA_H__
#include "gd_config.h"
//#include "main.h"
extern uint16_t adc_value[7];

#define USART0_TDATA_ADDRESS      ((uint32_t)0x40013828)
#define USART1_TDATA_ADDRESS 			((uint32_t)0x40004428)

void dma_adc_config(void);
void dma_config(dma_channel_enum DMA_CHx,uint32_t peraddr,uint32_t base_addr,uint16_t buffersize,uint32_t USARTx);
void dma_ch1_usart0_dry_config(void);
void dma_ch3_usart1_bms_config(void);
void dma_ch1_usart0_voice_config(void);
void dma_ch1_usart0_config(uint32_t addr,uint32_t number_num);
void dma_ch3_usart1_fct_config(void);
void dma_ch1_usart0_check_config(void);
void dma_ch1_usart0_voice_double_config(void);
#define COUNTOF(a)   (sizeof(a) / sizeof(*(a)))
#define BUFFER_SIZE_USART0  (COUNTOF(c))
//#define 
#endif


