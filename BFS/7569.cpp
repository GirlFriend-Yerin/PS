/*
	2019 1 2
	7569 - 토마토
	BFS

	- 성공 -
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;

short box[MAX][MAX][MAX];
bool checkBox[MAX][MAX][MAX];

int posX[6] = { 0, 1 , 0 , -1 , 0, 0 };
int posY[6] = { 0, 0, 1, 0, -1, 0 };
int posZ[6] = { -1, 0, 0, 0, 0, 1 };

struct Point {
	short x;
	short y;
	short z;

	Point(short x, short y, short z) : x(x), y(y), z(z) {}
};

int main()
{
	int row, col, hei;
	int day = -1;
	queue<Point> todayQ;
	queue<Point> tomorrowQ;

	cin >> col >> row >> hei;

	for (int i = 0; i < hei; i++)
	{
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				scanf("%hd", &box[i][j][k]);

				if (box[i][j][k] == 1)
					todayQ.push(Point(j, k, i));
			}
		}
	}

	if (todayQ.empty())
		day = 0;

	while (!todayQ.empty())
	{
		while (!todayQ.empty())
		{
			Point cur = todayQ.front();
			todayQ.pop();

			if (checkBox[cur.z][cur.x][cur.y])
				continue;

			checkBox[cur.z][cur.x][cur.y] = true;

			for (int i = 0; i < 6; i++)
			{
				int nextX = cur.x + posX[i];
				int nextY = cur.y + posY[i];
				int nextZ = cur.z + posZ[i];

				if (0 <= nextX && nextX < row && 0 <= nextY && nextY < col && 0 <= nextZ && nextZ < hei)
				{
					if (box[nextZ][nextX][nextY] == 0 && !checkBox[nextZ][nextX][nextY])
					{
						box[nextZ][nextX][nextY] = 1;
						tomorrowQ.push(Point(nextX, nextY, nextZ));
					}
				}
			}
		}

		while (!tomorrowQ.empty())
		{
			todayQ.push(tomorrowQ.front());
			tomorrowQ.pop();
		}
		day++;
	}

	for (int i = 0; i < hei; i++)
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				if (checkBox[i][j][k] == false && box[i][j][k] != -1)
				{
					cout << -1;
					return 0;
				}

	cout << day;

	return 0;
}

