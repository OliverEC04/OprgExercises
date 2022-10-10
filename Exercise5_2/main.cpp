#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARR_SIZE 10
#define _CRT_SECURE_NO_WARNINGS

int myArray[ARR_SIZE];
char myString[10000];

int * bubbleSort(int array[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			int a = array[j];
			int b = array[j + 1];

			if (a > b)
			{
				array[j] = b;
				array[j + 1] = a;
			}
		}
	}

	return array;
}

void main()
{
	srand(time(0));

	for (int i = 0; i < ARR_SIZE; i++)
	{
		char numStr[10000];
		myArray[i] = rand() % 100 + 1;
		sprintf_s(numStr, "%d ", myArray[i]);
		strcat_s(myString, numStr);
	}

	printf_s("Unsorted array:\n");
	printf_s(myString);
	printf_s("\n\nSorted array:\n");

	int *myArraySorted = bubbleSort(myArray, ARR_SIZE);

	for (int i = 0; i < ARR_SIZE; i++)
	{
		printf_s("%d ", myArraySorted[i]);
	}

	printf_s("\n\n");
}