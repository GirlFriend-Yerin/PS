#include <iostream>

using namespace std;

const short	BOARD_MAX = 10;

struct Point {
	short x;
	short y;

	Point() { };
	Point(short x, short y) : x(x), y(y) {}
};

bool board[BOARD_MAX][BOARD_MAX];
int res = -1;

bool locationAble(bool board[BOARD_MAX][BOARD_MAX], Point p, int size)
{
	bool res = false;

	if (p.x + size <= BOARD_MAX && p.y + size <= BOARD_MAX)
	{
		res = true;
		for (int i = p.x; i < p.x + size; i++)
			for (int j = p.y; j < p.y + size; j++)
				if (!board[i][j])
					return false;
	}

	return res;
}

bool isClear(bool board[BOARD_MAX][BOARD_MAX])
{
	for (int i = 0; i < BOARD_MAX; i++)
		for (int j = 0; j < BOARD_MAX; j++)
			if (board[i][j])
				return false;
	return true;
}

Point nextPoint(bool board[BOARD_MAX][BOARD_MAX])
{
	Point res(BOARD_MAX, BOARD_MAX);
	for (int i = 0; i < BOARD_MAX; i++) {
		for (int j = 0; j < BOARD_MAX; j++)
		{
			if (board[i][j]) {
				res.x = i;
				res.y = j;
				break;
			}
		}
		if (res.x != BOARD_MAX && res.y != BOARD_MAX)
			break;
	}

	return res;
}

void solution(bool board[BOARD_MAX][BOARD_MAX], int paper[5], Point p, int cnt)
{
	if (p.x == BOARD_MAX && p.y == BOARD_MAX)
	{
		if (res == -1)
			res = cnt;
		else
			if (res > cnt)
				res = cnt;
	}
	else
	{
		for (int s = 5; s > 0; s--)
		{
			if (paper[s - 1] > 0)
			{
				if (locationAble(board, p, s))
				{
					for (int px = p.x; px < p.x + s; px++)
						for (int py = p.y; py < p.y + s; py++)
							board[px][py] = false;

					Point next = nextPoint(board);

					paper[s - 1]--;

					solution(board, paper, next, cnt + 1);

					paper[s - 1]++;

					for (int px = p.x; px < p.x + s; px++)
						for (int py = p.y; py < p.y + s; py++)
							board[px][py] = true;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < BOARD_MAX; i++)
		for (int j = 0; j < BOARD_MAX; j++)
			cin >> board[i][j];

	int paper[] = { 5, 5, 5, 5, 5 };

	solution(board, paper, nextPoint(board), 0);

	cout << res;

	return 0;
}