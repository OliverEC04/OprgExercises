#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	int secondsElapsed;
	int time[3];
	char timeStr[9] = "hh:mm:ss";
	/*char hoursStr[2] = "0";*/

	printf_s("How many seconds ago did you last eat? \n");
	scanf_s("%d", &secondsElapsed);

	time[0] = floor(secondsElapsed / pow(60, 2));
	time[1] = secondsElapsed % (int)pow(60, 2) / 60;
	time[2] = secondsElapsed % 60;

	int unit = -1;
	for (int i = 0; i < 8; i++)
	{
		unit += i % 3 == 0 ? 1 : 0; // increments 1 every 3rd iteration

		timeStr[i] = time[unit]
	}

	/*if (hours < 10)
	{
		strcat(hoursStr, (char) hours + '0');
	}*/

	//hoursStr[] = hours > 9 ? (char)hours : strcat("0", (char) hours);

	//printf_s("%c : %d : %d \n", hours, minutes, seconds);

	return 0;
}

int strSwap(char string[], int i0, int i1)
{
	char c0 = string[i0];
	char c1 = string[i1];

	string[i0] = c1;
	string[i1] = c0;

	return 0;
}

int intToArr(int integer)
{
	int array[99];


}