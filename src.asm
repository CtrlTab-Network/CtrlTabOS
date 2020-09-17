;start settore 1
[org 0x7c00]

mov [BOOT_DRIVE], dl

mov bp, 0x7c00
mov sp, bp

mov bx, INITIALIZING   ;print
call println

mov bx, LOADING_KERNEL ;print
call println

mov dh, 15             ;load 15 sectors
mov bx, 0x7e00 				 ;kernel address
mov dl, [BOOT_DRIVE]
call disk_load

mov bx, KERNEL_LOADED  ;print
call println

mov bx, SWITCHING      ;print
call println

;cursor clearing
mov ah, 0x01
mov cx, 0x2607
int 0x10

call switch_to_pm      ;switch to 32bit protected mode

loop:
	jmp loop

%include "./asm/real/labels.asm"
%include "./asm/real/print.asm"
%include "./asm/real/disk_load.asm"
%include "./asm/real/gdt.asm"
%include "./asm/protected/protected_mode.asm"
%include "./asm/protected/src32.asm"

BOOT_DRIVE db 0

times 510 -( $ - $$ ) db 0
dw 0xaa55  ;magic number
