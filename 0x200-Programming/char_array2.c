#include <stdio.h>
#include <string.h>
int main()
{
	char str_a[20];
	printf("Breakpoint\n");
	strcpy(str_a, "Hello world!\n");
	printf(str_a);


	return 0;
}
