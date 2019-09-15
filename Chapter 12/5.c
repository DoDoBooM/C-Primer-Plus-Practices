#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 100
int GetRandNumber();
void SelectionSort(int[]);
int main(int argc, char* argv[])
{
	srand((unsigned int)time(0));
	int arr[LEN];
	printf("index\t\tvalue\n");
	for (int i = 0; i < LEN; ++i)
	{
		arr[i] = GetRandNumber();
	}
	SelectionSort(arr);
	for (int i = 0; i < LEN; ++i)
	{
		printf("%5d\t\t%5d\n", i, arr[i]);
	}
	return 0;
}
int GetRandNumber()
{
	int number = rand() % 10 + 1;
	return number;
}
void SelectionSort(int num[])
{

	for (int i = 0, temp = 0; i < LEN - 1; ++i)
	{
		for (int j = i + 1; j < LEN; ++j)
		{
			if(num[i] < num[j])
			{
				temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}
		}
	}
}