/*
	2018 12 29
	9663 - N Queens
	Back Tracking

	- ¼º°ø -
*/

#include <iostream>

using namespace std;

int res = 0;

bool isAble(int x, int y, int line, const int point[15][2])
{
	for (int j = 0; j < line + 1; j++) // current Line
		if (point[j][0] == x || abs(point[j][0] - x) == abs(point[j][1] - y))
			return false;

	return true;
}

void algorithm(int x, int y, int n, int point[15][2])
{
	if (y + 1 == n)
	{
		res++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (isAble(i, y + 1, y, point))
		{
			point[y + 1][0] = i; point[y + 1][1] = y + 1;
			algorithm(i, y + 1, n, point);
		}
	}
}

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int point[15][2];

		point[0][0] = i;
		point[0][1] = 0;

		algorithm(i, 0, n, point);
	}

	cout << res;

	return 0;
}