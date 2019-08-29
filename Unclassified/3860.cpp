#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short MAX = 31;

const int posX[] = { 0, 1 , 0 ,-1 };
const int posY[] = { 1, 0, -1, 0 };

struct Point {
	short x, y;
	int val;

	Point() {}
	Point(short x, short y, int val) : x(x), y(y), val(val) {};
};

struct Hole {
	short ix, iy, ox, oy;
	int cost;
	
	Hole() {};
	Hole(short ix, short iy, short ox, short oy, int cost) : ix(ix), iy(iy), ox(ox), oy(oy), cost(cost) {};
};

void bfs(bool map[MAX][MAX], int board[MAX][MAX], int start, int end, int n, int m) {

	bool visited[MAX][MAX] = {};
	queue<Point> q;

	q.push(Point(start, end, board[start][end]));
	visited[start][end] = true;

	while (!q.empty()) {
		Point cur = q.front(); q.pop();

		board[cur.x][cur.y] = cur.val;

		for (int i = 0; i < 4; i++) {
			short nextX = cur.x + posX[i];
			short nextY = cur.y + posY[i];

			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m && !visited[nextX][nextY] && !map[nextX][nextY]) {
				q.push(Point(nextX, nextY, cur.val + 1));
				visited[nextX][nextY] = true;
			}
		}
	}
}

void relexing(bool map[MAX][MAX], int board[MAX][MAX], const Hole& hole, int n, int m) {

	bool visited[MAX][MAX] = {};
	queue<Point> q;

	q.push(Point(hole.ox, hole.oy, board[hole.ix][hole.iy] + hole.cost));
	visited[hole.ox][hole.oy] = true;

	while (!q.empty()) {
		Point cur = q.front(); q.pop();

		if (board[cur.x][cur.y] <= cur.val) continue;
		board[cur.x][cur.y] = cur.val;

		for (int i = 0; i < 4; i++) {
			short nextX = cur.x + posX[i];
			short nextY = cur.y + posY[i];

			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m && !visited[nextX][nextY] && !map[nextX][nextY]) {
				q.push(Point(nextX, nextY, cur.val + 1));
				visited[nextX][nextY] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int w, h; cin >> w >> h;
	while (w | h) {
		int board[MAX][MAX] = {};
		bool map[MAX][MAX] = {};
		
		int g; cin >> g;
		for (int i = 0; i < g; i++) {
			int x, y; cin >> x >> y;
			map[x][y] = true;
		}

		int e; cin >> e;
		vector<Hole> holes(e);
		for (int i = 0; i < e; i++)
			cin >> holes[i].ix >> holes[i].iy >> holes[i].ox >> holes[i].oy >> holes[i].cost;

		bfs(map, board, 0, 0, w, h);

		if (board[w - 1][h - 1] == 0)
			cout << "Impossible\n";
		else {
			for (int i = 0; i < e; i++)
				relexing(map, board, holes[i], w, h);

			int cost = board[w - 1][h - 1];

			for (int i = 0; i < e; i++)
				relexing(map, board, holes[i], w, h);

			if (cost != board[w - 1][h - 1])
				cout << "Never" << '\n';
			else 
				cout << cost << '\n';
		}
		cin >> w >> h;
	}


	return 0;
}