#include <stdio.h>
int func_one() 
{
	printf("This is function one\n");
	return 1;
}
int func_two() 
{
	printf("This is function two\n");
	return 2;
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
int main() 
{
	int value;
	int (*function_ptr) ();
	function_ptr = func_one;
	printf("function_ptr is %p\n", (void*) function_ptr);
	value = function_ptr();
	printf("value returned was %d\n", value);
	function_ptr = func_two;
	printf("function_ptr is %p\n", (void*) function_ptr);
	value = function_ptr();
	printf("value returned was %d\n", value);
}
#pragma GCC diagnostic pop
