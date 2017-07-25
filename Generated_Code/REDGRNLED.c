/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : REDGRNLED.c
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
** @file REDGRNLED.c
** @version 01.11
** @brief
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
*/         
/*!
**  @addtogroup REDGRNLED_module REDGRNLED module documentation
**  @{
*/         

/* MODULE REDGRNLED. */

#include "Events.h"
#include "REDGRNLED.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* List of channels used by component */
static const uint8_t ChannelDevice[REDGRNLED_NUMBER_OF_CHANNELS] = {0x01U,0x00U};

/* Table of channels mode / 0 - compare mode, 1 - capture mode */
static const uint8_t ChannelMode[REDGRNLED_NUMBER_OF_CHANNELS] = {0x00U,0x00U};


typedef struct {
  LDD_TEventMask EnEvents;             /* Enable/Disable events mask */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} REDGRNLED_TDeviceData;

typedef REDGRNLED_TDeviceData *REDGRNLED_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static REDGRNLED_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static REDGRNLED_TDeviceDataPtr INT_TPM0__DEFAULT_RTOS_ISRPARAM;

#define AVAILABLE_EVENTS_MASK (LDD_TEventMask)(LDD_TIMERUNIT_ON_CHANNEL_0)
#define AVAILABLE_PIN_MASK (LDD_TPinMask)(REDGRNLED_CHANNEL_0_PIN | REDGRNLED_CHANNEL_1_PIN)
#define LAST_CHANNEL 0x01U

/* Internal method prototypes */
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
LDD_TDeviceData* REDGRNLED_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  REDGRNLED_TDeviceData *DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* Interrupt vector(s) allocation */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_TPM0__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* SIM_SCGC6: TPM0=1 */
  SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;
  /* TPM0_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,DMA=0,TOF=0,TOIE=0,CPWMS=0,CMOD=0,PS=0 */
  TPM0_SC = (TPM_SC_CMOD(0x00) | TPM_SC_PS(0x00)); /* Clear status and control register */
  /* TPM0_CNT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COUNT=0 */
  TPM0_CNT = TPM_CNT_COUNT(0x00);      /* Reset counter register */
  /* TPM0_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  TPM0_C0SC = 0x00U;                   /* Clear channel status and control register */
  /* TPM0_C1SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  TPM0_C1SC = 0x00U;                   /* Clear channel status and control register */
  /* TPM0_MOD: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,MOD=0x3D70 */
  TPM0_MOD = TPM_MOD_MOD(0x3D70);      /* Set up modulo register */
  /* TPM0_C1SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=1,MSB=1,MSA=0,ELSB=1,ELSA=0,??=0,DMA=0 */
  TPM0_C1SC = (TPM_CnSC_CHIE_MASK | TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK); /* Set up channel status and control register */
  /* TPM0_C1V: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,VAL=0 */
  TPM0_C1V = TPM_CnV_VAL(0x00);        /* Set up channel value register */
  /* TPM0_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=1,MSA=0,ELSB=1,ELSA=0,??=0,DMA=0 */
  TPM0_C0SC = (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK); /* Set up channel status and control register */
  /* TPM0_C0V: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,VAL=0 */
  TPM0_C0V = TPM_CnV_VAL(0x00);        /* Set up channel value register */
  /* PORTA_PCR5: ISF=0,MUX=2 */
  PORTA_PCR5 = (uint32_t)((PORTA_PCR5 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x05)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x02)
               ));
  /* PORTA_PCR6: ISF=0,MUX=2 */
  PORTA_PCR6 = (uint32_t)((PORTA_PCR6 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x05)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x02)
               ));
  DeviceDataPrv->EnEvents = 0x01U;     /* Enable selected events */
  /* NVIC_IPR4: PRI_17=0x80 */
  NVIC_IPR4 = (uint32_t)((NVIC_IPR4 & (uint32_t)~(uint32_t)(
               NVIC_IP_PRI_17(0x7F)
              )) | (uint32_t)(
               NVIC_IP_PRI_17(0x80)
              ));
  /* NVIC_ISER: SETENA|=0x00020000 */
  NVIC_ISER |= NVIC_ISER_SETENA(0x00020000);
  /* TPM0_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,DMA=0,TOF=0,TOIE=0,CPWMS=0,CMOD=1,PS=3 */
  TPM0_SC = (TPM_SC_CMOD(0x01) | TPM_SC_PS(0x03)); /* Set up status and control register */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_REDGRNLED_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

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
LDD_TError REDGRNLED_SetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, REDGRNLED_TValueType Ticks)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Parameter test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (ChannelIdx > LAST_CHANNEL) {     /* Is the channel index out of range? */
    return ERR_PARAM_INDEX;            /* If yes then error */
  }
  if ((ChannelMode[ChannelIdx]) != 0U) { /* Is the channel in compare mode? */
    return ERR_NOTAVAIL;               /* If not then error */
  }
  TPM_PDD_WriteChannelValueReg(TPM0_BASE_PTR, ChannelDevice[ChannelIdx], (uint16_t)Ticks);
  if (Ticks > 65535U) {                /* Was the given value greater than counter width? */
    return ERR_PARAM_TICKS;            /* If yes then truncation of user data to 16 bits is reported */
  }
  return ERR_OK;                       /* OK */
}

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
PE_ISR(REDGRNLED_Interrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  REDGRNLED_TDeviceDataPtr DeviceDataPrv = INT_TPM0__DEFAULT_RTOS_ISRPARAM;

  LDD_TEventMask State = 0U;

  if ((TPM_PDD_GetChannelInterruptFlag(TPM0_BASE_PTR, ChannelDevice[0])) != 0U) { /* Is the channel interrupt flag pending? */
    State |= LDD_TIMERUNIT_ON_CHANNEL_0; /* and set mask */
  }
  State &= DeviceDataPrv->EnEvents;    /* Handle only enabled interrupts */
  if (State & LDD_TIMERUNIT_ON_CHANNEL_0) { /* Is the channel 0 interrupt flag pending? */
    TPM_PDD_ClearChannelInterruptFlag(TPM0_BASE_PTR, ChannelDevice[0]); /* Clear flag */
    REDGRNLED_OnChannel0(DeviceDataPrv->UserDataPtr); /* Invoke OnChannel0 event */
  }
}

/* END REDGRNLED. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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