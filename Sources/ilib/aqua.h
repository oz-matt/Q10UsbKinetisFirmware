/*
 * aqua.h
 *
 *  Created on: Jul 23, 2017
 *      Author: TARS
 */

#ifndef AQUA_H_
#define AQUA_H_

#include "PE_Types.h"

#define SETFLAG(flag, field) field |= (flag)
#define CLEARFLAG(flag, field) field &= ~(flag)
#define CHECKFLAG(flag, field) field & flag

typedef struct{
	bool morseStart;
	bool morseActive;
	
	int morseArrayPosition;
	uint8_t morseBitPosition;
}AquaMorseFlags;

void checkVitals(void);

#endif /* AQUA_H_ */
