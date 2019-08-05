#include <iostream>
#include <queue>

using namespace std;

const int MAX = 16;

bool board[MAX][MAX];
bool archer[MAX];
int n, m, d;

int posX[3] = { -1, 1, 0 };
int posY[3] = { 0, 0, 1 };

struct Point {
	short x;
	short y;

	Point() : x(0), y(0) {};
	Point(short x, short y) : x(x), y(y) {};
};

void findEnemy(bool board[MAX][MAX], int pos, int& resX, int& resY) {

	bool visited[10][10] = {};

	queue<Point> q;
	queue<Point> nQ;
	
	int dist = 0;
	bool isOver = false;

	q.push(Point(pos, 0));
	visited[0][pos] = true;

	while (dist < d && !isOver)
	{
		while (!q.empty()) {
			Point cur = q.front();
			q.pop();

			if (board[cur.y][cur.x]) {

				if (resX == -1 && resY == -1) {
					resX = cur.x; resY = cur.y;
				}
				else {
					if (cur.x < resX) {
						resX = cur.x; resY = cur.y;
					}
				}
				isOver = true;
			}

			for (int i = 0; i < 3; i++) {
				short nextX = cur.x + posX[i];
				short nextY = cur.y + posY[i];

				if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n && !visited[nextY][nextX]) {
					visited[nextY][nextX] = true;
					nQ.push(Point(nextX, nextY));
				}
			}
		}

		dist++;

		if (isOver)
			continue;

		while (!nQ.empty()) {
			q.push(nQ.front());
			nQ.pop();
		}
	}
}

bool isContinue(bool board[MAX][MAX]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j])
				return true;
	return false;
}

int run(bool board[MAX][MAX]) {

	int res = 0;

	while (isContinue(board)) {

		vector<Point> turn;

		for (int pos = 0; pos < m; pos++) {
			if (archer[pos])
			{
				int resX = -1, resY = -1;
				findEnemy(board, pos, resX, resY);

				if (resX != -1 && resY != -1)
					turn.push_back(Point(resX, resY));
			}
		}

		for (unsigned int i = 0; i < turn.size(); i++) {
			Point cur = turn[i];

			if (board[cur.y][cur.x])
				res++;

			board[cur.y][cur.x] = false;
		}

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				board[j][i] = board[j + 1][i];
	}

	return res;
}

void boardCopy(bool origin[MAX][MAX], bool des[MAX][MAX])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			des[i][j] = origin[i][j];
}

int play() {

	int maxKill = 0;

	for (int i = 0; i < m - 2; i++)
		for (int j = i + 1; j < m - 1; j++)
			for (int k = j + 1; k < m; k++)
			{
				bool copyBoard[MAX][MAX] = {};

				archer[i] = archer[j] = archer[k] = true;

				boardCopy(board, copyBoard);
				int totalKill = run(copyBoard);

				archer[i] = archer[j] = archer[k] = false;

				if (maxKill < totalKill)
					maxKill = totalKill;
			}

	return maxKill;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> d;

	// 0을 향해 오는 모습으로
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	cout << play();

	return 0;
}