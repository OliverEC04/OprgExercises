#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <iostream>

class LightSensor
{
	public:
		LightSensor();
		int getIntens();
};

