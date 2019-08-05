/*
	2019 03 05
	1981 
	bfs

	- 메모리 초과 -
*/

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;

int adj[MAX][MAX];

const short posX[4] = { 1, 0 };
const short posY[4] = { 0, 1 };

struct Point {
	short x;
	short y;
	short max;
	short min;

	Point(short x, short y, short max, short min) : x(x), y(y), max(max), min(min) {};
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int res = 201;
	queue<Point> q;

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];

	q.push(Point(0, 0, adj[0][0], adj[0][0]));

	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		if (cur.x == n - 1 && cur.y == n - 1)
		{
			int cal = cur.max - cur.min;
			res = res > cal ? cal : res;
			continue;
		}
		
		short curDiff = cur.max - cur.min;
		for (int i = 0; i < 2; i++)
		{
			short nextX = cur.x + posX[i];
			short nextY = cur.y + posY[i];
			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n)
			{
				short nextMax = adj[nextX][nextY] > cur.max ? adj[nextX][nextY] : cur.max;
				short nextMin = adj[nextX][nextY] < cur.min ? adj[nextX][nextY] : cur.min;
				
				if (curDiff <= (nextMax - nextMin))
					q.push(Point(nextX, nextY, nextMax, nextMin));
			}
		}
	}

	cout << res;

	return 0;
}