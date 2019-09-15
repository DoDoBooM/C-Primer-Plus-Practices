#include <stdio.h>
#include <stdlib.h>

static int rollem(int sides)
{
	int roll;
	roll = rand() % sides + 1;
	return roll;
}
int roll_n_dice(int dice, int sides)
{
	if(sides < 2)
	{
		printf("Need at least 2 sides.\n");
		return -2;
	}
	if(dice < 1)
	{
		printf("Need at least 1 dice.\n");
		return -1;
	}
	int total = 0;
	for (int i = 0; i < dice; ++i)
		total += rollem(sides);
	return total;
}