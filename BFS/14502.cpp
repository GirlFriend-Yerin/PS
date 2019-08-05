/*
	2019 01 17
	7562 나이트의 이동
	BFS

	- 성공 -
*/
#include <iostream>
#include <string.h>

using namespace std;

struct Point {
	short x;
	short y;

	Point() {}
	Point(short x, short y) : x(x), y(y) {}
};

short board[8][8];
Point virusPoint[64];
Point safetyPoint[64];
int virusCount;
int safetyCount;
const int MAXQ = 500;
Point queue[MAXQ];
int head, tail;
int col, row;
int maxSafety = 0;

const short posX[4] = { 1, 0, -1, 0 };
const short posY[4] = { 0, 1, 0, -1 };

void push(short x, short y) {
	queue[head++ % MAXQ] = Point(x, y);
}

Point pop() {
	return queue[tail++ % MAXQ];
}

bool isEmpty() {
	return head == tail;
}

int calSafetyCount(short b[8][8])
{
	int safetyCount = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (b[i][j] == 0)
				safetyCount++;
	return safetyCount;
}

void bruteForce(int pos, int latest)
{
	if (pos == 3)
	{
		short tempBoard[8][8];
		bool check[8][8];

		memset(check, false, sizeof(check));

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				tempBoard[i][j] = board[i][j];

		for (int i = 0; i < virusCount; i++)
		{
			if (check[virusPoint[i].x][virusPoint[i].y])
				continue;

			push(virusPoint[i].x, virusPoint[i].y);

			while (!isEmpty())
			{
				Point cur = pop();

				if (check[cur.x][cur.y])
					continue;

				check[cur.x][cur.y] = true;

				for (int pos = 0; pos < 4; pos++)
				{
					int nextX = cur.x + posX[pos];
					int nextY = cur.y + posY[pos];

					if (0 <= nextX && nextX < row && 0 <= nextY && nextY < col && tempBoard[nextX][nextY] == 0)
					{
						tempBoard[nextX][nextY] = 2;
						push(nextX, nextY);
					}
				}
			}
		}
		
		int zone = calSafetyCount(tempBoard);

		if (maxSafety < zone)
			maxSafety = zone;
	}
	else
	{
		for (int i = latest; i < safetyCount; i++)
		{
			Point point = safetyPoint[i];
			board[point.x][point.y] = 1;
			bruteForce(pos+1, i + 1);
			board[point.x][point.y] = 0;
		}
	}
}

int main()
{
	cin >> row >> col;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 2)
				virusPoint[virusCount++] = Point(i, j);
			else if (board[i][j] == 0)
				safetyPoint[safetyCount++] = Point(i, j);
		}

	bruteForce(0, 0);

	cout << maxSafety;

	return 0;
}