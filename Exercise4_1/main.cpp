#include <stdio.h>
#include "sumBiggerThan100.h"

int main()
{
	double num1;
	double num2;

	printf_s("This program will tell you if the sum of two given numbers are greater than 100.\n\nEnter first number:\n");
	scanf_s("%lf", &num1);
	printf_s("\nEnter second number:\n");
	scanf_s("%lf", &num2);

	if (sumBiggerThan100(num1, num2))
	{
		printf_s("\nThe sum is bigger than 100!\n\n");
	}
	else
	{
		printf_s("\nThe sum is less than or equal to 100!\n\n");
	}

	return 0;
}