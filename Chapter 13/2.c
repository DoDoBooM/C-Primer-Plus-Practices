#include <stdio.h>
#include <stdlib.h>
#define SIZE 1024
int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s [source filename] [destination filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	char* srcPath = argv[1];
	FILE* srcFile = fopen(srcPath, "r");
	if(srcFile == NULL)
	{
		printf("Can't open %s\n", srcPath);
		exit(EXIT_FAILURE);
	}
	char* destPath = argv[2];
	FILE* destFile = fopen(destPath, "w");
	if(destFile == NULL)
	{
		printf("Can't open %s\n", destPath);
		exit(EXIT_FAILURE);
	}
	char buffer[SIZE];
	size_t size = 0;
	while((size = fread(buffer, sizeof(char), SIZE, srcFile)) != 0)
	{
		fwrite(buffer, sizeof(char), size, destFile);
	}
	//fwrite(buffer, sizeof(char), SIZE, destFile);
	fclose(srcFile);
	fclose(destFile);
	printf("Done\n");
	return 0;
}