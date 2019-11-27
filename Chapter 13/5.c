#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096

void Append(FILE*, FILE*);
int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		fprintf(stderr, "Usage: %s [filename1] [filename2]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if(strcmp(argv[1], argv[2]) == 0)
	{
		fprintf(stderr, "Can't append file to itself.\n");
		exit(EXIT_FAILURE);
	}
	FILE *fsrc = fopen(argv[1], "r");
	if (fsrc == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	FILE *fdest = fopen(argv[2], "a+");
	if (fdest == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(fsrc);
		exit(EXIT_FAILURE);
	}
	fseek(fsrc, 0L, SEEK_SET);
	fseek(fdest, 0L, SEEK_END);
	Append(fsrc, fdest);
	if(ferror(fsrc) != 0)
		fprintf(stderr, "Error in reading file %s\n", argv[1]);
	if(ferror(fdest) != 0)
		fprintf(stderr, "Error in writing file %s\n", argv[2]);
	fclose(fsrc);
	fclose(fdest);
	printf("Done\n");
	return 0;
}

void Append(FILE* src, FILE* dest)
{
	size_t bytes;
	static char temp[BUFSIZE];
	while((bytes = fread(temp, sizeof(char), BUFSIZE, src)) > 0)
	{
		printf("bytes is %zu", bytes);
		fwrite(temp, sizeof(char), bytes, dest);
	}
	fflush(dest);
}