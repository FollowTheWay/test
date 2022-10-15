#ifndef __BLUETOOTH_H
#define __BLUETOOTH_H

#include "stdint.h"

extern uint8_t RX_flag;

void BT_init(void);
void Check_Rx(void);

#endif

