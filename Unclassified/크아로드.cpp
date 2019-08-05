#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

const short MAX = 10;

bool board[MAX][MAX];
int posX[] = { 1, 0, -1, 0 };
int posY[] = { 0, 1, 0, -1 };

struct Point {
	short x, y;

	Point() {};
	Point(short x, short y) : x(x), y(y){}
};

int main()
{
	int x, y; cin >> x >> y;
	x--; y--;

	char input[MAX][MAX + 1] = {};
	queue<Point> q;

	for (int i = 0; i < MAX; i++)
		cin >> input[i];

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			if (input[i][j] == 'o') {
				q.push(Point(i, j));
			}
		}

	while (!q.empty())
	{
		Point cur = q.front(); q.pop();

		for (int i = 0; cur.x + i < 10; i++) 
			board[cur.x + i][cur.y] = true;

		for (int i = 0; cur.x - i >= 0; i++)
			board[cur.x - i][cur.y] = true;

		for (int i = 0; cur.y + i < 10; i++)
			board[cur.x][cur.y + i] = true;

		for (int i = 0; cur.y - i >= 0; i++) {
			board[cur.x][cur.y - i] = true;
		}
		
	}

	queue<Point> save;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (!board[i][j])
				save.push(Point(i, j));

	int res = 21;

	while (!save.empty()) {
		Point cur = save.front(); save.pop();

		int dis = abs(x - cur.x) + abs(y - cur.y);

		if (res > dis)
			res = dis;
	}

	cout << res;

	return 0;
}