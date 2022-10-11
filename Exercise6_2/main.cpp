#include <stdio.h>
#include <stdlib.h>

#define INPUT_STRING_SIZE 255

int getStringWordCount(char string[])
{
	int wordCount = 1;

	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			wordCount++;
		}

		i++;
	}

	return wordCount;
}

void main()
{
	char inputString[INPUT_STRING_SIZE];

	printf_s("Write string of maximum %d characters:\n", INPUT_STRING_SIZE - 1);
	fgets(inputString, INPUT_STRING_SIZE, stdin);
	printf_s("\n\nWords in string:\n%d\n", getStringWordCount(inputString));
}