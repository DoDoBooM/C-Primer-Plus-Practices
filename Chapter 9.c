#include <stdio.h>
double min(double, double);
void chline(char, int, int);
double harmonicmean(double, double);
void lager_of(double*, double*);
void swap(double*, double*, double*);
void reporter();
int getcharpos(char);
double power(double, int);
double powerrecursive(double, int);
void recursive(double, int, double*);
void to_base_n(unsigned, unsigned short);
unsigned long Fibonacci(unsigned);
int main(int argc, char* argv[])
{
	double v1 = 6.23, v2 = 4.321, v3 = 3.48;

	//printf("%g\n", min(v1, v2));

	//chline('*', 5, 5);

	//printf("%g\n", harmonicmean(v1, v2));

	// lager_of(&v1, &v2);
	// printf("%g\t%g\n", v1, v2);

	// swap(&v1, &v2, &v3);
	// printf("%g\t%g\t%g\n", v1, v2, v3);

	//reporter();

	//printf("%g\n", power(0, -1));

	//printf("%g\n", powerrecursive(2, -1));

	//to_base_n(255, 2);

	//printf("%ld\n", Fibonacci(50));
	return 0;
}
//No.1
double min(double v1, double v2)
{
	return v1 <= v2 ? v1 : v2;
}
//No.2 No.3
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
//No.4
double harmonicmean(double v1, double v2)
{
	double reciprocal1 = v1 == 0 ? 0 : 1 / v1;
	double reciprocal2 = v2 == 0 ? 0 : 1 / v2;
	double result = (reciprocal1 + reciprocal2) == 0 ? 0 : 1 / ((reciprocal1 + reciprocal2) / 2);
	return result;
}
//No.5
void lager_of(double* v1, double* v2)
{
	*v1 = (*v1 >= *v2) ? *v1 : *v2;
	*v2 = *v1;
}
//No.6
void swap(double* v1, double* v2, double* v3)
{
	double temp;
	if(*v1 >= *v2)
	{
		temp = *v1;
		*v1 = *v2;
		*v2 = temp;
	}

	if(*v3 < *v2)
	{
		if(*v3 < *v1)
		{
			temp = *v3;
			*v3 = *v2;
			*v2 = *v1;
			*v1 = temp;
		}
		else
		{
			temp = *v3;
			*v3 = *v2;
			*v2 = temp;
		}
	}
}
//No.7
void reporter()
{
	char ch;
	while((ch = getchar()) != EOF)
	{
		if(ch == '\n')
			continue;
		int pos = getcharpos(ch);
		if(pos == -1)
		{
			printf("This is not a alphabet\n");
		}
		else
		{
			printf("The position of this character in alphabet is %d\n", pos);
		}
	}
}
int getcharpos(char ch)
{
	if(ch >= 'a' && ch <='z')
	{
		return ch - 'a' + 1;
	}
	else if(ch >= 'A' && ch <= 'Z')
	{
		return ch - 'A' + 1;
	}
	else
	{
		return -1;
	}
}
//No.8
double power(double n, int p)
{
	if(p == 0)
	{
		if(n == 0)
		{
			printf("The 0 power of 0 is not defined.\n");
		}
		return 1.0;
	}
	if(n == 0)
	{
		if(p < 0)
		{
			printf("The negative power of 0 is not defined.\n");
		}
		return 0;
	}
	int isNegP = p < 0;
	if(isNegP)
	{
		p *= -1;
	}
	double pow = 1;
	for (int i = 1; i <= p; ++i)
	{
		pow *= n;
	}
	return isNegP ? (1 / pow) : pow;
}
//No.9
double powerrecursive(double n, int p)
{
	if(p == 0)
	{
		if(n == 0)
		{
			printf("The 0 power of 0 is not defined.\n");
		}
		return 1.0;
	}
	if(n == 0)
	{
		if(p < 0)
		{
			printf("The negative power of 0 is not defined.\n");
		}
		return 0;
	}
	int isNegP = p < 0;
	if(isNegP)
		p *= -1;
	double pow = 1;
	recursive(n, p, &pow);
	return isNegP ? (1 / pow) : pow;
}

void recursive(double n, int p, double *pow)
{
	*pow *= n;
	p--;
	if(p > 0)
	{
		recursive(n, p, pow);
	}
}
//No.10
void to_base_n(unsigned num, unsigned short base)
{
	unsigned long result = 0;
	unsigned long i = 0;
	while(num > 0)
	{
		result += ((num % base) * (unsigned long)power(10, i));
		num /= base;
		i++;
	}
	printf("%ld\n", result);
}


//No.11
unsigned long Fibonacci(unsigned n)
{
	unsigned long a = 0;
	unsigned long b = 1;
	unsigned long c = 1;
	for (int i = 3; i <= n; ++i)
	{
		a = b;
		b = c;
		c = a + b;
	}
	return c;
}
