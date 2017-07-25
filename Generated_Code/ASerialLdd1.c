/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : ASerialLdd1.c
**     Project     : UsbKinetis24
**     Processor   : MKL02Z32VFK4
**     Component   : Serial_LDD
**     Version     : Component 01.187, Driver 01.13, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-07-22, 09:43, # CodeGen: 8
**     Abstract    :
**         This component "Serial_LDD" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial communication channel.
**     Settings    :
**          Component name                                 : ASerialLdd1
**          Device                                         : UART0
**          Interrupt service/event                        : Disabled
**          Settings                                       : 
**            Data width                                   : 8 bits
**            Parity                                       : None
**            Stop bits                                    : 1
**            Loop mode                                    : Normal
**            Baud rate                                    : 9600 baud
**            Wakeup condition                             : Idle line wakeup
**            Stop in wait mode                            : no
**            Idle line mode                               : Starts after start bit
**            Transmitter output                           : Not inverted
**            Receiver input                               : Not inverted
**            Break generation length                      : 10/11 bits
**            Receiver                                     : Enabled
**              RxD                                        : ADC0_SE4/PTB2/IRQ_7/UART0_RX/UART0_TX
**              RxD pin signal                             : 
**            Transmitter                                  : Enabled
**              TxD                                        : ADC0_SE5/CMP0_IN3/PTB1/IRQ_6/UART0_TX/UART0_RX
**              TxD pin signal                             : 
**            Flow control                                 : None
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnBlockSent                                : Disabled
**              OnBlockReceived                            : Disabled
**              OnTxComplete                               : Disabled
**              OnError                                    : Disabled
**              OnBreak                                    : Enabled
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
**         Init               - LDD_TDeviceData* ASerialLdd1_Init(LDD_TUserData *UserDataPtr);
**         SendBlock          - LDD_TError ASerialLdd1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ReceiveBlock       - LDD_TError ASerialLdd1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         GetError           - LDD_TError ASerialLdd1_GetError(LDD_TDeviceData *DeviceDataPtr,...
**         GetReceivedDataNum - uint16_t ASerialLdd1_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
**         Main               - void ASerialLdd1_Main(LDD_TDeviceData *DeviceDataPtr);
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
** @file ASerialLdd1.c
** @version 01.13
** @brief
**         This component "Serial_LDD" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial communication channel.
*/         
/*!
**  @addtogroup ASerialLdd1_module ASerialLdd1 module documentation
**  @{
*/         

/* MODULE ASerialLdd1. */
/*lint -save  -e926 -e927 -e928 -e929 -e572 Disable MISRA rule (11.4,12.8) checking. */

/* {Default RTOS Adapter} No RTOS includes */
#include "ASerialLdd1.h"
#include "Inhr1.h"
#include "UART0_PDD.h"
#include "SIM_PDD.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! The mask of available events used to enable/disable events during runtime. */
#define AVAILABLE_EVENTS_MASK (LDD_SERIAL_ON_BREAK)

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static ASerialLdd1_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

/*
** ===================================================================
**     Method      :  ASerialLdd1_Init (component Serial_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the "Enable
**         in init. code" is set to "yes" value then the device is also
**         enabled(see the description of the Enable() method). In this
**         case the Enable() method is not necessary and needn't to be
**         generated. 
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/
LDD_TDeviceData* ASerialLdd1_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  ASerialLdd1_TDeviceDataPtr DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;

  /* Clear the receive counters and pointer */
  DeviceDataPrv->InpRecvDataNum = 0x00U; /* Clear the counter of received characters */
  DeviceDataPrv->InpDataNumReq = 0x00U; /* Clear the counter of characters to receive by ReceiveBlock() */
  DeviceDataPrv->InpDataPtr = NULL;    /* Clear the buffer pointer for received characters */
  /* Clear the transmit counters and pointer */
  DeviceDataPrv->OutSentDataNum = 0x00U; /* Clear the counter of sent characters */
  DeviceDataPrv->OutDataNumReq = 0x00U; /* Clear the counter of characters to be send by SendBlock() */
  DeviceDataPrv->OutDataPtr = NULL;    /* Clear the buffer pointer for data to be transmitted */
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* SIM_SCGC4: UART0=1 */
  SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
  /* PORTB_PCR2: ISF=0,MUX=2 */
  PORTB_PCR2 = (uint32_t)((PORTB_PCR2 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x05)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x02)
               ));
  /* PORTB_PCR1: ISF=0,MUX=2 */
  PORTB_PCR1 = (uint32_t)((PORTB_PCR1 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x05)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x02)
               ));
  UART0_PDD_EnableTransmitter(UART0_BASE_PTR, PDD_DISABLE); /* Disable transmitter. */
  UART0_PDD_EnableReceiver(UART0_BASE_PTR, PDD_DISABLE); /* Disable receiver. */
  DeviceDataPrv->SerFlag = 0x00U;      /* Reset flags */
  DeviceDataPrv->ErrFlag = 0x00U;      /* Reset error flags */
  /* UART0_C1: LOOPS=0,DOZEEN=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  UART0_C1 = 0x00U;                    /*  Set the C1 register */
  /* UART0_C3: R8T9=0,R9T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
  UART0_C3 = 0x00U;                    /*  Set the C3 register */
  /* UART0_C4: MAEN1=0,MAEN2=0,M10=0,OSR=0 */
  UART0_C4 = UART0_C4_OSR(0x00);       /*  Set the C4 register */
  /* UART0_S2: LBKDIF=0,RXEDGIF=0,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
  UART0_S2 = 0x00U;                    /*  Set the S2 register */
  SIM_PDD_SetClockSourceUART0(SIM_BASE_PTR, SIM_PDD_UART0_FLL_CLOCK);
  UART0_PDD_SetBaudRate(UART0_BASE_PTR, 546U); /* Set the baud rate register. */
  UART0_PDD_SetOversamplingRatio(UART0_BASE_PTR, 3U);
  UART0_PDD_EnableSamplingOnBothEdges(UART0_BASE_PTR, PDD_ENABLE);
  UART0_PDD_EnableTransmitter(UART0_BASE_PTR, PDD_ENABLE); /* Enable transmitter */
  UART0_PDD_EnableReceiver(UART0_BASE_PTR, PDD_ENABLE); /* Enable receiver */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_ASerialLdd1_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  ASerialLdd1_ReceiveBlock (component Serial_LDD)
