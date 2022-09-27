#include <stdio.h>
#include "functions.h"

void main()
{
	double number;

	printf_s("Enter a number:\n");
	scanf_s("%lf", &number);

	printf_s("\nIs even:\n%d\n\nIs integer:\n%d", isEven(number), isInteger(number));
}
