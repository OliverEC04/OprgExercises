#include <stdlib.h>
#include <RaspberryDLL.h>

void flash5sec()
{
	const int duration = 5000;
	const int tickDuration = 500;

	ledOn(1);

	for (int i = 0; i < duration / tickDuration; i++)
	{
		ledOn(i % 6 + 1);
		ledOff((i - 1) % 6 + 1);

		Wait(tickDuration);
	}
}

void flash10sec()
{
	const int duration = 10000;
	const int tickDuration = 2000;
	const int tickCount = duration / tickDuration;

	for (int i = 0; i < tickCount; i++)
	{
		if (i % 2)
		{
			ledOn(1);
			ledOff(2);
			ledOn(3);
			ledOff(4);
			ledOn(5);
			ledOff(6);
		}
		else
		{
			ledOff(1);
			ledOn(2);
			ledOff(3);
			ledOn(4);
			ledOff(5);
			ledOn(LD6, (int)((double)i / (double)tickCount * 100));
		}

		Wait(tickDuration);
	}
}
