/*
	2019 01 12
	11026 적록색약
	BFS

	- 성공 -
*/
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int MAX = 100;

char board[MAX][MAX];

short posX[4] = { 1, 0, -1, 0 };
short posY[4] = { 0, 1, 0, -1 };

struct Point {
	short x;
	short y;

	Point() {};
	Point(short x, short y) : x(x), y(y) {}
};

int func(int n, bool isRedGreen)
{
	int res = 0;
	bool visitTable[MAX][MAX];

	queue<Point> q;

	memset(visitTable, false, sizeof(visitTable));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (visitTable[i][j])
				continue;

			q.push(Point(i, j));

			while (!q.empty())
			{
				Point cur = q.front();
				q.pop();

				if (visitTable[cur.x][cur.y])
					continue;

				visitTable[cur.x][cur.y] = true;

				for (int pos = 0; pos < 4; pos++)
				{
					short nextX = cur.x + posX[pos];
					short nextY = cur.y + posY[pos];
					if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n)
					{
						if (isRedGreen && board[cur.x][cur.y] != 'B') // 적녹색약인 경우
						{
							if (board[nextX][nextY] == 'G' || board[nextX][nextY] == 'R')
								q.push(Point(nextX, nextY));
						}

						if (board[cur.x][cur.y] == board[nextX][nextY])
							q.push(Point(nextX, nextY));
					}
				}
			}
			res++;
		}

	return res;
}

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> board[i];

	cout << func(n, false) << ' ' << func(n, true);

	return 0;
}