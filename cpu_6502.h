#ifndef CPU_6502_H
#define CPU_6502_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "ram_6502.h"

#ifdef __cplusplus
extern "C" {
#endif

uint16_t getpc();
uint8_t getop();
void exec6502(int32_t tickcount);
void reset6502();

extern void serout(uint8_t val);
extern uint8_t getkey();
extern void clearkey();
extern void printhex(uint16_t val);

#ifdef __cplusplus
}
#endif

#endif /* CPU_6502_H */