*/
/*!
**     @brief
**         Specifies the number of data to receive. The method returns
**         ERR_BUSY until the specified number of characters is
**         received. Method [CancelBlockReception] can be used to
**         cancel a running receive operation. If a receive operation
**         is not in progress (the method was not called or a previous
**         operation has already finished) all received characters will
**         be lost without any notification. To prevent the loss of
**         data call the method immediately after the last receive
**         operation has finished (e.g. from the [OnBlockReceived]
**         event). This method finishes immediately after calling it -
**         it doesn't wait the end of data reception. Use event
**         [OnBlockReceived] to check the end of data reception.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferPtr       - Pointer to a buffer where
**                           received characters will be stored. In case
**                           of 8bit character width each character in
**                           buffer occupies 1 byte. In case of 9 and
**                           more bit long character width each
**                           character in buffer occupies 2 bytes.
**     @param
**         Size            - Number of characters to receive
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_PARAM_SIZE - Parameter Size is out of
**                           expected range.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous receive request is
**                           pending.
*/
/* ===================================================================*/
LDD_TError ASerialLdd1_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size)
{
  ASerialLdd1_TDeviceDataPtr DeviceDataPrv = (ASerialLdd1_TDeviceDataPtr)DeviceDataPtr;

  if (Size == 0U) {                    /* Is the parameter Size within an expected range? */
    return ERR_PARAM_SIZE;             /* If no then error */
  }
  if (DeviceDataPrv->InpDataNumReq != 0x00U) { /* Is the previous receive operation pending? */
    return ERR_BUSY;                   /* If yes then error */
  }
  DeviceDataPrv->InpDataPtr = (uint8_t*)BufferPtr; /* Store a pointer to the input data. */
  DeviceDataPrv->InpDataNumReq = Size; /* Store a number of characters to be received. */
  DeviceDataPrv->InpRecvDataNum = 0x00U; /* Set number of received characters to zero. */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  ASerialLdd1_SendBlock (component Serial_LDD)
*/
/*!
**     @brief
**         Sends a block of characters. The method returns ERR_BUSY
**         when the previous block transmission is not completed.
**         Method [CancelBlockTransmission] can be used to cancel a
**         transmit operation. This method is available only if the
**         transmitter property is enabled. This method finishes
**         immediately after calling it - it doesn't wait the end of
**         data transmission. Use event [OnBlockSent] to check the end
**         of data transmission.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferPtr       - Pointer to a buffer from where
**                           data will be sent. In case of 8bit
**                           character width each character in buffer
**                           occupies 1 byte. In case of 9 and more bit
**                           long character width each character in
**                           buffer occupies 2 bytes.
**     @param
**         Size            - Number of characters in the buffer.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_PARAM_SIZE - Parameter Size is out of
**                           expected range.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous transmit request is
**                           pending.
*/
/* ===================================================================*/
LDD_TError ASerialLdd1_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size)
{
  ASerialLdd1_TDeviceDataPtr DeviceDataPrv = (ASerialLdd1_TDeviceDataPtr)DeviceDataPtr;

  if (Size == 0U) {                    /* Is the parameter Size within an expected range? */
    return ERR_PARAM_SIZE;             /* If no then error */
  }
  if (DeviceDataPrv->OutDataNumReq != 0x00U) { /* Is the previous transmit operation pending? */
    return ERR_BUSY;                   /* If yes then error */
  }
  DeviceDataPrv->OutDataPtr = (uint8_t*)BufferPtr; /* Set a pointer to the output data. */
  DeviceDataPrv->OutDataNumReq = Size; /* Set the counter of characters to be sent. */
  DeviceDataPrv->OutSentDataNum = 0x00U; /* Clear the counter of sent characters. */
  DeviceDataPrv->SerFlag |= ENABLED_TX_INT; /* Set the flag ENABLED_TX_INT */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  ASerialLdd1_GetReceivedDataNum (component Serial_LDD)
*/
/*!
**     @brief
**         Returns the number of received characters in the receive
**         buffer. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Number of received characters in the receive
**                           buffer.
*/
/* ===================================================================*/
uint16_t ASerialLdd1_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr)
{
  ASerialLdd1_TDeviceDataPtr DeviceDataPrv = (ASerialLdd1_TDeviceDataPtr)DeviceDataPtr;

  return (DeviceDataPrv->InpRecvDataNum); /* Return the number of received characters. */
}

