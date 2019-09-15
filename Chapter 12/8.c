#include <stdio.h>
#include <stdlib.h>
int* make_array(int elem, int val);
void show_array(const int arr[], int n);
int main(int argc, char* argv[])
{
	int *pa;
	int size;
	int value;
	printf("Enter the number of elements: ");
	while(scanf("%d", &size) == 1 && size > 0)
	{
		printf("Enter the initialization value: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if(pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements (<1 to quit): ");
	}
	printf("Done.\n");
	return 0;
}
int* make_array(int elements, int value)
{
	int* ptr = (int*)malloc(elements * sizeof(int));
	if(ptr)
	{
		for (int i = 0; i < elements; ++i)
		{
			ptr[i] = value;
		}
	}
	return ptr;
}
void show_array(const int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
		if(i > 6 && i % 7 == 0)
			printf("\n");
	}
	printf("\n");
}