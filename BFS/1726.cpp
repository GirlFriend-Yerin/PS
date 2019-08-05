/*
	2019 01 22
	1726 ·Îº¿
	BFS

	- ¼º°ø -
*/
#include <iostream>
#include <queue>

using namespace std;

struct Point {
	short x;
	short y;
	short look;
	int count;

	Point() : count(0) {};
	Point(short x, short y, short look, int count) : x(x), y(y), look(look), count(count) {}
	bool operator==(Point& p) { return x == p.x && y == p.y && look == p.look; }
};

const short MAX = 100;

bool board[MAX + 1][MAX + 1];
bool check[MAX + 1][MAX + 1][4]; // row col look
const short posX[4] = { 0, 0, 1, -1 };
const short posY[4] = { 1, -1, 0, 0 };

int main()
{
	short row, col;
	queue<Point> q;
	Point start, des;
	Point res;

	cin >> row >> col;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> board[i][j];

	cin >> start.x >> start.y >> start.look;
	cin >> des.x >> des.y >> des.look;

	--start.x; --start.y; --start.look; --des.x; --des.y; --des.look;

	q.push(start);

	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		if (check[cur.x][cur.y][cur.look])
			continue;

		//cout << cur.x << ' ' << cur.y << ' ' << cur.look << " / " << cur.count << endl; // For debug

		if (cur == des)
		{
			res.count = cur.count;
			break;
		}

		check[cur.x][cur.y][cur.look] = true;

		// N S <-> W,E 
		for (int i = 0; i < 2; i++)
		{
			short nextLook = !(cur.look / 2) * 2 + i;
			if (!check[cur.x][cur.y][nextLook])
				q.push(Point(cur.x, cur.y, nextLook, cur.count + 1));
		}

		for (int i = 1; i <= 3; i++)
		{
			short nextX = cur.x + posX[cur.look] * i; // go i block
			short nextY = cur.y + posY[cur.look] * i;

			if (board[nextX][nextY]) // check wall
				break;

			if (0 <= nextX && nextX < row && 0 <= nextY && nextY < col && !check[nextX][nextY][cur.look])
					q.push(Point(nextX, nextY, cur.look, cur.count + 1));
		}
	}

	cout << res.count;

	return 0;
}