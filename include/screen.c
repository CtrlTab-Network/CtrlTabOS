void creset() {
  cur->col = 0;
  cur->row = 0;
}

unsigned int gvaddr(char row, char col) { //get video address
  return (unsigned int)(VIDEO_MEMORY_START + 2 * (row * COL + col));
}

void putc(char row, char col, char c) { //put char on screen, cf = char format
  putcf(row, col, c, DEFAULT_FORMAT);
}

void putcf(char row, char col, char c, char cf) { //put char on screen, cf = char format
  char *video_memory = (char*) (unsigned int) gvaddr(row, col);
  *video_memory = c;
  *(video_memory + 1) = cf;
}

void sclear() {
  for(int i=0; i<ROW; i++)
    for(int j=0; j<COL; j++)
      putc(i,j,' '); //screen clearing
}

void cinc() {
  if(cur->col == COL-1) {
    cnewline();
  } else cur->col++;
}

void cdec() {
  if(cur->col == 0) {
    cur->col = COL;
    cur->row--;
  } else cur->col--;
}

void printf(char *string, char format) { //print function
  while(*string != '\0') {
    if(*string == '\n') cnewline();
    else {
      putcf(cur->row, cur->col, *string, format);
      cinc();
    }
    string++;
  }
}

void print(char *string) {
  printf(string, DEFAULT_FORMAT);
}

void cnewline() {
  cur->col = 0;
  if(cur->row+1 != ROW)
    cur->row++;
  else scrollup(1);
  
}

void scrollup(int lines) {
  u16int* video_memory = (u16int*) VIDEO_MEMORY_START;

  u8int attributeByte = (0 << 4) | (15 & 0x0F);
  u16int blank = 0x20 | (attributeByte << 8);

  for(int j=0; j<lines; j++) {
    for (int i = 0*80; i < 24*80; i++) {
      video_memory[i] = video_memory[i+80];
    }

    for (int i=24*80; i<25*80; i++) {
      video_memory[i] = blank;
    }
  }
}

void scrolldown(int lines) {
  u16int* video_memory = (u16int*) VIDEO_MEMORY_START;

  u8int attributeByte = (0 << 4) | (15 & 0x0F);
  u16int blank = 0x20 | (attributeByte << 8);

  for(int j=0; j<lines; j++) {
    for (int i = 24*80-1; i >= 0; i--) {
      video_memory[i+80] = video_memory[i];
    }

    for (int i=0; i<80; i++) {
      video_memory[i] = blank;
    }
  }
}
