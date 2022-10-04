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
	
	for (int i = 1; i < 7; i++)
	{
		ledOn(i);
	}

	Wait(5000);

	for (int i = 1; i < 7; i++)
	{
		ledOff(i);
	}

	return 0;
}