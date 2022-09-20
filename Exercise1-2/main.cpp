#include <stdio.h>
#include <math.h>

int main()
{
	double sideA;
	double sideB;
	double sideC;

	printf_s("This program can calculate the length of the long side of a right angled triangle, using the lengths of the two short sides (sides A & B). \n\n");
	printf_s("Enter length of side A \n");
	scanf_s("%lf", &sideA);
	printf_s("\n");
	printf_s("Enter length of side B \n");
	scanf_s("%lf", &sideB);
	printf_s("\n");

	sideC = sqrt(pow(sideA, 2) + pow(sideB, 2));

	printf_s("The length of side C is %lf", sideC);
	printf_s("\n");

	return 0;
}