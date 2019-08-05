#include <iostream>
#include <queue>

using namespace std;

const short MAX = 32;

bool board[MAX][MAX];
int n;
const short posX[3] = { 1, 0, 1 };
const short posY[3] = { 0, 1, 1 };

struct Point {
	short x, y;
	short look;

	Point(short x, short y, short l) : x(x), y(y), look(l) {};
	Point();
};

bool checkAble(short sX, short sY, short eX, short eY)
{
	for (int i = sX; i <= eX; i++)
		for (int j = sY; j <= eY; j++)
			if (board[j][i])
				return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int res = 0;
	queue<Point> q;

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	q.push(Point(1, 0, 0));

	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		if (cur.x == n - 1 && cur.y == n - 1)
		{
			res++;
			continue;
		}

		for (int i = 0; i < 3; i++)
		{
			int nextX = cur.x + posX[i];
			int nextY = cur.y + posY[i];

			if (nextX >= n || nextY >= n || (cur.look == 0 && i == 1) || (cur.look == 1 && i == 0))
				continue;

			if (checkAble(cur.x, cur.y, nextX, nextY))
				q.push(Point(nextX, nextY, i));
		}
	}

	cout << res;

	return 0;
}