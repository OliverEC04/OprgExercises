int isInteger(double number)
{
	return (number - (int)(number) == 0);
}

int isEven(double number)
{
	if (!isInteger(number))
	{
		return 0;
	}

	return ((int)number + 1) % 2;
}