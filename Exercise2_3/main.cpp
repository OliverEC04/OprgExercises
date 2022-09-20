#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(void)
{
	double r1;
	double r2;
	bool run = true;

	while (run)
	{
		printf_s("Enter R1 \n");
		scanf_s("%lf", &r1);
		printf_s("\n");

		printf_s("Enter R2 \n");
		scanf_s("%lf", &r2);
		printf_s("\n");

		double rEq = 1 / ((1 / r1) + (1 / r2));

		printf_s("R_eq = %lf ohm \n\n", rEq);

		printf_s("Would you like to do another calculation? (y/n) \n\n");

		if (!(_getch() == 121))
		{
			run = false;
		}
	}

	return 0;
}