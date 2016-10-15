#include <stdio.h>
int main()
{
	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	int int_array[5] = {1, 2, 3, 4, 5};

	unsigned long hacky_nonpointer;

	hacky_nonpointer = (unsigned long) char_array;
	
	for(int i = 0; i < 5; ++i)
	{
		printf("[hacky_nonpointer] points to %p, which contains the char '%c'\n", (void*)hacky_nonpointer, *((char*)hacky_nonpointer));
		hacky_nonpointer = hacky_nonpointer + sizeof(char);
	}

	hacky_nonpointer = (unsigned long) int_array;

	for(int i = 0; i < 5; ++i)
	{
		printf("[hacky_nonpointer] points to %p, which contains the integer %d\n", (void*)hacky_nonpointer, *((int*)hacky_nonpointer));		
		hacky_nonpointer = hacky_nonpointer + sizeof(int);
	}

	return 0;
}
