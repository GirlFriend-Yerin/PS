/*
	2019 1 2
	7576 - 토마토
	BFS

	- 성공 -
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

short box[1000][1000];
bool checkBox[1000][1000];

int posX[4] = { 1 , 0 , -1 , 0 };
int posY[4] = { 0, 1, 0, -1 };

struct Point {
	short x;
	short y;

	Point(short x, short y) : x(x), y(y) {}
};

int main()
{
	int row, col;
	int day = -1;
	queue<Point> todayQ;
	queue<Point> tomorrowQ;

	cin >> col >> row;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			scanf("%hd", &box[i][j]);

			if (box[i][j] == 1)
				todayQ.push(Point(i, j));
		}

	if (todayQ.empty())
		day = 0;

	while (!todayQ.empty())
	{
		while (!todayQ.empty())
		{
			Point cur = todayQ.front();
			todayQ.pop();

			if (checkBox[cur.x][cur.y])
				continue;

			checkBox[cur.x][cur.y] = true;

			for (int i = 0; i < 4; i++)
			{
				int nextX = cur.x + posX[i];
				int nextY = cur.y + posY[i];

				if (0 <= nextX && nextX < row && 0 <= nextY && nextY < col)
				{
					if (box[nextX][nextY] == 0 && !checkBox[nextX][nextY])
					{
						box[nextX][nextY] = 1;
						tomorrowQ.push(Point(nextX, nextY));
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

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (checkBox[i][j] == false && box[i][j] != -1)
			{
				cout << -1;
				return 0;
			}

	cout << day;

	return 0;
}
