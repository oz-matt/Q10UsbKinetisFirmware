/* ###################################################################
**     Filename    : Events.h
**     Project     : UsbKinetis24
**     Processor   : MKL02Z32VFK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-28, 10:35, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
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

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL02Z32FM4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


void POWER_OFF_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  POWER_OFF_OnInterrupt (module Events)
**
**     Component   :  POWER_OFF [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void USBMUX_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  USBMUX_OnInterrupt (module Events)
**
**     Component   :  USBMUX [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void);

/*
** ===================================================================
**     Event       :  TI2_OnInterrupt (module Events)
**
**     Component   :  TI2 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI2_OnInterrupt(void);

/*
** ===================================================================
**     Event       :  REDGRNLED_OnChannel0 (module Events)
**
**     Component   :  REDGRNLED [TimerUnit_LDD]
*/
/*!
**     @brief
**         Called if compare register match the counter registers or
**         capture register has a new content. OnChannel0 event and
**         Timer unit must be enabled. See [SetEventMask] and
**         [GetEventMask] methods. This event is available only if a
**         [Interrupt] is enabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
*/
/* ===================================================================*/
void REDGRNLED_OnChannel0(LDD_TUserData *UserDataPtr);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
