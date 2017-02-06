#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define null NULL

bool strHasNewLine(const char *str);

int main(int argc, char const *argv[])
{
	FILE *fp;
	char *line = null;
	size_t len = 0;
	ssize_t read;
	bool nl = false;

	for (int i = 1; i < argc; ++i)
	{
		if (strcmp("-", argv[i]) == 0) 
		{
			fp = stdin;
		}
		else 
		{
			fp = fopen(argv[i], "r");

			if (null == fp) 
			{
				printf("%s: %s: No such file or directory\n", argv[0], argv[i]);
				exit(EXIT_FAILURE);
			}
		}

		while ((read = getline(&line, &len, fp)) != -1) 
		{
			printf("%s", line);
			nl = strHasNewLine(line);
			if (line) {
				free(line);
				line = null;
			}
		}

		fclose(fp);

		if (!nl)
			printf("\n");
	}
	exit(EXIT_SUCCESS);
}

bool strHasNewLine(const char *str) 
{
	return (str && *str && str[strlen(str) - 1] == '\n');
}