#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <iostream>
#include "LightSensor.h"

using namespace std;

void main()
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");
	
	LightSensor myLightSensor;

	cout << "init done";

	while (1)
	{
		cout << myLightSensor.getIntens() << "%\n";
	}
}