#include <stdio.h>
#include "pe12-3a.h"
int main(int argc, char* argv[])
{
	int preMode = 0;
	int mode = 0;
	float distance, fuel;
	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while(mode >= 0)
	{
		set_mode(&mode, preMode);
		preMode = mode;
		get_info(mode, &distance, &fuel);
		show_info(mode, distance, fuel);
		printf("Enter 0 for metric mode, 1 for US mode: ");
		printf(" (-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}