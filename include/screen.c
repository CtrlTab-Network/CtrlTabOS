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
    cur->col = 0;
    cur->row++;
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
  cur->row++;
}
