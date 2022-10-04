#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARR_SIZE 10
#define _CRT_SECURE_NO_WARNINGS

int myArray[ARR_SIZE];
int myBufArr[ARR_SIZE];
char myString[10000];

void bubbleSort(int *bufArr, int array[], int arrSize)
{
	bufArr = array;

	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			int a = bufArr[j];
			int b = bufArr[j + 1];

			if (a > b)
			{
				bufArr[j] = b;
				bufArr[j + 1] = a;
			}
			printf_s(" - %d \n", bufArr[j]);
		}

		printf_s("-----\n");
	}

	//*bufArr = bufArr;
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

	printf_s(myString);
	printf_s("\n");

	bubbleSort(myBufArr, myArray, ARR_SIZE);

	for (int i = 0; i < ARR_SIZE; i++)
	{
		printf_s("%d ", myBufArr[i]);
	}
}