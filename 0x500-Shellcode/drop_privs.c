#include <unistd.h>
#include <string.h>
void lowered_privilege_function(unsigned char *ptr)
{
	char buffer[50];
	seteuid(0);
	strcpy(buffer, ptr);
}
int main(int argc, char *argv[])
{
	if(argc > 1)
		lowered_privilege_function(argv[1]);
}
