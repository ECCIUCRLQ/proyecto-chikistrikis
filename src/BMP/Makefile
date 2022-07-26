all:
	nasm -f elf64 -o Increment_brightness.o Increment_brightness.asm 
	nasm -f elf64 -o Inverse_colors.o Inverse_colors.asm
	g++ -no-pie main.c BMP.c Increment_brightness.o Inverse_colors.o -o program
clean:
	rm ./program
	rm ./Increment_brightness.o
	rm ./Inverse_colors.o
	

