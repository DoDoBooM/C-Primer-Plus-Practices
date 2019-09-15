#include <stdio.h>

int LoopFunc();
int main(int argc, char* argv[])
{
	for (int i = 0; i < 11; ++i)
	{
		printf("called %d time(s)\n",LoopFunc());
	}
	return 0;
}
int LoopFunc()
{
	static int calledTimes = 0;
	return ++calledTimes;
}