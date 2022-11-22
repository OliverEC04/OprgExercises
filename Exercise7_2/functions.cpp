int maxValue(double* arr, const int arrSize)
{
	int maxVal = arr[0];

	for (int i = 1; i < arrSize; i++)
	{
		if (arr[i] > maxVal)
		{
			maxVal = arr[i];
		}
	}

	return maxVal;
}

int minValue(double* arr, const int arrSize)
{
	int minVal = arr[0];

	for (int i = 1; i < arrSize; i++)
	{
		if (arr[i] < minVal)
		{
			minVal = arr[i];
		}
	}

	return minVal;
}

double average(double arr[], const int arrSize)
{
	int sum = 0;

	for (int i = 0; i < arrSize; i++)
	{
		sum += arr[i];
	}

	return (double)sum / (double)arrSize;
}
