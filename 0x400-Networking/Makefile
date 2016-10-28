
default : all

all : 
	for file in `find -name '*.c'|cut -c 3-|sort`; do                        \
		echo " [+] $$file -o $$file.out";	  \
		gcc -O0 -g -Wall -Wextra -pedantic -lpcap -m32 $$file -o $$file.out; \
	done

clean :
	rm -rf *.out
