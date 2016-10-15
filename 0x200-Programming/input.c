#include <stdio.h>
#include <string.h>
int main()
{
	char message[20];
	int count;

	strcpy(message, "Hello, world!");

	printf("Repeat how many times? ");
	scanf("%d", &count);

	for(int i = 0; i < count; ++i)
		printf("%3d - %s\n", i, message);
	
	return 0;
}
