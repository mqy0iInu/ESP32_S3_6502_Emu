#ifndef RAM_6502_H
#define RAM_6502_H

#include <stdint.h>

#define EnBASIC_6502_USE

#ifdef EnBASIC_6502_USE
#define RAM_SIZE    65536
#else
#define RAM_SIZE    8192
// #define RAM_SIZE    65536
#endif

#endif /* RAM_6502_H */