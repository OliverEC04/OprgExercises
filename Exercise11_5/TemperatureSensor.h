#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>

#pragma once
class TemperatureSensor
{
	public:
		TemperatureSensor();
		double getTemp();
};

