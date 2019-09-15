#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(int argc, char* argv[])
{
	printf("Enter the number of sets; enter q to stop :");
	int sets, sides, dice, status;
	while(scanf("%d", &sets) == 1 && sets > 0)
	{
		printf("How many sides and how many dice?");
		if((status = scanf("%d %d", &sides, &dice)) != 2)
		{
			if(status == EOF)
				break;
			else
			{
				printf("You should have entered two integers.\n");
				printf("Let's begin again!\n");
				while(getchar() != '\n')
					continue;
				printf("Enter the number of sets; enter q to stop :");
				continue;
			}
		}
		printf("Here are %d sets, of %d %d-sided throws.\n", sets, dice, sides);
		for (int i = 0; i < sets; ++i)
		{
			printf("%d ", roll_n_dice(dice, sides)); 
		}
		printf("\nEnter the number of sets; enter q to stop :");
	}
	return 0;
}