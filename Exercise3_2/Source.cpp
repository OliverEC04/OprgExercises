#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

int lightOff()
{
	ledOff(4);
	ledOff(5);
	ledOff(6);

	return 0;
}

int setLightState(bool green)
{
	if (green)
	{
		lightOff();

		ledOn(5);
		ledOn(6);

		Wait(1000);

		ledOff(6);
		ledOff(5);
		ledOn(4);
	}
	else
	{
		lightOff();

		ledOn(5);

		Wait(4000);

		ledOff(5);
		ledOn(6);
	}

	return 0;
}

int main(void)
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");

	setLightState(true);

	Wait(10000);

	setLightState(false);

	return 0;
}