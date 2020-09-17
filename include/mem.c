void rmemshift(u8int* start, u32int len, u32int shift) {
  rmemshiftf(start, len, shift, DEFAULT_FILLER);
}

void lmemshift(u8int* start, u32int len, u32int shift) {
  lmemshiftf(start, len, shift, DEFAULT_FILLER);
}

void rmemshiftf(u8int* start, u32int len, u32int shift, u8int filler) {
  for(u32int j=0; j<shift; j++) {
    for(u32int i=len-1; i>0; i--)
      *(start+i+1) = *(start+i);
    *start = filler;
  }
}

void lmemshiftf(u8int* start, u32int len, u32int shift, u8int filler) {
  for(u32int j=0; j<shift; j++) {
    for(u32int i=1; i<len; i++)
      *(start+i-1) = *(start+i);
    *(start+len-1) = filler;
  }
}
