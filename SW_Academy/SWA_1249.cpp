#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	short x, y;
	int cost;

	Point() {}
	Point(short x, short y, int cost) : x(x), y(y), cost(cost) {}
};

struct cmp {
	bool operator()(Point& p1, Point& p2) {
		return p1.cost > p2.cost;
	}
};

const int MAX = 100;

const short posX[4] = { 1, 0 , -1, 0 };
const short posY[4] = { 0, 1, 0 ,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;
	cin >> tcc;

	for (int i = 1; i <= tcc; i++)
	{
		short n, board[MAX][MAX];
		bool check[MAX][MAX] = {};
		priority_queue<Point, vector<Point>, cmp> pQ;

		cin >> n;

		for (int j = 0; j < n; j++)
		{
			char input[MAX + 1];
			cin >> input;
			for (int k =0 ;k < n; k++)
				board[j][k] = input[k] - '0';
		}

		check[0][0] = true;
		pQ.push(Point(0, 0, 0));

		while (!pQ.empty())
		{
			Point cur = pQ.top();
			pQ.pop();

			if (cur.x == n - 1 && cur.y == n - 1)
			{
				cout << '#' << i << ' ' << cur.cost << '\n';
				break;
			}

			for (int j = 0; j < 4; j++)
			{
				short nextX = cur.x + posX[j];
				short nextY = cur.y + posY[j];

				if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && !check[nextX][nextY])
				{
					check[nextX][nextY] = true;
					pQ.push(Point(nextX, nextY, cur.cost + board[nextX][nextY]));
				}
			}
		}
	}

	return 0;
}