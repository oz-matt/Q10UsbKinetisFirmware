/*
 * ledasync.c
 *
 *  Created on: Jul 23, 2017
 *      Author: TARS
 */

#include "ledasync.h"
#include "ledhandler.h"
#include "ilib/aqua.h"

#include "PE_Types.h"
#include "stdio.h"
#include "string.h"

extern NewLedFlags LedFlags;
extern ActiveLedFlags LedActives;

rgbLevels rgbSrcLevels = {0};

void asyncLedElement(int flag, int activeFlag, int* posCtr, int source, int color, const char* ledArray, bool continuous)
{
	
	if (CHECKFLAG(flag, LedFlags)) { /* If this LED flag has been set, we are supposed to asynchronously start the LED sequence indicated in 'ledArray' */
		
		if (!(CHECKFLAG(activeFlag, LedActives))) {
			
			 /* 
			  * Right when we start, we set all the LEDs from the given source to zero. This means that any
			  * subsequent requests with this source will override this request and start it's own.
			  */
			
			lightLED(source, RED, 0);
			lightLED(source, GREEN, 0);
			lightLED(source, BLUE, 0);
			
			SETFLAG(activeFlag, LedActives); /* We are now in 'active' mode. */
		}
		
		lightLED(source, color, ledArray[*posCtr]);
		
		/* 
		 * Send writes to the actual array (ledSrcBuffer) handling asynchronous LED sequences.
		 * This function fires once every 10ms when 'flag' is set, and this function controls
		 * the light for one instance of 10ms -- reading it from the correct element of ledArray.
		*/
		
		if (*posCtr == (strlen(ledArray) - 1)) { /* Checks if we are at the end of ledArray */
			if (!continuous) { /* Continuous requests will loop back to ledArray[0] after reaching the end. This means the LED will not stop on its own */

				CLEARFLAG(flag, LedFlags);
				
				/* 
				 * Clear our main flag. The erasing of our influences on the LED and setting active mode off will be done in the next
				 * iteration of this function in the 'are we still in active mode?' section.
				 */

			}
			
			*posCtr = 0;
		
		} else (*posCtr)++; /* Go to the next element of ledArray for the next 10ms */
		
	} else {
		if (CHECKFLAG(activeFlag, LedActives)) { /* Are we still in 'active' mode? */
			
			/*
			 * The main ledFlag (flag) was just turned off. Let's erase the influence of the flag being on.
			 */
			
			removeLEDSrc(source, color);
			CLEARFLAG(flag, LedFlags);
			CLEARFLAG(activeFlag, LedActives);
			*posCtr = 0;
			
		}
	}
}

void asyncUsbLedElement(int flag, int activeFlag, int* posCtr, int source, const char* ledArray, uint8_t battpct, uint8_t adjust)
{
	
	static int ctr = 0;
	
	if (CHECKFLAG(flag, LedFlags)) { /* If this LED flag has been set, we are supposed to asynchronously start the LED sequence indicated in 'ledArray' */
		
		static int currentRed, currentGreen, currentBlue;
		
		if (!(CHECKFLAG(activeFlag, LedActives))) {
			
			 /* 
			  * Right when we start, we set all the LEDs from the given source to zero. This means that any
			  * subsequent requests with this source will override this request and start it's own.
			  */
			
			ctr=0;
			SETFLAG(activeFlag, LedActives); /* We are now in 'active' mode. */
			
			uint8_t rgblvls[4] = {0};
			rgbValuesPtr(rgblvls);
			
			currentRed = rgblvls[0];
			currentGreen = rgblvls[1];
			currentBlue = rgblvls[2];
		}
		
		
		
		
		
		//lightLED(source, BLUE, ledArray[*posCtr]);
		
		//uint8_t corp = (rgbSrcLevels.green);
		
		if (ctr < 200) {
			
			lightLED(source, RED, ctr * (.005) * (100 - battpct) + (200-ctr) * .005 * (currentRed));
			lightLED(source, GREEN, (200-ctr) * (.005) * currentGreen);
			lightLED(source, BLUE, ctr * (.005) * (battpct) + (200-ctr) * .005 * (currentBlue));
			ctr++;
		} else {
			lightLED(source, RED, (95 - battpct) + adjust);
			lightLED(source, BLUE, battpct + adjust - 5);
		}
		
		//If ctr < 2000ms, multiply red and green influences by a fade constant
		//Else, read i2c and adjust color accordingly
		
		/* 
		 * Send writes to the actual array (ledSrcBuffer) handling asynchronous LED sequences.
		 * This function fires once every 10ms when 'flag' is set, and this function controls
		 * the light for one instance of 10ms -- reading it from the correct element of ledArray.
		*/
		
		//if (*posCtr == (strlen(ledArray) - 1)) { /* Checks if we are at the end of ledArray */
		
		//} else (*posCtr)++; /* Go to the next element of ledArray for the next 10ms */
		
	} else {
		if (CHECKFLAG(activeFlag, LedActives)) { /* Are we still in 'active' mode? */
			
			/*
			 * The main ledFlag (flag) was just turned off. Let's erase the influence of the flag being on.
			 */
			removeLEDSrc(source, BLUE);
			removeLEDSrc(source, GREEN);
			removeLEDSrc(source, RED);
			CLEARFLAG(flag, LedFlags);
			CLEARFLAG(activeFlag, LedActives);
			*posCtr = 0;
			ctr = 0;
			
		}
	}
}
