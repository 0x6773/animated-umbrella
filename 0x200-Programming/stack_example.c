#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
void test_function(int a, int b, int c, int d)
{
	int flag;
	char buffer[10];

	flag = 31337;
	buffer[0] = 'A';
}
int main()
{
	test_function(1, 2, 3, 4);
	return 0;
}
#pragma GCC diagnostic pop
