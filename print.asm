setup_segment:
	mov cx, 0x07c0 ;shiftato a sinistra, originale 0x7c00
	mov ds, cx
	ret

print:
	mov ah, 0x0e
print_loop:
	mov al, [bx]
	cmp al, 0
	je print_end
	  
	mov al, [bx]
	int 0x10
	inc bx
	jmp print_loop

println:
	call print
newline:
	mov al, 10
	int 0x10   ;accapo
	mov al, 13
	int 0x10
	ret
  
print_end ret