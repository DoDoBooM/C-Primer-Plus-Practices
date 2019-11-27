#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(int argc, char *argv[])
{
	FILE *fp;
	char words[MAX];
	if((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	int count = 0;
	char ch;
	rewind(fp);
	while((ch = getc(fp)) != EOF)
	{
		if(ch == '\n')
			count++;
	}
	printf("Current words count is %d\n", count);
	puts("Enter words to add to the file; press the #\nkey at the beginning of a line to terminate.");
	while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%d-%s\n", ++count, words);
	puts("File contents:");
	rewind(fp);
	while(fscanf(fp, "%s\n", words) == 1)
		puts(words);
	puts("Done!");
	if(fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");
	return 0;
}