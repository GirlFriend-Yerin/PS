#include <iostream>
#include <queue>

using namespace std;

const short MAX = 100;

struct Point {
	short x, y;
	short cnt;

	Point() {}
	Point(short x, short y, short cnt) : x(x), y(y), cnt(cnt) {}

	bool operator<(const Point& p) const {
		return cnt > p.cnt;
	}
};

const short posX[] = { 1, 0, -1, 0 };
const short posY[] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	int res = 0;
	bool visited[MAX][MAX] = {};
	char board[MAX][MAX + 1] = {};

	for (int i = 0; i < m; i++)
		cin >> board[i];

	visited[0][0] = true;

	priority_queue<Point> pq;
	pq.push(Point(0, 0, 0));
	
	while (!pq.empty()) {
		Point cur = pq.top(); pq.pop();

		if (cur.x == m - 1 && cur.y == n - 1) {
			res = cur.cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			short nextX = cur.x + posX[i];
			short nextY = cur.y + posY[i];

			if (0 <= nextX && nextX < m && 0 <= nextY && nextY < n && !visited[nextX][nextY]) {
				visited[nextX][nextY] = true;
				pq.push(Point(nextX, nextY, cur.cnt + board[nextX][nextY] - '0'));
			}
		}
	}

	cout << res;

	return 0;
}