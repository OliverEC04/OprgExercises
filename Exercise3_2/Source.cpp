#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

int lightsCountdown[3];

int lightsCheck()
{
	for (int light = 0; light < 3; light++)
	{
		if (lightsCountdown[light] == 0)
		{
			ledOff(light + 4);
		}
		else if (lightsCountdown[light] == 1)
		{
			ledOn(light + 4);
		}
		else
		{
			lightsCountdown[light]--;
		}
	}

	return 0;
}

int setLightState(bool green)
{
	if (green)
	{
		lightsCountdown[0] = 10;
		lightsCountdown[1] = 1;
		lightsCountdown[2] = 1;
	}
	else
	{
		lightsCountdown[0] = 0;
		lightsCountdown[1] = 1;
		lightsCountdown[2] = 20;
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

	while (true)
	{

		lightsCheck();
		Wait(1);
	}

	return 0;
}