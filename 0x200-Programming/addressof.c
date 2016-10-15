#include <stdio.h>
int main()
{
	int int_var = 5;
	int *int_ptr;

	int_ptr = &int_var;

	printf("%d", *int_ptr);
		
	return 0;	
}
