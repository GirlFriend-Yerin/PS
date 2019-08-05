/*
	2019 01 12
	10989 수 정렬하기 3
	Sorting

	- 성공 -
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

short digits[10001];

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		short val;
		scanf("%hd", &val);
		digits[val]++;
	}

	// counting Sort
	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < digits[i]; j++)
			printf("%hd\n", i);
	}

	return 0;
}