[bits 32]

begin_pm:
  mov ebx, SWITCHED
  call print32
  jmp 0x7e00

%include "print32.asm"
