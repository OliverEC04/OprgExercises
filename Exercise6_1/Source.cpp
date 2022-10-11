#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

#define ARR_SIZE 12

double temperatures[ARR_SIZE];
int intensities[ARR_SIZE];

int main(void)
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	while (1)
	{
		for (int i = 0; i < ARR_SIZE; i++)
		{
			temperatures[i] = getTemperature();
			intensities[i] = getIntensity();

			printf_s("run %d of 12 ", i);

			Wait(5000);
		}

		printf_s("\n\nTemperatures measurement:\n");
		for (int i = 0; i < ARR_SIZE; i++)
		{
			printf_s("%lf\n", temperatures[i]);
		}

		printf_s("\n\nLight intensities measurement:\n");
		for (int i = 0; i < ARR_SIZE; i++)
		{
			printf_s("%d\n", intensities[i]);
		}
	}

	return 0;
}