#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int MAX = 2500;
int arr[MAX + 1][MAX + 1];
char board[MAX + 1][MAX + 1];
int row, col, shapes;

void addRectangle(int strX, int strY, int desX, int desY)
{
	int y1;
	for (; strX < desX; strX += strX & (-strX))
	{
		y1 = strY;
		for (; y1 < desY; y1 += y1 & (-y1))
			arr[y1][strX] += 1;
	}
}

void drawVertical(int x, int y, int desY)
{
	for (; y < desY + 1; y += y & (-y))
		arr[x][y] += 1;
}

void addDiamond(int x, int y, int r)
{
	drawVertical(x, y - r, y + r);
	for (int i = 1; i < r; i++)
	{
		drawVertical(x - i, y - r + i, y + r - i);
		drawVertical(x + i, y - r + i, y + r - i);
	}
}

int sum(int x, int y) {
	int r = 0;
	int y1;
	for (; x > 0; x -= x & (-x))
	{
		y1 = y;
		for (; y1 > 0; y1 -= y1 & (-y1))
			r += arr[x][y1];
	}
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> col >> row >> shapes;

	for (int i = 0; i < shapes; i++)
	{
		int order;
		cin >> order;
		if (order == 1) // Rectangle
		{
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			addRectangle(x1 + 1, y1 + 1, x2 + 1, y2 + 1);
		}
		else // Diamond
		{
			int x, y, r;

			cin >> x >> y >> r;
			addDiamond(x + 1, y + 1, r);
		}
	}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			board[i][j] = sum(i + 1, j + 1) % 2 ? '#' : '.';

	for (int i = 0; i < row; i++)
		cout << board[i] << '\n';

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}

	return 0;
}