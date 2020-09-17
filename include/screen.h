#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#define VIDEO_MEMORY_START 0xb8000
#define DEFAULT_FORMAT 0x0f
#define ROW 25
#define COL 80

typedef struct _cursor {
  int col;
  int row;
} cursor;

cursor *cur;

void creset(); //cursor reset
unsigned int gvaddr(char row, char col);
void putc(char row, char col, char c);
void putcf(char row, char col, char c, char cf);
void sclear(); //screen clear
void cinc(); //increment cursor
void cdec(); //decrement cursor
void print(char *string);
void printf(char *string, char format);
void cnewline(); //cursor newline

#include "screen.c"

#endif
