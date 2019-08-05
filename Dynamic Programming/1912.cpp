/*
	2019 01 11
	1912 연속합
	Dynamic Programming

	- 성공 -
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int MAX = 100000;

int main()
{
	int n;
	int numbers[MAX + 1];
	int dpTable[MAX + 1];
	int max = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		scanf("%d", &numbers[i]);

	dpTable[0] = numbers[0];
	max = dpTable[0];

	for (int i = 1; i < n; i++)
	{
		if (dpTable[i - 1] < 0)
			dpTable[i] = numbers[i];
		else
			dpTable[i] = dpTable[i - 1] + numbers[i];
	}

	for (int i = 0; i < n; i++)
		if (max < dpTable[i])
			max = dpTable[i];

	cout << max;

	return 0;
}