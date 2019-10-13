#include <iostream>
#include <queue>

using namespace std;

const short MAX = 250;
typedef pair<int, int> pii;

struct Point {
	short x;
	short y;

	Point() {};
	Point(short x, short y) : x(x), y(y) {};
};

int n, m;
const short posX[] = { 0, 1, 0, -1 };
const short posY[] = { 1, 0, -1, 0 };

pii bfs(char board[MAX][MAX + 1], bool visited[MAX][MAX], int x, int y) {

	int sheep = board[x][y] == 'o', wolf = board[x][y] == 'v';
	queue<Point> q;
	q.push(Point(x, y));
	visited[x][y] = true;

	while (!q.empty()) {
		Point cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			short nextX = cur.x + posX[i];
			short nextY = cur.y + posY[i];

			if (0 <= nextX && nextX < n && 0 <= nextY && nextY <= m && !visited[nextX][nextY] && board[nextX][nextY] != '#') {
				sheep += board[nextX][nextY] == 'o';
				wolf += board[nextX][nextY] == 'v';
				q.push(Point(nextX, nextY));
				visited[nextX][nextY] = true;
			}
		}
	}
	
	sheep = sheep <= wolf ? 0 : sheep;
	wolf = sheep <= wolf ? wolf : 0;

	return { sheep, wolf };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	char board[MAX][MAX + 1] = {};
	bool visited[MAX][MAX] = {};
	for (int i = 0; i < n; i++)
		cin >> board[i];

	pii res = {0,0};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || board[i][j] == '#') continue;
			pii live = bfs(board, visited, i, j);
			res.first += live.first;
			res.second += live.second;
		}

	cout << res.first << ' ' << res.second;
	
	return 0;
}