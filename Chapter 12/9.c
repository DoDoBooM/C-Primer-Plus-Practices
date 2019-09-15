#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LIM 1000
char* GetWord(char* str, int* index);
int main(int argc, char* argv[])
{
	int wordsCount;
	printf("How many words do you wish to enter? ");
	if(scanf("%d", &wordsCount) == 1 && wordsCount > 0)
	{
		printf("Enter %d wrods now:\n", wordsCount);
		char str[LIM];
		char**words = (char**)malloc(wordsCount * sizeof(char*));
		if(words == NULL)
			return -1;
		while(getchar() != '\n')
			continue;
		if(fgets(str, LIM, stdin) == NULL)
			goto Done;
		char* temp[wordsCount];
		int index = 0;
		int size = 0;
		for (int i = 0; i < wordsCount; ++i)
		{
			words[i] = GetWord(str, &index);
		}
		printf("Here are your words:\n");
		for (int i = 0; i < wordsCount; ++i)
		{
			printf("%s\n", words[i]);
		}
		free(words);
	}
	Done:printf("Done\n");
	return 0;
}
char* GetWord(char* str, int* index)
{	
	char* word = NULL;
	while(str[*index] != '\0')
	{
		if(isalpha(str[*index]))
		{
			if(!word)
			{
				word = str + *index;
			}
		}
		else
		{
			if(word)
			{
				str[*index] = '\0';
				(*index)++;
				break;
			}
		}
		(*index)++;
	}
	return word;
}