#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

bool lightState;

int lightOff()
{
	ledOff(4);
	ledOff(5);
	ledOff(6);

	return 0;
}

bool setLightState(bool state)
{
	if (state && state != lightState)
	{
		lightOff();

		ledOn(5);
		ledOn(6);

		Wait(1000);

		ledOff(6);
		ledOff(5);
		ledOn(4);
	}
	else if (state != lightState)
	{
		lightOff();

		ledOn(5);

		Wait(4000);

		ledOff(5);
		ledOn(6);
	}
	else
	{
		printf_s("lightState was set to current state \n ");
	}

	return state;
}

int main(void)
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");

	lightState = setLightState(true);

	while (true)
	{
		// Switch to red
		if ((keyPressed(P2) || getIntensity() > 50) && lightState)
		{
			lightState = setLightState(false);
		}
	}

	return 0;
}