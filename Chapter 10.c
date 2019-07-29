#include <stdio.h>
#define MONTHS 12
#define YEARS 5
#define COL 5
void No_1();
void No_2();
void copy_arr(double[], double[], int);
void copy_ptr(double[], double[], int);
void copy_ptrs(double*, double*, double*);
int max(int[], int);
int maxIndex(double[], int);
double maxDiff(double[], int);
void sortInverse(double[], int);
void copy_2D_vla(int, int, double[*][*], double[*][*]);
void print_2D_vla_double(int, int, double[*][*]);
void array_add(int[], int[], int[], int);
void two_times_array(int[][COL], int);
void print_2D_int(int, int, int[*][*]);
void rain_every_year( const float [YEARS][MONTHS] );
void rain_every_month( const float [YEARS][MONTHS] );
void No_13_14();
void get_element(int, int, int [*][*] );
void get_average_per_row(int, int, int [*][*]);
float get_average(int, int, int [*][*]);
int get_max(int, int, int [*][*]);
int main(int argc, char *argv[])
{
	//No_1();

	//No_2();

	// int arr[5] = { 1, 2, 3, 4, 5 };
	// printf("%d\n", max(arr, 5));

	// double arr[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	// printf("%d\n", maxIndex(arr, 5));

	// double arr[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	// printf("%lf\n", maxDiff(arr, 5));

	// double arr[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	// sortInverse(arr, 5);
	// for (int i = 0; i < 5; ++i)
	// 	printf("%lf\t", arr[i]);

	//No.7
	// double source[3][3] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
	// double target[3][3];
	// for (int i = 0; i < 3; ++i)
	// {
	// 	copy_arr(target[i], source[i], 3);
	// 	for (int j = 0; j < 3; ++j)
	// 		printf("%lf\t", source[i][j]);
	// 	printf("\n");
	// }

	//No.8
	// double source[7] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	// double target[3];
	// copy_ptr(target, source + 2, 3);
	// for (int i = 0; i < 3; ++i)
	// {
	// 	printf("%lf\t", target[i]);
	// }

	// double source[3][3] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
	// double target[3][3];
	// copy_2D_vla( 3, 3, target, source );
	// printf("Print source array\n");
	// print_2D_vla_double( 3, 3, source );
	// printf("Print target array\n");
	// print_2D_vla_double( 3, 3, target);

	// int arr1[4] = { 2, 4, 5, 8 };
	// int arr2[4] = { 1, 0, 4, 6 };
	// int arr3[4];
	// array_add(arr3, arr1, arr2, 4);
	// for (int i = 0; i < 4; ++i)
	// 	printf("%d\t", *(arr3 + i) );


	// int arr[3][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	// two_times_array(arr, 3);
	// print_2D_int(3, COL, arr);

	No_13_14();
	return 0;
}
//No.1 NO.12
void No_1()
{
	const float rain[YEARS][MONTHS] =
	{
		{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
		{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
		{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
		{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
		{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
	};
	rain_every_year(rain);
	rain_every_month(rain);
	
}

void rain_every_year(const float rain[YEARS][MONTHS] )
{
	printf("YEAR    RAINFALL    (inches)\n");
	int year, month;
	float subtot, total;
	for (year = 0, total = 0; year < YEARS; year++)
	{
		for (month = 0, subtot = 0; month < MONTHS; month++)
			subtot += *(*(rain + year) + month);
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;
	}
	printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
}

void rain_every_month(const float rain[YEARS][MONTHS] )
{
	int year, month;
	float subtot;

	printf("MONTHLY AVERAGE:\n\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtot = 0; year < YEARS; year++)
			subtot += *(*(rain + year) + month);
		printf("%4.1f", subtot / YEARS);
	}
	printf("\n");
}

//No.2
void No_2()
{
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5];
	double target2[5];
	double target3[5];
	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);
	printf("source  target1  target2  target3\n");
	for (int i = 0; i < 5; ++i)
	{
		printf("%5.1lf    %5.1lf    %5.1lf    %5.1lf\n", source[i], target1[i], target2[i], target3[i]);
	}
}
void copy_arr(double target[], double source[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		target[i] = source[i];
	}
}
void copy_ptr(double target[], double source[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		*(target + i) = *source++;
	}
}
void copy_ptrs(double* target, double* source, double* sEnd)
{
	while (source < sEnd)
	{
		*target++ = *source++;
	}
}

//No.3
int max(int arr[], int len)
{
	int maxVal = arr[0];
	for (int i = 1; i < len; ++i)
	{
		maxVal = maxVal > arr[i] ? maxVal : arr[i];
	}
	return maxVal;
}

//No.4
int maxIndex(double arr[], int len)
{
	int maxIndex = 0;
	for (int i = 0; i < len; ++i)
	{
		maxIndex = arr[maxIndex] > arr[i] ? maxIndex : i;
	}
	return maxIndex;
}

//No.5
double maxDiff(double arr[], int len)
{
	double minVal = arr[0];
	double maxVal = arr[0];
	for (int i = 0; i < len; ++i)
	{
		minVal = minVal < arr[i] ? minVal : arr[i];
		maxVal = maxVal > arr[i] ? maxVal : arr[i];
	}
	return maxVal - minVal;
}

//No.6 Bubble Sort
void sortInverse(double arr[], int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				double temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//No.9
void copy_2D_vla(int row, int col, double target[row][col], double source[row][col])
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			target[i][j] = source[i][j];
		}
	}
}
void print_2D_vla_double(int row, int col, double arr[row][col])
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%lf\t", arr[i][j]);
		}
		printf("\n");
	}
}

//No.10
void array_add(int target[], int arr1[], int arr2[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		target[i] = arr1[i] + arr2[i];
	}
}

//No.11
void two_times_array(int arr[][COL], int row)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			arr[i][j] *= 2;
		}
	}
}
void print_2D_int(int row, int col, int arr[row][col])
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}
//No.13 No.14
void No_13_14()
{
	int row, col;
	printf("Enter row and column of the array.\n");
	scanf("%d %d", &row, &col);
	int array[row][col];
	get_element(row, col, array);
	printf("Average of array is %f\n", get_average(row, col, array));
	printf("Max num in array is %d\n", get_max(row, col, array));
}

void get_element( int row, int col, int array[row][col] )
{
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			printf("\nEnter the integer at row %d column %d.\n", r, c);
			scanf("%d", &array[r][c]);
		}
	}
}
void get_average_per_row( int row, int col, int array[row][col] )
{
	for (int r = 0, sum; r < row; ++r)
	{
		for (int c = 0, sum = 0; c < col; ++c)
		{
			sum += array[r][c];
		}
		printf("Average at row %d is %f\n", r, (float)sum / col);
	}
}
float get_average( int row, int col, int array[row][col] )
{
	int sum = 0;
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			sum += array[r][c];
		}
	}
	float average = (float)sum / (col * row);
	return average;
}
int get_max( int row, int col, int array[row][col] )
{
	int max = array[0][0];
	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			max = max > array[r][c] ? max : array[r][c];
		}
	}
	return max;
}
