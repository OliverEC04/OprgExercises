#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

int main(void)
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");
	
	while (true)
	{
		printf_s("%lf\n", getTemperature());
		for (int led = 1; led <= 6; led++)
		{
			if (getTemperature() >= 21 + led)
			{
				ledOn(led);
			}
			else
			{
				ledOff(led);
			}
		}
	}

	return 0;
}