#ifndef __GD_UART_H__
#define __GD_UART_H__

#include "gd_config.h"

//单总线
#define UART0_GPIO_CLK              RCU_GPIOB 
#define UART0_CLK                   RCU_USART0

#define UART0_GPIO_PORT 						GPIOB
#define UART0_GPIO_TX_PIN 					GPIO_PIN_6
#define UART0_GPIO_RX_PIN           GPIO_PIN_7
#define UART0_GPIO_TX_AF						GPIO_AF_0
#define UART0_GPIO_RX_AF						GPIO_AF_0
//#define UART0_GPIO_CLK              RCU_GPIOA 
//#define UART0_CLK                   RCU_USART0

//#define UART0_GPIO_PORT 						GPIOA
//#define UART0_GPIO_TX_PIN 					GPIO_PIN_9
//#define UART0_GPIO_RX_PIN           GPIO_PIN_10
//#define UART0_GPIO_TX_AF						GPIO_AF_1
//#define UART0_GPIO_RX_AF						GPIO_AF_1

//电池包

#define UART1_GPIO_CLK              RCU_GPIOA
#define UART1_CLK                   RCU_USART1

#define UART1_GPIO_PORT 						GPIOA
#define UART1_GPIO_TX_PIN 					GPIO_PIN_8
#define UART1_GPIO_RX_PIN           GPIO_PIN_15
#define UART1_GPIO_TX_AF						GPIO_AF_4
#define UART1_GPIO_RX_AF						GPIO_AF_1



#define	UART_TX_30MS						3						//unit:10ms		5 means 50ms
#define	UART_TX_50MS						5						//unit:10ms		5 means 50ms
#define	UART_TX_100MS						10					//unit:10ms		105 means 100ms
#define UART_TX_1S 							100
#define UART_TX_2S 							200
#define UART_TX_5S              500



typedef enum{
	HEAD=0,
	ID,
	LENTH,
	TxDATA1,
	TxDATA2,
	TxDATA3,
	TxDATA4,
	TxDATA5,
	TxDATA6,
	TxDATA7,
	TxDATA8,
	TxDATA9,
	TxDATA10,
	TxDATA11,
	TxDATA12,
	TxDATA13,
	TxDATA14,
	TxDATA15,
	TxDATA16,
	TxDATA17,
	TxDATA18,
	TxDATA19,
	TxDATA20,
	TxDATA21,//
	TxDATA22,//
	TxDATA23,
	TxDATA24,
	TxDATA25,
	TxDATA26,//
	TxDATA27,//
	TxDATA28,
	TxDATA29,
	TxDATA30
}TxDataSeq;

typedef enum{
	RxDATA1=3,
	RxDATA2,
	RxDATA3,
	RxDATA4,
	RxDATA5,
	RxDATA6,
	RxDATA7,
	RxDATA8,
	RxDATA9,
	RxDATA10,
	RxDATA11,
	RxDATA12,
	RxDATA13,
	RxDATA14,
	RxDATA15,
	RxDATA16,
	RxDATA17,
	RxDATA18,
	RxDATA19,
	RxDATA20,
	RxDATA21
}RxDataSeq;











void gd_uart0_init(uint32_t baudrate);
void gd_uart1_init(uint32_t baudrate);
void gd_uart0_init_test(void );
#endif
