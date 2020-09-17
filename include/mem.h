#ifndef MEM_H_INCLUDED
#define MEM_H_INCLUDED

#define DEFAULT_FILLER 0x0

#include <types.h>

void rmemshift(u8int* start, u32int len, u32int shift); //right memory shift
void lmemshift(u8int* start, u32int len, u32int shift); //left memory shift
void rmemshiftf(u8int* start, u32int len, u32int shift, u8int filler); //right memory shift filler
void lmemshiftf(u8int* start, u32int len, u32int shift, u8int filler); //left memory shift filler
#include "mem.c"

#endif
