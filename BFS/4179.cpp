/*
	2018 01 28
	4179 ºÒ!
	BFS

	- ¼º°ø -
*/
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000;

const short posX[4] = { 0, 1, 0, -1 };
const short posY[4] = { 1, 0, -1, 0 };

struct Point {
	short x;
	short y;

	Point() : x(0), y(0) {};
	Point(short x, short y) : x(x), y(y) {};
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	queue<Point> fire;
	queue<Point> nextFire;
	queue<Point> sangGeun;
	queue<Point> nextSangGeun;
	int result = 0;
	bool success = false;
	char board[MAX + 1][MAX + 1] = {};
	bool check[MAX + 1][MAX] = {};
	int row, col;
	cin >> col >> row;

	for (int i = 0; i < col; i++)
	{
		cin >> board[i];
		for (int j = 0; j < row; j++)
			if (board[i][j] == 'F')
				fire.push(Point(i, j));
			else if (board[i][j] == 'J')
			{
				sangGeun.push(Point(i, j));
				check[i][j] = true;
			}
	}

	while (!sangGeun.empty())
	{
		while (!fire.empty())
		{
			Point cur = fire.front();
			fire.pop();

			for (int i = 0; i < 4; i++)
			{
				short nextX = cur.x + posX[i];
				short nextY = cur.y + posY[i];

				if (0 <= nextX && nextX < col && 0 <= nextY && nextY < row && board[nextX][nextY] != '#' && board[nextX][nextY] != 'F')
				{
					board[nextX][nextY] = 'F';
					nextFire.push(Point(nextX, nextY));
				}
			}
		}

		while (!sangGeun.empty())
		{
			Point cur = sangGeun.front();
			sangGeun.pop();

			if (cur.x == -1 || cur.y == -1 || cur.x == col || cur.y == row)
			{
				success = true;
				break;
			}

			// cout << cur.x << ' ' << cur.y << '\n'; // For Debug

			for (int i = 0; i < 4; i++)
			{
				short nextX = cur.x + posX[i];
				short nextY = cur.y + posY[i];

				if (nextX == -1 || nextY == -1 || nextX == col || nextY == row)
					nextSangGeun.push(Point(nextX, nextY));
				else if (nextX < col && nextY < row && !check[nextX][nextY] && board[nextX][nextY] != '#' && board[nextX][nextY] != 'F')
				{
					check[nextX][nextY] = true;
					nextSangGeun.push(Point(nextX, nextY));
				}
			}
		}

		if (!success)
		{
			while (!nextFire.empty())
			{
				fire.push(nextFire.front());
				nextFire.pop();
			}

			while (!nextSangGeun.empty())
			{
				sangGeun.push(nextSangGeun.front());
				nextSangGeun.pop();
			}
			result++;
		}
		else
			break;
	}

	if (success)
		cout << result << '\n';
	else
		cout << "IMPOSSIBLE\n";

	return 0;
}