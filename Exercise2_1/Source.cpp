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
	
	int ld6Intensity = 0;

	// Turn off all lights
	for (int i = 0; i < 6; i++)
	{
		ledOff(i + 1);
	}

	while (true)
	{
		if (keyPressed(P1))
		{
			ledOn(LD1);
		}
		else
		{
			ledOff(LD1);
		}

		if (keyPressed(P2))
		{
			ld6Intensity = ld6Intensity < 100 ? ld6Intensity + 10 : 0;
		}

		ledOn(LD6, ld6Intensity);

		Wait(1);
	}

	

	return 0;
}