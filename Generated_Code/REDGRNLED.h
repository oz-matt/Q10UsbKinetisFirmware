/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : REDGRNLED.h
**     Project     : UsbKinetis24
**     Processor   : MKL02Z32VFK4
**     Component   : TimerUnit_LDD
**     Version     : Component 01.164, Driver 01.11, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-07-24, 21:12, # CodeGen: 76
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : REDGRNLED
**          Module name                                    : TPM0
**          Counter                                        : TPM0_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : Optimal
**          Input clock source                             : Internal
**            Counter frequency                            : 2.62144 MHz
**          Counter restart                                : On-match
**            Period device                                : TPM0_MOD
**            Period                                       : 6 ms
**            Interrupt                                    : Disabled
**          Channel list                                   : 2
**            Channel 0                                    : 
**              Mode                                       : Compare
**                Compare                                  : TPM0_C1V
**                Offset                                   : 0 timer-ticks
**                Output on compare                        : Clear
**                  Output on overrun                      : Set
**                  Initial state                          : High
**                  Output pin                             : PTA5/TPM0_CH1/SPI0_SS_b
**                  Output pin signal                      : 
**                Interrupt                                : Enabled
**                  Interrupt                              : INT_TPM0
**                  Interrupt priority                     : medium priority
**            Channel 1                                    : 
**              Mode                                       : Compare
**                Compare                                  : TPM0_C0V
**                Offset                                   : 0 timer-ticks
**                Output on compare                        : Clear
**                  Output on overrun                      : Set
**                  Initial state                          : High
**                  Output pin                             : PTA6/TPM0_CH0/SPI0_MISO
**                  Output pin signal                      : 
**                Interrupt                                : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnCounterRestart                           : Disabled
**              OnChannel0                                 : Enabled
**              OnChannel1                                 : Disabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init           - LDD_TDeviceData* REDGRNLED_Init(LDD_TUserData *UserDataPtr);
**         SetOffsetTicks - LDD_TError REDGRNLED_SetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file REDGRNLED.h
** @version 01.11
** @brief
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
*/         
/*!
**  @addtogroup REDGRNLED_module REDGRNLED module documentation
**  @{
*/         

#ifndef __REDGRNLED_H
#define __REDGRNLED_H

/* MODULE REDGRNLED. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "TPM_PDD.h"
#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


#ifndef __BWUserType_REDGRNLED_TValueType
#define __BWUserType_REDGRNLED_TValueType
  typedef uint32_t REDGRNLED_TValueType ; /* Type for data parameters of methods */
#endif
#define REDGRNLED_CNT_INP_FREQ_U_0 0x00280000UL /* Counter input frequency in Hz */
#define REDGRNLED_CNT_INP_FREQ_R_0 2621438.120953155F /* Counter input frequency in Hz */
#define REDGRNLED_CNT_INP_FREQ_COUNT 0U /* Count of predefined counter input frequencies */
#define REDGRNLED_PERIOD_TICKS 0x3D71UL /* Initialization value of period in 'counter ticks' */
#define REDGRNLED_NUMBER_OF_CHANNELS 0x02U /* Count of predefined channels */
#define REDGRNLED_COUNTER_WIDTH 0x10U  /* Counter width in bits  */
#define REDGRNLED_COUNTER_DIR DIR_UP   /* Direction of counting */
#define REDGRNLED_OFFSET_0_TICKS 0x00ul /* Initialization value of offset as 'counter ticks' for channel 0 */
#define REDGRNLED_OFFSET_1_TICKS 0x00ul /* Initialization value of offset as 'counter ticks' for channel 1 */
/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define REDGRNLED_PRPH_BASE_ADDRESS  0x40038000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define REDGRNLED_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_REDGRNLED_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define REDGRNLED_Init_METHOD_ENABLED  /*!< Init method of the component REDGRNLED is enabled (generated) */
#define REDGRNLED_SetOffsetTicks_METHOD_ENABLED /*!< SetOffsetTicks method of the component REDGRNLED is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define REDGRNLED_OnChannel0_EVENT_ENABLED /*!< OnChannel0 event of the component REDGRNLED is enabled (generated) */



/*
** ===================================================================
**     Method      :  REDGRNLED_Init (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property ["Enable in init. code"] is set to "yes" value then
**         the device is also enabled (see the description of the
**         [Enable] method). In this case the [Enable] method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the [Deinit]
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* REDGRNLED_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  REDGRNLED_SetOffsetTicks (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Sets the new offset value to channel specified by the
**         parameter ChannelIdx. It is user responsibility to use value
**         below selected period. This method is available when at
**         least one channel is configured.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         ChannelIdx      - Index of the component
**                           channel.
**     @param
**         Ticks           - Number of counter ticks to compare
**                           match.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range.
**                           ERR_NOTAVAIL -  The compare mode is not
**                           selected for selected channel
**                           ERR_PARAM_TICKS - Ticks parameter is out of
**                           possible range.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError REDGRNLED_SetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, REDGRNLED_TValueType Ticks);

/*
** ===================================================================
**     Method      :  REDGRNLED_Interrupt (component TimerUnit_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(REDGRNLED_Interrupt);

/* END REDGRNLED. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __REDGRNLED_H */
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
