#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor()
{}

double TemperatureSensor::getTemp()
{
	return 60 - getTemperature();
}