#include <stdio.h>
int main()
{
	char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	int int_array[5] = {1, 2, 3, 4, 5};

	char *char_pointer;
	int *int_pointer;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

	char_pointer = int_array;
	int_pointer = char_array;

#pragma GCC diagnostic pop

	for(int i = 0; i < 5; ++i)
	{
		printf("[integer pointer] points to %p, which contains the char '%c'\n", (void*)int_pointer, *int_pointer);
		int_pointer = int_pointer + 1;
	}

	for(int i = 0; i < 5; ++i)
	{
		printf("[char pointer] points to %p, which contains the integer %d\n", (void*)char_pointer, *char_pointer);
		char_pointer = char_pointer + 1;
	}

	return 0;
}
