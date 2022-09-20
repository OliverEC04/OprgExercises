#include <stdio.h>
#include <math.h>

int main(void)
{
	int a;
	int b;
	int c;

	printf_s("Enter A \n");
	scanf_s("%d", &a);
	printf_s("\n");

	printf_s("Enter B \n");
	scanf_s("%d", &b);
	printf_s("\n");

	printf_s("Enter C \n");
	scanf_s("%d", &c);
	printf_s("\n");

	float d = pow(b, 2) - (4 * a * c);

	printf_s("D = %f \n", d);

	if (d > 0)
	{
		float x1 = (b * -1 + sqrt(d)) / (2 * a);
		float x2 = (b * -1 - sqrt(d)) / (2 * a);

		printf_s("X1 = %f \n", x1);
		printf_s("X2 = %f \n", x2);
	}
	else if (d == 0)
	{
		float x = (b * -1 + sqrt(d)) / (2 * a);

		printf_s("X = %f \n", x);
	}
	else
	{
		printf_s("Your andengradsligning has no solutions! \n");
	}

	return 0;
}
