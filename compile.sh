nasm src.asm -f bin -o boot_sect.bin
nasm kernel_entry.asm -f elf32 -o kernel_entry.o

gcc -m32 -fno-pie -ffreestanding -c kernel.c -o kernel.o

ld -m elf_i386 -o kernel.bin -Ttext 0x7e00 kernel_entry.o kernel.o --oformat binary
cat boot_sect.bin kernel.bin > os-image.bin
