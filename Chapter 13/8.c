#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 80

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s [character] [opational:filenames]\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	FILE* fptr;
	char target = argv[1][0], ch;
	int count = 0;
	if(argc < 3)
	{
		char path[SLEN];
		while(1)
		{
			count = 0;
			printf("Enter file path(EOF to quit)\n");
			if(scanf("%s", path) == 1)
			{
				fptr = fopen(path, "r");
				if(fptr == NULL)
				{
					printf("Can't open %s\n", path);
					continue;
				}
				while((ch = getc(fptr)) != EOF)
				{
					if(ch == target)
						count++;
				}
				printf("%d %c(s) found in file %s\n", count, target, path);
				fclose(fptr);
			}
			else
				break;
		}
	}
	else
	{
		for (int i = 2; i < argc; ++i)
		{
			count = 0;
			fptr = fopen(argv[i], "r");
			if(fptr == NULL)
			{
				printf("Can't open %s\n", argv[i]);
				continue;
			}
			while((ch = getc(fptr)) != EOF)
			{
				if(ch == target)
					count++;
			}
			printf("%d %c(s) found in file %s\n", count, target, argv[i]);
			fclose(fptr);
		}
	}
	printf("Done\n");
	return 0;
}