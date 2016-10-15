#include <stdio.h>
int main()
{
	printf("The 'int' data type is\t\t %d bytes\n", (int)sizeof(int));
	printf("The 'unsigned int' data type is\t %d bytes\n", (int)sizeof(unsigned int));
	printf("The 'short int' data type is\t %d bytes\n", (int)sizeof(short int));
	printf("The 'long int' data type is\t %d bytes\n", (int)sizeof(long int));
	printf("The 'long long int' data type is %d bytes\n", (int)sizeof(long long int));
	printf("The 'float' data type is\t %d bytes\n", (int)sizeof(float));
	printf("The 'double' data type is\t %d bytes\n", (int)sizeof(double));
	printf("The 'long double' data type is\t %d bytes\n", (int)sizeof(long double));
	printf("The 'char' data type is\t\t %d bytes\n", (int)sizeof(char));
	return 0;
}
