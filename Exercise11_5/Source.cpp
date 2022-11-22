#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <iostream>
#include "TemperatureSensor.h"

using namespace std;

void main()
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");
	// To do your code

	TemperatureSensor myTempSens;

	cout << "init done";

	while (true)
	{
		cout << myTempSens.getTemp() << "C\n";
	}
}