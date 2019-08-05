/*
	2019 01 10
	2580 ½ºµµÄí
	Back Tracking

	- ¼º°ø -
*/
#include <iostream>

using namespace std;

struct Point
{
	short x;
	short y;

	Point() {};
	Point(short x, short y) : x(x), y(y) {};
};

bool isOver;
short board[9][9];
Point emptySpace[81];
int zeroCount;

void func(int pos)
{
	if (pos == zeroCount)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << board[i][j] << ' ';
			cout << '\n';
		}
		isOver = true;
	}
	else
	{
		short curX = emptySpace[pos].x;
		short curY = emptySpace[pos].y;

		bool row[10] = {};
		bool col[10] = {};
		bool box[10] = {};

		for (int i = 0; i < 9; i++)
			row[board[curX][i]] = true;

		for (int i = 0; i < 9; i++)
			col[board[i][curY]] = true;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				box[board[(curX / 3) * 3 + i][(curY / 3) * 3 + j]] = true;

		for (int i = 1; i < 10; i++)
			if (!row[i] && !col[i] && !box[i] && !isOver)
			{
				board[curX][curY] = i;
				func(pos + 1);
				board[curX][curY] = 0;
			}
	}
}


int main()
{
	int startX = -1, startY = -1;

	for (int i = 0 ;i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
				emptySpace[zeroCount++] = Point(i, j);
		}

	func(0);
	
	return 0;
}