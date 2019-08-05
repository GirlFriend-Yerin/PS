#include <iostream>
#include <queue>

using namespace std;

const int MAX = 300;

struct Point {
	short x;
	short y;

	Point() {};
	Point(short x, short y) : x(x), y(y) {};
};

const short posX[] = { 0, 1, 0 , -1, 1, 1, -1, -1 };
const short posY[] = { 1, 0, -1, 0, 1, -1, -1, 1 };

int getBombCount(char board[MAX][MAX + 1], Point p, int n) {
	int res = 0;

	for (int i = 0; i < 8; i++) {
		short nextX = p.x + posX[i];
		short nextY = p.y + posY[i];

		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && board[nextX][nextY] == '*')
			res++;
	}

	return res;
}

int nearAble(char board[MAX][MAX + 1], Point p, int n) {
	for (int i = 0; i < n; i++) {
		short nextX = p.x + posX[i];
		short nextY = p.y + posY[i];

		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n)
			if (getBombCount(board, p, n) == 0)
				return i;
	}

	return -1;
}

int boardClick(char board[MAX][MAX + 1], bool checked[MAX][MAX], Point start, int n) {

	int bombRes = 0;

	queue<Point> q;

	q.push(start);

	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		checked[cur.x][cur.y] = true;
		bombRes++;

		int bombCount = getBombCount(board, cur, n);

		if (bombCount == 0)
		{
			for (int i = 0; i < 8; i++) {
				short nextX = cur.x + posX[i];
				short nextY = cur.y + posY[i];

				if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && !checked[nextX][nextY]) {
					checked[nextX][nextY] = true;
					q.push(Point(nextX, nextY));
				}
			}
		}
	}

	return bombRes;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;
	cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++)
	{
		int res = 0;
		int n;
		int blankCount = 0;
		int firstBomb = 0;

		char board[MAX][MAX + 1] = {};
		bool checked[MAX][MAX] = {};

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> board[i];
			for (int j = 0; j < n; j++)
				if (board[i][j] == '.')
					blankCount++;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == '*' || checked[i][j])
					continue;

				if (getBombCount(board, Point(i, j), n) == 0) {
					firstBomb += boardClick(board, checked, Point(i, j), n);
					res++;
				}
			}
		}

		res += blankCount - firstBomb;

		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}