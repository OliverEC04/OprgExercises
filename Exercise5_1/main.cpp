#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 20

int myArray[ARR_SIZE];
int negaCount = 0;

void main()
{
	srand(time(0));

	for (int i = 0; i < ARR_SIZE; i++)
	{
		myArray[i] = rand() % 100 - 50;
		negaCount += myArray[i] < 0 ? 1 : 0;
	}

	printf_s("\nmyArray contains %d negative numbers.\n", negaCount);
}