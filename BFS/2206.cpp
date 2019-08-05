#include <iostream>

using namespace std;

const int QMAX = 1000000;
const int BOARD_MAX = 1000;

struct Point {
	int dist;
	short x, y;
	bool wallBroken;

	Point() {};
	Point(short x, short y, int dist, bool w) : x(x), y(y), dist(dist), wallBroken(w) {};
};

struct Queue
{
	int top = 0;
	int rear = 0;
	Point data[QMAX];

	void push(Point p) {
		data[top++ % QMAX] = p;
	}

	Point pop() {
		return data[rear++ % QMAX];
	}

	bool isEmpty() {
		return top % QMAX == rear % QMAX;
	}
};

bool board[BOARD_MAX][BOARD_MAX];
short posX[4] = { 1, 0, -1, 0 };
short posY[4] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int row, col;
	int res = -1;
	Queue q;
	bool visited[BOARD_MAX][BOARD_MAX] = {};
	bool wallVisited[BOARD_MAX][BOARD_MAX] = {};

	cin >> col >> row;

	for (int i = 0; i < col; i++)
	{
		char line[BOARD_MAX + 1];
		cin >> line;
		for (int j = 0; j < row; j++)
			board[i][j] = line[j] - '0';
	}

	q.push(Point(0, 0, 1, false));
	visited[0][0] = true;

	while (!q.isEmpty()) {
		Point cur = q.pop();

		//cout << cur.dist << " : " << cur.x << " , " << cur.y << " - " << (cur.wallBroken ? "True" : "False") << endl;

		if (cur.x == col - 1 && cur.y == row - 1) {
			res = cur.dist;
			break;
		}

		for (int i = 0; i < 4; i++) {
			short nextX = cur.x + posX[i];
			short nextY = cur.y + posY[i];

			if (0 <= nextX && nextX < col && 0 <= nextY && nextY < row) {
				// Not wall
				if (!board[nextX][nextY]) {
					if (cur.wallBroken && !wallVisited[nextX][nextY]) {
						wallVisited[nextX][nextY] = true;
						q.push(Point(nextX, nextY, cur.dist + 1, cur.wallBroken));
					}
					else if (!cur.wallBroken && !visited[nextX][nextY]) {
						visited[nextX][nextY] = true;
						q.push(Point(nextX, nextY, cur.dist + 1, cur.wallBroken));
					}
				}
				// Wall
				else {
					if (!wallVisited[nextX][nextY] && !cur.wallBroken) {
						wallVisited[nextX][nextY] = true;
						q.push(Point(nextX, nextY, cur.dist + 1, true));
					}
				}
			}
		}
	}

	cout << res;

	return 0;
}