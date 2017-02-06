#include <stdio.h>
#include <string.h>
#define bool int
#define true 1
#define false 0

int main(int argc, char const *argv[])
{
	bool n = false;
	short min = 1;
	// Test auf -n als erste Option
	if (argc > 1 && 0 == strncmp("-n", argv[1], 2)) 
	{
		n = true;
		min = 2;
	}
	for (int i = min; i < argc; ++i)
	{
		printf("%s", argv[i]);
		if (i != (argc - 1))
		{
			printf(" ");
		}
	}
	if (!n) 
		printf("\n");
	return 0;
}