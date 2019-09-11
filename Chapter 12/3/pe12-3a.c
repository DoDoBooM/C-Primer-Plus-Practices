#include <stdio.h>

void set_mode(int *mode, int preMode)
{
	if(*mode != 1 && *mode != 0)
	{
		printf("Invalid mode specified. Mode %d(%s) used.\n", preMode, preMode == 0 ? "metric" :"US");
		*mode = preMode;
	}
}

void get_info(int mode, float* distance, float* fuel)
{
	if(mode)//metric
	{
		printf("Enter distance traveled in kilometers:");
		while(scanf("%f", distance) != 1 || *distance == 0)
		{
			printf("Invalid input. Enter again.\n");
		}
		printf("Enter fuel consumed in liters:");
		while(scanf("%f", fuel) != 1 || *fuel == 0)
		{
			printf("Invalid input. Enter again.\n");
		}
	}
	else//US
	{
		printf("Enter distance traveled in miles:");
		while(scanf("%f", distance) != 1 || *distance == 0)
		{
			printf("Invalid input. Enter again.\n");
		}
		printf("Enter fuel consumed in gallons:");
		while(scanf("%f", fuel) != 1 || *fuel == 0)
		{
			printf("Invalid input. Enter again.\n");
		}
	}
}

void show_info(int mode, float distance, float fuel)
{
	if(mode)//metric
	{
		printf("Fuel consumption is %.2f liters per 100 km.\n", fuel / (distance / 100));
	}
	else//US
	{
		printf("Fuel consumption is %.2f miles per gallon.\n", distance / fuel);
	}
}