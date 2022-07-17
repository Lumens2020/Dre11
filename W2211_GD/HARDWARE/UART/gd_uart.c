#include "gd_uart.h"


void gd_uart0_init(uint32_t baudrate)
{
    nvic_irq_enable(USART0_IRQn, 0, 2);

    rcu_periph_clock_enable(UART0_GPIO_CLK);
    rcu_periph_clock_enable (UART0_CLK);  

    gpio_af_set(UART0_GPIO_PORT,UART0_GPIO_TX_AF,UART0_GPIO_TX_PIN);
    gpio_af_set(UART0_GPIO_PORT,UART0_GPIO_RX_AF,UART0_GPIO_RX_PIN);

    gpio_mode_set(UART0_GPIO_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, UART0_GPIO_TX_PIN);
    gpio_output_options_set(UART0_GPIO_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, UART0_GPIO_TX_PIN);

    gpio_mode_set(UART0_GPIO_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, UART0_GPIO_RX_PIN);
    gpio_output_options_set(UART0_GPIO_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, UART0_GPIO_RX_PIN);

    usart_deinit(USART0);
    usart_baudrate_set(USART0, baudrate);
    usart_receive_config(USART0, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);

    usart_enable(USART0);

    usart_interrupt_enable(USART0, USART_INT_RBNE);    

}


void gd_uart1_init(uint32_t baudrate)
{
    nvic_irq_enable(USART1_IRQn, 0, 3);

    rcu_periph_clock_enable(UART1_GPIO_CLK);
    rcu_periph_clock_enable (UART1_CLK);  

    gpio_af_set(UART1_GPIO_PORT,UART1_GPIO_TX_AF,UART1_GPIO_TX_PIN);
    gpio_af_set(UART1_GPIO_PORT,UART1_GPIO_RX_AF,UART1_GPIO_RX_PIN);

    gpio_mode_set(UART1_GPIO_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, UART1_GPIO_TX_PIN);
    gpio_output_options_set(UART1_GPIO_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, UART1_GPIO_TX_PIN);

    gpio_mode_set(UART1_GPIO_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, UART1_GPIO_RX_PIN);
    gpio_output_options_set(UART1_GPIO_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, UART1_GPIO_RX_PIN);

    usart_deinit(USART1);
    usart_baudrate_set(USART1, baudrate);
    usart_receive_config(USART1, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART1, USART_TRANSMIT_ENABLE);

    usart_enable(USART1);

    usart_interrupt_enable(USART1, USART_INT_RBNE);    

}




void gd_uart0_init_test(void)
{
    nvic_irq_enable(USART0_IRQn, 0, 3);

    rcu_periph_clock_enable(UART0_GPIO_CLK);
    rcu_periph_clock_enable (UART0_CLK);  

    gpio_af_set(UART0_GPIO_PORT,UART0_GPIO_TX_AF,UART0_GPIO_TX_PIN);
    gpio_af_set(UART0_GPIO_PORT,UART0_GPIO_RX_AF,UART0_GPIO_RX_PIN);

    gpio_mode_set(UART0_GPIO_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, UART0_GPIO_TX_PIN);
    gpio_output_options_set(UART0_GPIO_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, UART0_GPIO_TX_PIN);

    gpio_mode_set(UART0_GPIO_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, UART0_GPIO_RX_PIN);
    gpio_output_options_set(UART0_GPIO_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, UART0_GPIO_RX_PIN);

    usart_deinit(USART0);
    usart_baudrate_set(USART0, 9600);
    usart_receive_config(USART0, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);

    usart_enable(USART0);
   

}


