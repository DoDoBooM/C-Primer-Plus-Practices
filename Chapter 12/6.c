#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 1000
int GetRandNumber();
int main(int argc, char* argv[])
{
	for (int i = 0; i < 10; ++i)
	{
		printf("Loop %d seed %u\n", i, i);
		srand(i);
		int* ptr = (int*)calloc(10, LEN * sizeof(int));
		for (int i = 0; i < LEN; ++i)
		{
			ptr[GetRandNumber()]++;
		}
		printf("value\t\tcount\n");
		for (int i = 0; i < 10; ++i)
		{
			printf("%5d\t\t%5d\n", i, ptr[i]);
		}
		free(ptr);
		printf("==============================\n");
	}
	return 0;
}
int GetRandNumber()
{
	int number = rand() % 10 + 1;
	return number;
}