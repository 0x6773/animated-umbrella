
default : all

all : 
	for file in `find -name '*.c'|cut -c 3-|sort`; do 							\
		echo " [+] GCC  $$file -o $$file.out";												\
		gcc -O0 -g -Wall -Wextra -pedantic -m32 $$file -o $$file.out;	\
	done;																														\
	for file in `find -name '*.asm'|cut -c 3-|sort`; do							\
		echo " [+] NASM $$file -o $$file.o";													\
		nasm -f elf $$file -o $$file.o; 															\
		echo " [+] LD   $$file.o -o $$file.out";											\
		ld -m elf_i386 $$file.o -o $$file.out;												\
	done;																														\
	rm -rf *.o
clean :
	rm -rf *.out
	rm -rf *.o
