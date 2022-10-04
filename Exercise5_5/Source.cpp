#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

#define LED_COUNT 6

int ledStates[LED_COUNT] = {0, 0, 0, 0, 0, 0};
int hit = 1;

void allLedsOff()
{
	for (int led = 1; led <= LED_COUNT; led++)
	{
		ledOff(led);
	}
}

void rollDie()
{
	while (!keyPressed(P1))
	{
		int num = rand() % 6 + 1;
		printf_s("%d\n", num);

		// Sluk forrige tal
		ledStates[hit - 1] = 0;
		ledOff(hit);

		// Tænd slået tal
		ledStates[num - 1] = 1;
		ledOn(num);

		hit = num;
	}
}

int main(void)
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");
	
	allLedsOff();

	while (true)
	{
		rollDie();

		// Bliv på slået tal indtil P2 er trykket
		while (!keyPressed(P2))
		{
			Wait(100);
		}
	}

	allLedsOff();

	return 0;
}