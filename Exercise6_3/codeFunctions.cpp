#include <stdio.h>
#include "codeFunctions.h"
#include <stdlib.h>


void createCode(char codeAlias[])
{
	int ascii;

	srand(time(0));

	for (size_t index = 0; index < CODE_SIZE; index++)
	{
		ascii = (rand() % 75 + 48);

		// if ascii number is NOT a letter or digit (check ASCII table)
		if (57 < ascii && ascii < 65 || 90 < ascii && ascii < 97)
			index--;
		else
			codeAlias[index] = ascii;
	}

	codeAlias[CODE_SIZE] = '\0';
}


int checkCode(char correctCodeAlias[], char codeToCheckAlias[])
{
	printf_s(codeToCheckAlias);

	int i = 0;
	while (correctCodeAlias[i] != '\0')
	{
		printf_s("%c %c %d\n", correctCodeAlias[i], codeToCheckAlias[i], correctCodeAlias[i] == codeToCheckAlias[i]);
		if (correctCodeAlias[i] != codeToCheckAlias[i])
		{
			return 0;
		}

		i++;
	}

	if (correctCodeAlias[i] == codeToCheckAlias[i])
	{
		return 1;
	}
	
	return 0;
}


int changeCode(char currentCodeAlias[])
{
	char currentCodeInput[CODE_SIZE];
	char newCodeInput1[CODE_SIZE];
	char newCodeInput2[CODE_SIZE];

	printf_s("Enter old password:\n");
	fgets(currentCodeInput, CODE_SIZE + 1, stdin);

	if (!checkCode(currentCodeAlias, currentCodeInput))
	{
		printf_s("Wrong password!\n");
		return 0;
	}

	printf_s("Enter new password (max %d characters):\n", CODE_SIZE);
	fgets(newCodeInput1, CODE_SIZE + 1, stdin);

	printf_s("Enter new password again (max %d characters):\n", CODE_SIZE);
	fgets(newCodeInput2, CODE_SIZE + 1, stdin);

	if (checkCode(newCodeInput1, newCodeInput2))
	{
		currentCodeAlias = newCodeInput1;
		printf_s("Password successfully changed!\n");
		return 1;
	}
	else
	{
		printf_s("Entered passwords don't match!\n");
		return 0;
	}

	return 0;
}
