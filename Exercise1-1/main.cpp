#include <stdio.h>
#include <math.h>

int main()
{
	int num1;
	int num2;

	printf_s("Write a number: \n");
	scanf_s("%d", &num1);
	printf_s("Write another number: \n");
	scanf_s("%d", &num2);
	printf_s("\n");

	printf_s("%d to the power of %d is %lf \n", num1, num2, pow(num1, num2));
	printf_s("The squareroot of the sum of %d and %d is %lf \n", num1, num2, sqrt(num1 + num2));
	printf_s("%d divided by %d rounded up is %d \n", num1, num2, (int) ceil((double) num1 / num2));

	return 0;
}