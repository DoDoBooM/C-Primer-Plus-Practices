#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s [filename1] [filename2]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	char* path1 = argv[1];
	FILE *file1 = fopen(path1, "r");
	if(file1 == NULL)
	{
		printf("Can't open %s\n", path1);
		exit(EXIT_FAILURE);
	}
	char* path2 = argv[2];
	FILE *file2 = fopen(path2, "r");
	if(file2 == NULL)
	{
		fclose(file1);
		printf("Can't open %s\n", path2);
		exit(EXIT_FAILURE);
	}
	int count = 0;
	char ch1 = getc(file1);
	char ch2 = getc(file2);

	while(1)
	{
		while(ch1 != EOF)
		{
			putc(ch1, stdout);
			if(ch1 == '\n')
			{
				ch1 = getc(file1);
				break;
			}
			ch1 = getc(file1);
		}
		while(ch2 != EOF)
		{
			putc(ch2, stdout);
			if(ch2 == '\n')
			{
				ch2 = getc(file2);
				break;
			}
			ch2 = getc(file2);
		}
		if(ch1 == EOF && ch2 == EOF)
		{
			break;
		}
	}
	fclose(file1);
	fclose(file2);
	printf("Done\n");
	return 0;
}