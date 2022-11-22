#include <stdio.h>
#include "functions.h"

#define ARR_SIZE 8

int myArr[ARR_SIZE] = { 0, 3, 7, 69, 30, 55, 17, 58 };

void main()
{
	printf_s("Maximum value: %d\nMinimum value: %d\nAverage value: %lf\n", 
		maxValue(myArr, ARR_SIZE), minValue(myArr, ARR_SIZE), average(myArr, ARR_SIZE));
}