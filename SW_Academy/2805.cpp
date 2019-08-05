#include <iostream>

using namespace std;

const int MAX = 49;
char input[MAX][MAX + 1];

int solve(int size)
{
	int ret = 0;

	for (int i = 0; i < size / 2; i++)
		for (int j = (size / 2) - i; j <= (size / 2) + i; j++)
		{
			ret += input[i][j] - '0';
		}

	for (int i = 0; i < (size / 2) + 1; i++)
		for (int j = i; j < size - i; j++)
		{
			ret += input[(size / 2) + i][j] - '0';
		}

	return ret;
}

int main()
{
	int tcc, n;

	cin >> tcc;

	for (int i = 0 ; i < tcc; i++)
	{
		cin >> n;

		for (int j = 0; j < n; j++)
			cin >> input[j];

		cout << '#' << i + 1 << ' ' << solve(n);
	}

	return 0;
}