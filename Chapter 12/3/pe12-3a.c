#include <stdio.h>

void set_mode(int *mode, int preMode)
{
	if(*mode != 1 && *mode != 0)
	{
		printf("Invalid mode specified. Mode %d(%s) used.\n", preMode, preMode == 0 ? "metric" :"US");
		*mode = preMode;
	}
}
void get_info(int mode)
{
	if(mode)//metric
	{
		printf("Enter distance traveled in kilometers:");
		while(scanf("%f", &_distance) != 1 || _distance == 0)
		{
			printf("Invalid input. Enter again.\n");
		}
		printf("Enter fuel consumed in liters:");
		while(scanf("%f", &_fuel) != 1 || _fuel == 0)
		{
			printf("Invalid input. Enter again.\n");
		}
	}
	else//US
	{
		printf("Enter distance traveled in miles:");
		while(scanf("%f", &_distance) != 1 || _distance == 0)
		{
			printf("Invalid input. Enter again.\n");
		}
		printf("Enter fuel consumed in gallons:");
		while(scanf("%f", &_fuel) != 1 || _fuel == 0)
		{
			printf("Invalid input. Enter again.\n");
		}
	}
}
void show_info()
{
	if(!_mode)//metric
	{
		printf("Fuel consumption is %.2f liters per 100 km.\n", _fuel / (_distance / 100));
	}
	else//US
	{
		printf("Fuel consumption is %.2f miles per gallon.\n", _distance / _fuel);
	}
}