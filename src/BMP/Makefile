all:
	nasm -f elf64 -o Increment_brightness.o Increment_brightness.asm 
	nasm -f elf64 -o Inverse_colors.o Inverse_colors.asm
	nasm -f elf64 -o Increment_saturation.o Increment_saturation.asm
	g++ -no-pie main.c BMP.c Increment_brightness.o Inverse_colors.o Increment_saturation.o -o program
clean:
	rm ./program
	rm ./Increment_brightness.o
	rm ./Inverse_colors.o
	rm ./Increment_saturation.o
	

