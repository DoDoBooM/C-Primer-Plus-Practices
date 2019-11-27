#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define PATHLEN 50
int main(int argc, char* argv[])
{
	printf("Enter file path.\n");
	char path[PATHLEN];
	if(scanf("%s",path) != 1)
	{
		fprintf(stderr, "Invalid input.\n");
		exit(EXIT_FAILURE);
	}
	FILE* fpr = fopen(path, "r");
	FILE* fpw = fopen(path, "w");
	char ch;
	while((ch = getc(fpr)) != EOF)
	{
		fputc(ch, fpw);
	}
	fclose(fpr);
	fclose(fpw);
	return 0;
}