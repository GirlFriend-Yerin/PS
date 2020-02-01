/*
	2018 12 28
	2146 - 다리만들기
	BFS

	-  -
*/

#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e7;
const int MAX = 105;
int map[MAX][MAX];
int group[MAX][MAX];
const int posX[] = { 0, 1 , 0 , -1 };
const int posY[] = { 1, 0, -1, 0 };

const int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }
const int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

struct Point {
	int x, y;

	Point() {};
	Point(int x, int y) : x(x), y(y) {};
};

struct Node {
	int x, y;
	int cnt;

	Node() {};
	Node(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {};
};

void grouping(int n)
{
	bool visited[MAX][MAX] = {};
	queue<Point> q;
	int gpNum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] || !map[i][j]) continue;

			group[i][j] = ++gpNum;
			visited[i][j] = true;
			q.push(Point(i, j));

			while (!q.empty())
			{
				Point cur = q.front(); q.pop();

				for (int k = 0; k < 4; k++) {
					int nextX = cur.x + posX[k];
					int nextY = cur.y + posY[k];

					if (0 <= nextX && nextY < n && 0 <= nextY && nextY < n && map[nextX][nextY] && !visited[nextX][nextY]) {
						group[nextX][nextY] = gpNum;
						visited[nextX][nextY] = true;
						q.push(Point(nextX, nextY));
					}
				}
			}
		}
	}
}

int getCount(int n, int sX, int sY) {

	bool visited[MAX][MAX] = {};
	queue<Node> q;

	int curGroup = group[sX][sY];
	visited[sX][sY] = true;
	q.push(Node(sX, sY, 0));

	while (!q.empty())
	{
		Node cur = q.front(); q.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int nextX = cur.x + posX[i];
			int nextY = cur.y + posY[i];

			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && !visited[nextX][nextY])
			{
				visited[nextX][nextY] = true;

				if (!map[nextX][nextY])
					q.push(Node(nextX, nextY, cur.cnt + 1));
				else {
					if (curGroup != group[nextX][nextY])
						return cur.cnt;
				}
			}
		}
	}

	return INF;
}

bool isSide(int n, int x, int y)
{
	for (int i = 0; i < 4; i++) {
		int nextX = x + posX[i];
		int nextY = y + posY[i];
		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && !map[nextX][nextY]) return true;
	}
	return false;
}

int main()
{
	int n;	cin >> n;
	int res = INF;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j]; 

	grouping(n);

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << group[i][j] << ' ';
		cout << '\n';
	}*/
		

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (!map[i][j] || !isSide(n, i, j)) continue;

			int cnt = getCount(n, i, j);
			res = _min(res, cnt);
		}

	cout << res;

	return 0;
}