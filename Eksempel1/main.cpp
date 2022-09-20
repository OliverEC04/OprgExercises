#include <stdio.h>

int main()
{
	int year;

	printf_s("Indtast aarstal: \n");
	scanf_s("%d", &year);
	printf_s("Hej \n");
	printf_s("Start i august %d \n", year);
	printf_s("Slut i december %d \n", year);

	return 0;
}