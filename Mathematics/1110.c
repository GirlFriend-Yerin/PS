/*
	2019 01 05
	1110 - 더하기 사이클
	MatheMatics

	- 성공 -
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int original;

	scanf("%d", &original);

	int counter = 1;
	int sum = (original % 10) + (original / 10);
	int curNum = ((original % 10) * 10) + (sum % 10);

	for (; curNum != original; counter++)
	{
		sum = (curNum % 10) + (curNum / 10);
		curNum = ((curNum % 10) * 10) + (sum % 10);
	}

	printf("%d", counter);

	return 0;
}