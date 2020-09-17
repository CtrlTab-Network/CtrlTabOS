;start settore 1
[org 0x7c00]

mov [BOOT_DRIVE], dl

mov bp, 0x7c00
mov sp, bp

mov bx, INITIALIZING
call println

mov bx, LOADING_KERNEL
call println

mov dh, 15
mov bx, 0x7e00
mov dl, [BOOT_DRIVE]
call disk_load

mov bx, KERNEL_LOADED
call println

mov bx, SWITCHING
call println

;cursor clearing
mov ah, 0x01
mov cx, 0x2607
int 0x10

call switch_to_pm

loop:
	jmp loop

%include "labels.asm"
%include "print.asm"
%include "disk_load.asm"
%include "gdt.asm"
%include "protected_mode.asm"
%include "src32.asm"

BOOT_DRIVE db 0

times 510 -( $ - $$ ) db 0
dw 0xaa55
