#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const short MAX = 125;
const short INF = 2500;

const short posX[] = { 0, 1, 0, -1 };
const short posY[] = { 1, 0, -1, 0 };

struct Point {
	short x, y;
	int acc;

	Point(short x, short y, int acc) : x(x), y(y), acc(acc) {}

	bool operator<(const Point& p) const {
		return acc > p.acc;
	}
};

int dijkstra(const vector<vector<int>>& board, const int n) {

	bool visited[MAX][MAX] = {};
	int accBoard[MAX][MAX] = {}; for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) accBoard[i][j] = INF;
	priority_queue<Point> pq;

	pq.push(Point(0, 0, board[0][0]));

	while (!pq.empty()) {
		Point cur = pq.top(); pq.pop();

		if (visited[cur.x][cur.y]) continue;

		visited[cur.x][cur.y] = true;

		for (int i = 0; i < 4; i++) {
			short nextX = cur.x + posX[i];
			short nextY = cur.y + posY[i];

			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && !visited[nextX][nextY]) {
				if (cur.acc + board[nextX][nextY] < accBoard[nextX][nextY]) {
					accBoard[nextX][nextY] = cur.acc + board[nextX][nextY];
					pq.push(Point(nextX, nextY, accBoard[nextX][nextY]));
				}
			}
		}
	}

	return accBoard[n - 1][n - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int tc = 1;
	while (n) {
		vector<vector<int>> board(n);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int val; cin >> val;
				board[i].push_back(val);
			}

		cout << "Problem " << tc++ << ": " << dijkstra(board, n) << '\n';

		cin >> n;
	}

	return 0;
}