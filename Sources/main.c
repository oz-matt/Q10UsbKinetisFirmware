/* ###################################################################
**     Filename    : main.c
**     Project     : UsbKinetis24
**     Processor   : MKL02Z32VFK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-28, 10:35, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "KIN_I2C_OE.h"
#include "BitIoLdd1.h"
#include "BSTAT.h"
#include "BitIoLdd2.h"
#include "USBMUX.h"
#include "ExtIntLdd1.h"
#include "SEL0.h"
#include "BitIoLdd3.h"
#include "SEL1.h"
#include "BitIoLdd4.h"
#include "WAIT1.h"
#include "KSDK1.h"
#include "POWER_OFF.h"
#include "ExtIntLdd2.h"
#include "USB_SW_EN.h"
#include "BitIoLdd5.h"
#include "GI2C1.h"
#include "I2C1.h"
#include "SDA1.h"
#include "BitIoLdd6.h"
#include "SCL1.h"
#include "BitIoLdd7.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU3.h"
#include "BLULED.h"
#include "REDGRNLED.h"
#include "KIN_FLOW_IN.h"
#include "BitIoLdd8.h"
#include "KIN_FLOW_OUT.h"
#include "BitIoLdd9.h"
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

bool gotusbselpress = FALSE;

#include "xlib/ledhandler.h"
#include "xlib/ledasync.h"

void printIoStates(void) {
	if (KIN_I2C_OE_GetVal()) Term1_SendStr("Kin I2c High\r\n");
	else Term1_SendStr("Kin I2c Low\r\n");
	if (SEL0_GetVal()) Term1_SendStr("Sel 0 High\r\n");
	else Term1_SendStr("Sel 0 Low\r\n");
	if (SEL1_GetVal()) Term1_SendStr("Sel 1 High\r\n");
	else Term1_SendStr("Sel 1 Low\r\n");
	if (USB_SW_EN_GetVal()) Term1_SendStr("Usb Sw En High\r\n");
	else Term1_SendStr("Usb Sw En Low\r\n");
	if (KIN_FLOW_OUT_GetVal()) Term1_SendStr("Kin flow out High\r\n");
	else Term1_SendStr("Kin flow out Low\r\n");
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
//TI1_Disable();
//TI2_Enable();
  /* Write your code here */
  /* For example: for(;;) { } */
  //allLEDsOff();
  while(1) {
	 
	  //Term1_SendStr("Press any key to begin or continue the test.\r\n");
	  //while (!Term1_KeyPressed());
	  //Inhr1_Init();
	  //REDLED_SetVal();WAIT1_Waitms(1008);
	  //REDPWM_SetDutyUS(2000);
	  //powerUpSuccessLEDflicker();
	  //REDPWM_SetDutyUS(2001);
	  //Term1_SendStr("Press any key to begin or continue the test.\r\n");
	  	  //while (!Term1_KeyPressed());
	  	  //Inhr1_Init();
	  	  //REDLED_ClrVal();
	  	  //powerUpSuccessLEDflicker();
	  	  //REDLED_SetVal();
	  	  //GRNPWM_SetDutyUS(2000);
	  	//Term1_SendStr("Press any key to begin or continue the test.\r\n");
	  		  //while (!Term1_KeyPressed());
	  		  //Inhr1_Init();
	  	  	
	  	  	
	  WAIT1_Waitms(3000);
	  /*REDGRNLED_SetOffsetTicks(NULL,0,1);
	  WAIT1_Waitms(3000);REDGRNLED_SetOffsetTicks(NULL,0,0);
	  WAIT1_Waitms(3000);REDGRNLED_SetOffsetTicks(NULL,0,15);
	  WAIT1_Waitms(3000);REDGRNLED_SetOffsetTicks(NULL,0,150);
	  WAIT1_Waitms(3000);REDGRNLED_SetOffsetTicks(NULL,0,1500);
	  WAIT1_Waitms(3000);REDGRNLED_SetOffsetTicks(NULL,0,15000);
	  WAIT1_Waitms(3000);REDGRNLED_SetOffsetTicks(NULL,0,65535);*/
	  	  		  powerUpSuccessLEDflicker();WAIT1_Waitms(3000);
	  		  //REDLED_ClrVal();
	  	  		powerUpFailureLEDflicker();
	  		  //GRNPWM_SetDutyUS(1999);
  }
	  /*KIN_I2C_OE_SetVal();
	  if(!(GI2C1_SelectSlave(0x69) == ERR_OK)) Term1_SendStr("Couldnt sel slv... \r\n");;
	  Term1_SendStr("Starting bit toggle tests...\r\n");
	  while (!Term1_KeyPressed()) {
		  //GI2C1_RequestBus();
		  //GI2C1_ReleaseBus();
		  byte data1[2], ret1, ret2;
		  data1[0] = 0x11;
		  data1[1] = 0x18;
		  
		  ret1 = GI2C1_WriteBlock(data1, sizeof(data1), GI2C1_SEND_STOP);
		  WAIT1_Waitms(50);
		  
		  byte data2 = 0;
		  
		  ret2 = GI2C1_ReadBlock(&data2, 1, GI2C1_SEND_STOP);
		  
		  WAIT1_Waitms(3008);
		  BLUPWM_SetDutyMS(9);
		  char ntot[50];
		  snprintf(ntot, 50, "%d, ret1:%d, ret2:%d", data2, ret1, ret2);
		  Term1_SendStr("Am1805@mem0x11=");
		  Term1_SendStr(ntot);
		  Term1_SendStr("\r\n");
	  }
	  
	  Inhr1_Init();	  
	  
	  Term1_SendStr("Test completed.\r\n");*/

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
