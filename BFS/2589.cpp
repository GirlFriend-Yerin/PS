/*
	2019 01 13
	2589 º¸¹°¼¶
	BFS

	- ¼º°ø -
*/

#include <iostream>
#include <queue>

using namespace std;

struct Point {
	short x;
	short y;

	Point() {} 
	Point(short x, short y) : x(x), y(y) {}
};

const int MAX = 50;
char tresureMap[MAX][MAX + 1];
Point lands[MAX * MAX];
int row, col;

const short posX[4] = { 1, 0, -1, 0 };
const short posY[4] = { 0, 1, 0, -1 };

int main()
{
	short landCount = 0;
	int maxDis = 0;

	cin >> row >> col;

	for (int i = 0; i < row; i++)
	{
		cin >> tresureMap[i];
		for (int j = 0; j < col; j++)
			if (tresureMap[i][j] == 'L')
				lands[landCount++] = Point(i, j);
	}

	for (int i = 0; i < landCount; i++)
	{
		bool point[MAX][MAX] = {};
		int dis = 0;

		queue<Point> curQ;
		queue<Point> nextQ;

		curQ.push(lands[i]);

		while (!curQ.empty())
		{
			while (!curQ.empty())
			{
				Point cur = curQ.front();
				curQ.pop();

				if (point[cur.x][cur.y])
					continue;

				point[cur.x][cur.y] = true;

				for (int pos = 0; pos < 4; pos++)
				{
					short nextX = cur.x + posX[pos];
					short nextY = cur.y + posY[pos];

					if (0 <= nextX && nextX < row && 0 <= nextY && nextY < col && tresureMap[nextX][nextY] != 'W' &&!point[nextX][nextY])
						nextQ.push(Point(nextX, nextY));
				}
			}

			while (!nextQ.empty())
			{
				curQ.push(nextQ.front());
				nextQ.pop();
			}

			++dis;
		}
		if (maxDis < dis)
			maxDis = dis;

	}

	cout << maxDis - 1;

	return 0;
}