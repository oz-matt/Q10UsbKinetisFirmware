/*
 * ledasync.h
 *
 *  Created on: Jul 23, 2017
 *      Author: TARS
 */

#ifndef LEDASYNC_H_
#define LEDASYNC_H_

#include "PE_Types.h"

void asyncLedElement(int flag, int activeFlag, int* posCtr, int source, int color, const char* ledArray, bool continuous);

#endif /* LEDASYNC_H_ */
