[bits 32]

begin_pm:
  mov ebx, SWITCHED
  call print32
  jmp 0x7e00 ;jump to kernel address

%include "./asm/protected/print32.asm"