/*
** ===================================================================
**     Method      :  InterruptRx (component Serial_LDD)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void InterruptRx(ASerialLdd1_TDeviceDataPtr DeviceDataPrv)
{
  register uint16_t Data;              /* Temporary variable for data */

  Data = (uint16_t)UART0_PDD_GetChar8(UART0_BASE_PTR); /* Read an 8-bit character from the receiver */
  if (DeviceDataPrv->InpDataNumReq != 0x00U) { /* Is the receive block operation pending? */
    *(DeviceDataPrv->InpDataPtr++) = (uint8_t)Data; /* Put an 8-bit character to the receive buffer */
    DeviceDataPrv->InpRecvDataNum++;   /* Increment received char. counter */
    if (DeviceDataPrv->InpRecvDataNum == DeviceDataPrv->InpDataNumReq) { /* Is the requested number of characters received? */
      DeviceDataPrv->InpDataNumReq = 0x00U; /* If yes then clear number of requested characters to be received. */
    }
  }
}

/*
** ===================================================================
**     Method      :  InterruptTx (component Serial_LDD)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void InterruptTx(ASerialLdd1_TDeviceDataPtr DeviceDataPrv)
{

  if (DeviceDataPrv->OutSentDataNum < DeviceDataPrv->OutDataNumReq) { /* Is number of sent characters less than the number of requested incoming characters? */
    UART0_PDD_PutChar8(UART0_BASE_PTR, *(DeviceDataPrv->OutDataPtr++)); /* Put a 8-bit character to the transmit register */
    DeviceDataPrv->OutSentDataNum++;   /* Increment the counter of sent characters. */
    if (DeviceDataPrv->OutSentDataNum == DeviceDataPrv->OutDataNumReq) {
      DeviceDataPrv->OutDataNumReq = 0x00U; /* Clear the counter of characters to be send by SendBlock() */
    }
  } else {
    DeviceDataPrv->SerFlag &= (uint16_t)(~(uint16_t)ENABLED_TX_INT); /* Clear the flag ENABLED_TX_INT */
  }
}

