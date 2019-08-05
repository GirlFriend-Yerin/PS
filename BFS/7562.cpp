/*
	2019 01 09
	7562 나이트의 이동
	BFS

	- 성공 -
*/
#include <iostream>
#include <queue>

using namespace std;

const short posX[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const short posY[8] = { -2, -1, 1 ,2 , 2, 1, -1, -2 };

struct Point {
	short x;
	short y;

	Point() {}
	Point(short x, short y) : x(x), y(y) {}
};

int solution(int n, Point start, Point des)
{
	bool check[301][301];
	queue<Point> currentQ;
	queue<Point> nextQ;
	int result = 0;
	bool isFind = false;

	for (int i = 0; i < n; i++)
		fill_n(check[i], n, false);

	currentQ.push(start);

	while (!isFind)
	{
		while (!currentQ.empty())
		{
			Point cur = currentQ.front();
			currentQ.pop();

			if (cur.x == des.x && cur.y == des.y)
			{
				isFind = true;
				break;
			}

			if (check[cur.x][cur.y])
				continue;

			check[cur.x][cur.y] = true;

			for (int i = 0; i < 8; i++)
			{
				int nextX = cur.x + posX[i];
				int nextY = cur.y + posY[i];

				if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && !check[nextX][nextY])
					nextQ.push(Point(nextX, nextY));
			}
		}

		if (isFind)
			break;

		while (!nextQ.empty())
		{
			currentQ.push(nextQ.front());
			nextQ.pop();
		}
		result++;
	}

	return result;
}

int main()
{
	int tcc;

	cin >> tcc;

	for (int i = 0; i < tcc; i++)
	{
		int l;
		short x1, y1, x2, y2;

		cin >> l >> x1 >> y1 >> x2 >> y2;

		int res = solution(l, Point(x1, y1), Point(x2, y2));
		cout << res << endl;
	}

	return 0;
}