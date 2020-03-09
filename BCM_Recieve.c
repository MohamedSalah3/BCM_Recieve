/*
 * BCM_Recieve.c
 *
 * Created: 04/03/2020 05:13:17 م
 *  Author: mo
 */
#include "BCM_Recieve.h"

ERROR_STATUS BCM_Init (const BCM_ConfigType * ConfigPtr )
{
  uint8_t ret=E_OK;
if(ConfigPtr == NULL){ret=NULL_PTR+BCM_MODULE;}
else{
/*Intialize SPI..*/
switch (ConfigPtr->u8_channel_Protcol) {
  case SPI:
  u8_Is_Intialized++;
	SPI_Init();
  Enable_communication_interrupt();
  break;
  case UART:
u8_Is_Intialized++;
  Uart_Init(Baud9600,OneStopBit,NoParity,EightBits,ASynchronous);
	Enable_communication_interrupt();
  break;
  case UARTANDSPI:
  u8_Is_Intialized++;
  SPI_Init();
  Uart_Init(Baud9600,OneStopBit,NoParity,EightBits,ASynchronous);
	Enable_communication_interrupt();
  break;
  case I2C:
  ret=INVALID_PARM+BCM_MODULE;
  break;
  default:
  ret=INVALID_PARM+BCM_MODULE;
  break;

}
}
u8_frameID=ConfigPtr -> u8_BCM_ID;
return ret;
}
ERROR_STATUS BCM_DeInit (const BCM_ConfigType * ConfigPtr)
{
uint8_t ret=E_OK;
    if(u8_Is_Intialized==1)
      {
      switch (ConfigPtr->u8_channel_Protcol)
        {
          case SPI:
            u8_Is_Intialized--;
	           SPI_De_Init();
          break;
          case UART:
            u8_Is_Intialized--;
             Uart_De_Init();
          break;
          case UARTANDSPI:
            u8_Is_Intialized--;
            SPI_De_Init();
            Uart_De_Init();
          break;
          case I2C:
            ret=INVALID_PARM+BCM_MODULE;
          break;
        }
    }else if(u8_Is_Intialized > 1)
      {
        ret=MULTIPLE_INIT+BCM_MODULE;
      }else
      {
        ret = NOT_INIT+BCM_MODULE;
      }
return ret;
}
