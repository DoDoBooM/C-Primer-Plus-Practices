#include <stdio.h>
double min(double, double);
void chline(char, int, int);
double harmonicmean(double, double);
int main(int argc, char* argv[])
{
	//printf("%g\n", min(6.23, 4.321));
	//chline('*', 5, 5);
	printf("%g\n", harmonicmean(6.23, 4.321));
	return 0;
}

double min(double v1, double v2)
{
	return v1 <= v2 ? v1 : v2;
}

void chline(char ch, int col, int row)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			putchar(ch);
		}
		putchar('\n');
	}
}
double harmonicmean(double v1, double v2)
{
	double reciprocal1 = v1 == 0 ? 0 : 1 / v1;
	double reciprocal2 = v2 == 0 ? 0 : 1 / v2;
	double result = (reciprocal1 + reciprocal2) == 0 ? 0 : 1 / ((reciprocal1 + reciprocal2) / 2);
	return result;
}
