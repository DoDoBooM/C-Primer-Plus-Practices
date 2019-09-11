#include <stdio.h>
#include "pe12-2a.h"
int main(int argc, char* argv[])
{
	int preMode = 0;
	int mode = 0;
	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while(mode >= 0)
	{
		set_mode(mode, preMode);
		preMode = mode;
		get_info(mode);
		show_info();
		printf("Enter 0 for metric mode, 1 for US mode: ");
		printf(" (-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}