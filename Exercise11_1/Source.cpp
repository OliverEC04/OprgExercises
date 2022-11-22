#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include <iostream>
#include "Switch.h"

using namespace std;

void main()
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");
	
	cout << "Init done";

	Switch switch1;

	while (true)
	{
		cout << switch1.getState();
	}
}