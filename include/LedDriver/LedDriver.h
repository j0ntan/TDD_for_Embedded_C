#ifndef D_LedDriver_H
#define D_LedDriver_H

#include <stdint.h>
#include "BOOL.h"

void LedDriver_Create(uint16_t * ledsAddress);

void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnAllOff(void);

BOOL LedDriver_IsOn(int ledNumber);
BOOL LedDriver_IsOff(int ledNumber);

#endif /* D_LedDriver_H */
