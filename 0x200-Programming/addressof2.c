#include <stdio.h>
int main()
{	
	int int_var = 5;
	int *int_ptr;

	int_ptr = &int_var;

	printf(" int_ptr = %p\n", (void*)int_ptr);
	printf("&int_ptr = %p\n", (void*)&int_ptr);
	printf("*int_ptr = %d\n\n", *int_ptr);

	printf("int_var is located at %p and contains %d\n", (void*)&int_var, int_var);
	printf("int_ptr is located at %p, contains %p, and points to %d\n\n",	
			(void*) &int_ptr, (void*)int_ptr, *int_ptr);

	return 0;
}
