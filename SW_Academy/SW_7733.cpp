#include <iostream>
#include <queue>

using namespace std;

const short MAX = 100;

const short posX[] = { -1, 0, 1, 0 };
const short posY[] = { 0, -1, 0, 1 };

struct Point {
	short x;
	short y;

	Point() {}
	Point(short x, short y) : x(x), y(y) {}
};

void eatCheese(short board[MAX][MAX],const int& n,const int& val) {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] == val)
				board[i][j] = 0;
}

int bfs(short board[MAX][MAX], const int &n)
{
	int res = 0;
	bool checkBoard[MAX][MAX] = {};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (checkBoard[i][j] || !board[i][j])
				continue;
			
			queue<Point> q;

			q.push(Point(i, j));
			checkBoard[i][j] = true;

			while (!q.empty()) {
				Point cur = q.front(); q.pop();

				for (int pos = 0; pos < 4; pos++) {
					short nextX = cur.x + posX[pos], nextY = cur.y + posY[pos];

					if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && !checkBoard[nextX][nextY] && board[nextX][nextY])
					{
						checkBoard[nextX][nextY] = true;
						q.push(Point(nextX, nextY));
					}
				}
			}

			res++;
		}
	}

	return res;
}

int solve(const int& n) {
	int res = 0;
	short board[MAX][MAX] = {};
	short limits = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] > limits)
				limits = board[i][j];
		}
	
	for (int i = 0; i < limits; i++)
	{
		eatCheese(board, n, i);
		int cal = bfs(board, n);

		if (res < cal)
			res = cal;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;
	
	for (int tc = 1; tc <= tcc; tc++) {
		int n; cin >> n;

		int res = solve(n);

		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}