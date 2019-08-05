#include <iostream>
#include <queue>

using namespace std;

const int MAX = 30;

const short posX[6] = { 1, 0, -1, 0, 0, 0 };
const short posY[6] = { 0, 1, 0, -1, 0, 0 };
const short posZ[6] = { 0, 0, 0, 0, 1, -1 };

struct Point {
	short x;
	short y;
	short z;

	Point() : x(0), y(0), z(0) {};
	Point(short x, short y, short z) : x(x), y(y), z(z) {};
};

int main()
{
	int l, r, c;

	cin >> l >> r >> c;

	while (l && r && c)
	{
		bool isSuccess = false;
		int time = 0;
		char board[MAX][MAX][MAX + 1] = {};
		bool visited[MAX][MAX][MAX] = {};
		queue<Point> q;
		queue<Point> nextQ;
		Point start, des;

		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
			{
				cin >> board[i][j];

				for (int k = 0; k < c; k++)
				{
					if (board[i][j][k] == 'S')
						start = Point(j, k, i);
					else if (board[i][j][k] == 'E')
						des = Point(j, k, i);
				}
			}

		q.push(start);
		visited[start.z][start.x][start.y] = true;

		while (!q.empty())
		{
			while (!q.empty())
			{
				Point cur = q.front();
				q.pop();

				if (cur.x == des.x && cur.y == des.y && cur.z == des.z)
				{
					isSuccess = true;
					break;
				}

				for (int i = 0; i < 6; i++)
				{
					short nextX = cur.x + posX[i];
					short nextY = cur.y + posY[i];
					short nextZ = cur.z + posZ[i];

					if (0 <= nextX && nextX < r && 0 <= nextY && nextY < c && 0 <= nextZ && nextZ < l && board[nextZ][nextX][nextY] != '#' && !visited[nextZ][nextX][nextY])
					{
						visited[nextZ][nextX][nextY] = true;
						nextQ.push(Point(nextX, nextY, nextZ));
					}
				}
			}

			if (isSuccess)
				break;

			while (!nextQ.empty())
			{
				q.push(nextQ.front());
				nextQ.pop();
			}

			time++;
		}

		if (isSuccess)
			cout << "Escaped in " << time << " minute(s).\n";
		else
			cout << "Trapped!\n";

		cin >> l >> r >> c;
	}
	
	return 0;
}