#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
	char ch;
	for (int i = 1; i < argc; ++i)
	{
		printf("-------------------------\n");
		FILE* fp = fopen(argv[i], "r");
		if(fp == NULL)
		{
			fprintf(stderr, "Can't open %s.\n", argv[i]);
			continue;
		}
		while((ch = getc(fp)) != EOF)
		{
			putchar(ch);
		}
		printf("%s\n", argv[i]);
		fclose(fp);
	}
	return 0;
}