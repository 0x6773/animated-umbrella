#include <stdio.h>
int main(int argc, char* argv[])
{
	printf("There was %d arguments provided : \n", argc);
	for(int i = 0; i < argc; ++i)
		printf("argument #%d\t-\t%s\n", i, argv[i]);
	return 0;
}
