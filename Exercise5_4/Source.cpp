#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <conio.h>

int ledStates[6] = { 0, 0, 0, 0, 0, 0 };

void allLedsOff()
{
	for (int led = 1; led < 7; led++)
	{
		ledOff(led);
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
		int key = _getch() - 48;

		if (key == 0)
		{
			allLedsOff();

			return 0;
		}

		if (ledStates[key - 1] && (0 < key && key <= 6))
		{
			ledOff(key);
			ledStates[key - 1] = 0;
		}
		else if (0 < key && key <= 6)
		{
			ledOn(key);
			ledStates[key - 1] = 1;
		}
		else
		{
			printf_s("Invalid input\n");
		}
	}

	allLedsOff();

	return 0;
}