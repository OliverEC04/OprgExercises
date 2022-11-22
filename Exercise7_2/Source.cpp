#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include "functions.h"

#define ARR_SIZE 12

double temperatures[ARR_SIZE];
double intensities[ARR_SIZE];

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

		printf_s("\nTemperature:\nMaximum value: %d\nMinimum value: %d\nAverage value:%lf\n",
			maxValue(temperatures, ARR_SIZE), minValue(temperatures, ARR_SIZE), average(temperatures, ARR_SIZE));

		printf_s("\nLight intensity:\nMaximum value: %d\nMinimum value: %d\nAverage value:%lf\n",
			maxValue(intensities, ARR_SIZE), minValue(intensities, ARR_SIZE), average(intensities, ARR_SIZE));
	}

	return 0;
}