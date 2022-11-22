#include <stdio.h>
#include "codeFunctions.h"

void main()
{
	char password[CODE_SIZE];
	createCode(password);

	printf_s("Your password is ");
	printf_s(password);
	printf_s("\n");
	/*for (int i = 0; i < CODE_SIZE; i++)
	{
		printf_s(password[i]);
	}*/

	while(!changeCode(password)){}
}