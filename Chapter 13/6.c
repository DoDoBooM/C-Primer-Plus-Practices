#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(int argc, char *argv[])
{
	int ch;
	char name[LEN];
	int count = 0;
	printf("Enter source file name:");
	if(scanf("%s", name) != 1)
	{
		fprintf(stderr, "Invalid input!\n");
		exit(EXIT_FAILURE);
	}
	FILE *in = fopen(name, "r");
	if(in == NULL)
	{
		fprintf(stderr, "Can't open %s\n", name);
		exit(EXIT_FAILURE);
	}
	printf("Enter destined file name:");
	if(scanf("%s", name) != 1)
	{
		fprintf(stderr, "Invalid input!\n");
		exit(EXIT_FAILURE);
	}
	FILE *out = fopen(name, "w");
	if(in == NULL)
	{
		fprintf(stderr, "Can't open %s\n", name);
		exit(EXIT_FAILURE);
	}
	while((ch = getc(in)) != EOF)
		if(count++ % 3 == 0)
			putc(ch, out);
	if(fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");
	printf("Done\n");
	return 0;
}