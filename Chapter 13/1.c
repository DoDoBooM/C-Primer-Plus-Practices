#include <stdio.h>
#include <stdlib.h>
#define PATHLEN 50
int main(int argc, char* argv[])
{
	char path[PATHLEN];
	printf("Enter file path: ");
	if(scanf("%s", path) != 1)
	{
		printf("Invalid path!\n");
		exit(EXIT_FAILURE);
	}
	FILE* fp = fopen(path, "r");
	if(fp == NULL)
	{
		printf("Can't open %s.\n", path);
		exit(EXIT_FAILURE);
	}
	char ch;
	unsigned long count = 0;
	while((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", path, count);
	return 0;
}