/*
 * BCM_Recieve.c
 *
 * Created: 04/03/2020 05:10:34 م
 *  Author: mo
 */

#include "pushButtonConfig.h"
#include "pushButton.h"
#include "led.h"
#include "ledConfig.h"
#include "timers.h"
#include "uart.h"
#include "uartconfig.h"
#include "SPI.h"
#include "SPI_Config.h"
volatile uint8_t u8_DATA='R';
volatile uint8_t u8_interrupt_spi=0;
int main(void)
{
	Led_Init(LED_0);
	//uint8_t data_sent='M';
	//uint8_t flag=0;
	gpioPinDirection(GPIOB,BIT3,OUTPUT);
	Uart_Init(Baud9600,OneStopBit,NoParity,EightBits,ASynchronous);
	Enable_communication_interrupt();
//	Led_On(LED_0);
	SPI_Init();
	//SPDR=5;
	//if(u8_interrupt_spi==1){
//}
	while(1)
		{

//				UartTransmitdataInt(u8_DATA);

    }



}
