[bits 32]
                         ; Define some constants
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x07
                         ; prints a null - terminated string pointed to by EDX
print32:
  pusha ;kekko
  mov edx, VIDEO_MEMORY  ; Set edx to the start of vid mem.
print32_loop:
  mov al, [ebx]          ; Store the char at EBX in AL
  mov ah, WHITE_ON_BLACK ; Store the attributes in AH
  cmp al, 0              ; if (al == 0) , at end of string , so
  je print32_end         ; jump to print32_end
  mov [edx], ax          ; Store char and attributes at current
                         ; character cell.
  add ebx, 1             ; Increment EBX to the next char in string.
  add edx, 2             ; Move to next character cell in vid mem.
  jmp print32_loop       ; loop around to print the next char.
print32_end:
  popa
  ret                    ; Return from the function