/*
	2018 01 20
	1405 미친 로봇
	DFS

	- 성공 -
*/
#include <iostream>

using namespace std;

const int MAX = 15;

const short posX[4] = { 1, -1, 0, 0 }; // E W
const short posY[4] = { 0, 0, 1, -1 }; // S N
bool map[MAX * 2 + 1][MAX * 2 + 1];
double percentage[4];
short n;

double dfs(int pos, short x, short y, double curPer)
{
	double res = 0;
	if (pos == n)
	{
		return curPer;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (percentage[i] != 0)
			{
				short nextX = x + posX[i];
				short nextY = y + posY[i];

				if (0 <= nextX && nextX < (n * 2 + 1) && 0 <= nextY && nextY < (n * 2 + 1) && !map[nextX][nextY])
				{
					map[nextX][nextY] = true;
					res += dfs(pos + 1, nextX, nextY, curPer * percentage[i]);
					map[nextX][nextY] = false;
				}
			}
		}
	}

	return res;
}

int main()
{
	cin >> n;

	for (int i = 0; i < 4; i++)
	{
		cin >> percentage[i];
		percentage[i] /= 100.0;
	}


	map[n][n] = true;
	cout.precision(11);
	cout << fixed << dfs(0, n, n, 1);

	return 0;
}