﻿/*
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

int main(void)
{
	Led_Init(LED_0);
	uint8_t data_sent='M';
	uint8_t flag=0;
	gpioPinDirection(GPIOB,BIT3,OUTPUT);
	timer2Init(T2_NORMAL_MODE,T2_OC2_DIS,T2_PRESCALER_NO,0,0,0,T2_POLLING);
	Uart_Init(Baud9600,OneStopBit,NoParity,EightBits,ASynchronous);
	Enable_communication_interrupt();
	SPI_Init();
	Led_On(LED_0);
	Uart_tryansmitfirstbyte(data_sent);
	while(1)
		{

				UartTransmitdataInt(gU8_Data_Recieved);

    }



}