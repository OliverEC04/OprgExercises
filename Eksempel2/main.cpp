#include <stdio.h>

int main()
{
	int age;
	int year;

	printf_s("How old are you? \n");
	scanf_s("%d", &age);
	printf_s("Which year is it? \n");
	scanf_s("%d", &year);
	printf_s("You were born in %d \n", year - age);

	return 0;
}