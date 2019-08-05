/*
	2019 01 11
	1932 정수삼각형
	Dynamic Programming

	- 성공 -
*/

#include <iostream>

using namespace std;

const int MAX = 500;
int pyramid[MAX][MAX + 1];

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> pyramid[i][j];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				pyramid[i][j] += pyramid[i - 1][j];
			else
				pyramid[i][j] += pyramid[i - 1][j - 1] < pyramid[i - 1][j] ? pyramid[i - 1][j] : pyramid[i - 1][j - 1];
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			if (pyramid[i][j] > max)
				max = pyramid[i][j];

	cout << max;

	return 0;
}