#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

const short MAX = 20;

int n;
short board[MAX][MAX];
short fishCount[7];
short sharkSize = 2;
short eatCount = 0;

short posX[4] = { 1, 0 ,-1, 0 };
short posY[4] = { 0, 1, 0, -1 };

struct Point {
	short x;
	short y;

	Point() : x(-1), y(-1) {}
	Point(short x, short y) : x(x), y(y) {}
};

bool continueable(int size) {

	for (int i = 0; i < size; i++)
		if (fishCount[i] > 0)
			return true;
	return false;
}

int getDistance(Point start, Point des) {

	int dist = 0;
	bool check[MAX][MAX] = { };

	queue<Point> q;
	queue<Point> nQ;
	bool isOver = false;
	bool isReachAble = true;

	q.push(start);
	check[start.x][start.y] = true;

	while (!isOver && isReachAble) {

		while (!q.empty()) {

			Point cur = q.front();
			q.pop();

			if (cur.x == des.x && cur.y == des.y)
			{
				isOver = true;
				break;
			}

			for (short i = 0; i < 4; i++) {
				short nextX = cur.x + posX[i];
				short nextY = cur.y + posY[i];

				if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && !check[nextX][nextY] && board[nextX][nextY] <= sharkSize) {
					check[nextX][nextY] = true;
					nQ.push(Point(nextX, nextY));
				}
			}
		}

		if (isOver)
			continue;

		while (!nQ.empty()) {
			q.push(nQ.front());
			nQ.pop();
		}

		if (q.empty())
			isReachAble = false;

		dist++;
	}

	if (!isReachAble)
		dist = 4000;

	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Point shark;

	cin >> n;
	int res = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 9)
			{
				shark.x = i;
				shark.y = j;
				board[i][j] = 0;
			}
			else if (board[i][j]) {
				fishCount[board[i][j]]++;
			}
		}

	while (continueable(sharkSize))
	{
		Point shortestFish;
		int shortest = 500;
		int dist = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] && board[i][j] < sharkSize && abs(shark.x - i) + abs(shark.y - j) < shortest)
				{
					dist = getDistance(shark, Point(i, j));

					if (dist < 400 && shortest > dist)
					{
						shortest = dist;
						shortestFish.x = i; shortestFish.y = j;
					}
				}
			}

		if (shortest == 500)
			break;

		shark = shortestFish;
		eatCount++;
		if (eatCount == sharkSize)
		{
			eatCount = 0;
			sharkSize++;
		}
		res += shortest;

		//cout << "x : " << shortestFish.x << " y : " << shortestFish.y << " dist : " << shortest << " res : " << res << " size : " << sharkSize << " eat : " << eatCount << endl;

		fishCount[board[shortestFish.x][shortestFish.y]]--;
		board[shortestFish.x][shortestFish.y] = 0;
	}

	cout << res;

	return 0;
}