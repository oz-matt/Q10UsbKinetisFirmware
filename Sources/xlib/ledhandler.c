/*
 * ledhandler.c
 *
 *  Created on: Jul 23, 2017
 *      Author: TARS
 */

#include "ledhandler.h"
#include "WAIT1.h"
#include "PE_Types.h"
#include <ilib/aqua.h>
#include "ledasync.h"
#include "REDGRNLED.h"
#include "BLULED.h"

#define GETBIT(x,n) (((x) >> (n)) & 1)

NewLedFlags LedFlags = 0;
ActiveLedFlags LedActives = 0;
AsyncLedArrayPos LedPos = {0};

byte ledSrcBuffer[TOTAL_NUM_LED_SOURCES][3];

const char successfulPowerupLEDarray[256] = INIT_SUCCESSFUL_POWERUP_LED_ARRAY;
const char unsuccessfulPowerupLEDarray[200] = INIT_UNSUCCESSFUL_POWERUP_LED_ARRAY;
const char criticalFaultLEDarray[60] = INIT_CRITICAL_FAULT_LED_ARRAY;

const char initRedDiscoLEDarray[] = INIT_RED_DISCO_LED_ARRAY;
const char initGreenDiscoLEDarray[] = INIT_GREEN_DISCO_LED_ARRAY;
const char initBlueDiscoLEDarray[] = INIT_BLUE_DISCO_LED_ARRAY;

const char morseCoordinatesArray[] = MORSE_COORDINATES;

void lightLED(int source, int color, int amount) {
	ledSrcBuffer[source][color] = amount;
}

void removeLEDSrc(int source, int color) {
	ledSrcBuffer[source][color] = 0;
}

int scalepwm(int level) {
	
	int levelscaled = (level * 10);

	if (levelscaled > 999) levelscaled = 999;
	else if (levelscaled < 2) levelscaled = 0;
	
	return levelscaled;
	
}

void updateLEDs(void) {
	
	/* 
	 * This is an asynchronous task that runs every 10ms in the 'TI2' interrupt (see Events.c)
	 * It updates the LEDs and is handled by the functions 'lightLED' and 'removeLEDSrc.
	 */
	
	int i;
	int redlevel = 0, grnlevel = 0, blulevel = 0;
	
	for (i=0;i<TOTAL_NUM_LED_SOURCES;i++) {
		redlevel += ledSrcBuffer[i][RED];
		grnlevel += ledSrcBuffer[i][GREEN];
		blulevel += ledSrcBuffer[i][BLUE];
	}
	
	if (redlevel < 0) redlevel = 0;
	if (redlevel > 999) redlevel = 999;
	
	if (grnlevel < 0) grnlevel = 0;
	if (grnlevel > 999) grnlevel = 999;
	
	if (blulevel < 0) blulevel = 0;
	if (blulevel > 999) blulevel = 999;
	
	/* 
	 * Now redlevel, grnlevel and blulevel contain a number from 0-100 indicating the desired intensity of light
	 * for the LEDs. This number will get scaled by 'scalepwm' to a number between 0 and 2000 to designate the
	 * overall duty cycle of the pwm going to the led.
	 */
	
	REDGRNLED_SetOffsetTicks(NULL, 0, redlevel);
	REDGRNLED_SetOffsetTicks(NULL, 1, grnlevel);
	BLULED_SetOffsetTicks(NULL, 0, blulevel);
}

void fastRedFlash(int source) {
	lightLED(source, RED, 50);
	WAIT1_Waitms(200);
	lightLED(source, RED, 20);
	WAIT1_Waitms(200);
}

void allLEDsOff(void) {
	//GRNL_SetDutyUS(2000);
	//REDPWM_SetDutyUS(2000);
	//BLUPWM_SetDutyUS(2000);
}

void powerUpSuccessLEDflicker(void) {

	checkVitals(); /* Turns on LED while checking vitals. Locks up if vital check fails */
	
	SETFLAG(SuccessfulPowerup, LedFlags);
	CLEARFLAG(UnsuccessfulPowerup, LedFlags);
	  
}


void ledQueueHandle(void) {
	
	asyncLedElement(SuccessfulPowerup, SuccessfulPowerupActive, &LedPos.SuccessfulPowerupPos, KEYLOCK_LED_SRC, GREEN, successfulPowerupLEDarray, FALSE);
	asyncLedElement(UnsuccessfulPowerup, UnsuccessfulPowerupActive, &LedPos.UnsuccessfulPowerupPos, KEYLOCK_LED_SRC, RED, unsuccessfulPowerupLEDarray, TRUE);
	asyncLedElement(CriticalFault, CriticalFaultActive, &LedPos.CriticalFaultPos, VITALS_SRC, RED, criticalFaultLEDarray, TRUE);
	
	asyncLedElement(Disco, DiscoActive, &LedPos.DiscoRedPos, DISCO_SRC, RED, initRedDiscoLEDarray, TRUE);
	asyncLedElement(Disco, DiscoActive, &LedPos.DiscoGreenPos, DISCO_SRC, GREEN, initGreenDiscoLEDarray, TRUE);
	asyncLedElement(Disco, DiscoActive, &LedPos.DiscoBluePos, DISCO_SRC, BLUE, initBlueDiscoLEDarray, TRUE);

}
void powerUpFailureLEDflicker(void) {
	
	checkVitals(); /* Turns on LED while checking vitals. Locks up if vital check fails */
	
	SETFLAG(UnsuccessfulPowerup, LedFlags);
	CLEARFLAG(SuccessfulPowerup, LedFlags);
}
void powerUpFailureLEDflicker2(void) {
	
SETFLAG(Disco, LedFlags);
	  	  		CLEARFLAG(SuccessfulPowerup, LedFlags);

}
