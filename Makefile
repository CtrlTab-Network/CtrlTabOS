all: os-image.bin

clean:
	rm -fr *.bin *.dis *.o os-image.bin *.map

run: clean all
	cmd.exe /c "D:\\Program Files\\Bochs-2.6.11\\bochs.exe"

boot_sect.bin : src.asm
	nasm $< -f bin -o $@

kernel_entry.o : kernel_entry.asm
	nasm $< -f elf32 -o $@

kernel.o : kernel.c
	gcc -m32 -I include -fno-pie -ffreestanding -c $< -o $@

kernel.bin : kernel_entry.o kernel.o
	ld -m elf_i386 -o $@ -Ttext 0x7e00 $^ --oformat binary

os-image.bin : boot_sect.bin kernel.bin
	cat $^ > $@
