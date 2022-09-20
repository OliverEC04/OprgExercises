#include <stdio.h>
#include <math.h>

int main(void)
{
	int number1;
	int number2;
	double fraction;
	double squareRoot;

	printf_s("Write first number: ");
	scanf_s("%d", &number1);

	printf_s("Write second number: ");
	scanf_s("%d", &number2);

	fraction = (double) number1 / number2;
	squareRoot = sqrt(number1);

	printf("\n%d divided by %d gives %lf\n", number1, number2, fraction);
	printf("\nSquare root of %d is %lf\n\n", number1, squareRoot);

	return 0;
}