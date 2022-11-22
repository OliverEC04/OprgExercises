#include <stdio.h>
#include "codeFunctions.h"

void main()
{
	char str1[] = "test1 hej";
	char str2[] = "test1 hej";
	char str3[] = "nej string";

	printf_s("\nString 1 & 2 eq: %d\nString 2 & 3 eq: %d\nString 1 & 3 eq: %d\n", 
		checkCode(str1, str2), checkCode(str2, str3), checkCode(str1, str3));
}