/*
** ===================================================================
**     Method      :  ASerialLdd1_Main (component Serial_LDD)
*/
/*!
**     @brief
**         This method is available only in the polling mode (Interrupt
**         service/event = 'no'). If interrupt service is disabled this
**         method replaces the interrupt handler. This method should be
**         called if Receive/SendBlock was invoked before in order to
**         run the reception/transmission. The end of the
**         receiving/transmitting is indicated by OnBlockSent or
**         OnBlockReceived event. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
*/
/* ===================================================================*/
void ASerialLdd1_Main(LDD_TDeviceData *DeviceDataPtr)
{
  ASerialLdd1_TDeviceDataPtr DeviceDataPrv = (ASerialLdd1_TDeviceDataPtr)DeviceDataPtr;
  register uint32_t StatReg = UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR); /* Read status register */
  register uint16_t OnErrorFlags = 0U; /* Temporary variable for flags */
  register uint8_t  OnBreakFlag = 0U;  /* Temporary variable flag for OnBreak event */
  register uint16_t Data;              /* Temporary variable for data */

  if (StatReg & (UART0_S1_NF_MASK | UART0_S1_OR_MASK | UART0_S1_FE_MASK | UART0_S1_PF_MASK)) { /* Is any error flag set? */
    UART0_PDD_ClearInterruptFlags(UART0_BASE_PTR, (UART0_S1_NF_MASK | UART0_S1_OR_MASK | UART0_S1_FE_MASK | UART0_S1_PF_MASK));
    Data = (uint16_t)UART0_PDD_GetChar8(UART0_BASE_PTR); /* Read an 8-bit character from receiver */
    if ((StatReg & UART0_S1_FE_MASK) != 0U) { /* Is the framing error detected? */
      if (((StatReg & UART0_S1_RDRF_MASK) != 0U) && (Data == 0U)) { /* Is the zero character in the receiver? */
        OnBreakFlag++;
        DeviceDataPrv->SerFlag |= BREAK_DETECTED; /* If yes then set the flag */
      } else {
        OnErrorFlags |= LDD_SERIAL_FRAMING_ERROR; /* If yes then set the flag */
      }
    }
    if ((StatReg & UART0_S1_OR_MASK) != 0U) { /* Is the overrun error flag set? */
      OnErrorFlags |= LDD_SERIAL_RX_OVERRUN; /* If yes then set the flag */
    }
    if ((StatReg & UART0_S1_PF_MASK) != 0U) { /* Is the parity error flag set? */
      OnErrorFlags |= LDD_SERIAL_PARITY_ERROR; /* If yes then set the flag */
    }
    if ((StatReg & UART0_S1_NF_MASK) != 0U) { /* Is the noise error flag set? */
      OnErrorFlags |= LDD_SERIAL_NOISE_ERROR; /* If yes then set the flag */
    }
    DeviceDataPrv->ErrFlag |= OnErrorFlags; /* Copy flags status to ErrFlag status variable */
    StatReg &= (uint32_t)(~(uint32_t)UART0_S1_RDRF_MASK); /* Clear the receive data flag to discard the errorneous data */
    if (OnBreakFlag != 0U) {
      ASerialLdd1_OnBreak(DeviceDataPrv->UserDataPtr); /* If yes then invoke user event */
  }
  }
  if (StatReg & UART0_S1_RDRF_MASK) {  /* Is the receiver's interrupt flag set? */
    InterruptRx(DeviceDataPrv);        /* If yes, then invoke the internal service routine. This routine is inlined. */
  }
  if (DeviceDataPrv->SerFlag & ENABLED_TX_INT) { /* Is the transmitter interrupt enabled? */
    if (StatReg & UART0_S1_TDRE_MASK) { /* Is the transmitter empty? */
      InterruptTx(DeviceDataPrv);      /* If yes, then invoke the internal service routine. This routine is inlined. */
    }
  }
}

/*
** ===================================================================
**     Method      :  ASerialLdd1_GetError (component Serial_LDD)
*/
/*!
**     @brief
**         This method returns a set of asserted flags. The flags are
**         accumulated in the set. After calling this method the set is
**         returned and cleared.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         ErrorPtr        - A pointer to the returned set of
**                           error flags:
**                           LDD_SERIAL_RX_OVERRUN - Receiver overrun.
**                           LDD_SERIAL_PARITY_ERROR - Parity error
**                           (only if HW supports parity feature).
**                           LDD_SERIAL_FRAMING_ERROR - Framing error.
**                           LDD_SERIAL_NOISE_ERROR - Noise error.
**     @return
**                         - Error code (if GetError did not succeed),
**                           possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_DISABLED - Component is disabled
*/
/* ===================================================================*/
LDD_TError ASerialLdd1_GetError(LDD_TDeviceData *DeviceDataPtr, LDD_SERIAL_TError *ErrorPtr)
{
  ASerialLdd1_TDeviceDataPtr DeviceDataPrv = (ASerialLdd1_TDeviceDataPtr)DeviceDataPtr;

  *ErrorPtr = DeviceDataPrv->ErrFlag;
  DeviceDataPrv->ErrFlag = 0x00U;      /* Reset error flags */
  return ERR_OK;                       /* OK */
}

/*lint -restore Enable MISRA rule (11.4,12.8) checking. */
/* END ASerialLdd1. */

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