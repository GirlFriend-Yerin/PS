#include <iostream>

using namespace std;

const short MAX = 16;
const int QMAX = 100000;
const short posX[4] = { 0, 1, 0, -1 };
const short posY[4] = { 1, 0, -1, 0 };

struct Point {
	short x, y;

	Point(short x, short y) : x(x), y(y) {};
	Point() {};
};

char board[MAX][MAX];
Point queue[QMAX];
int head = 0;
int tail = 0;

void push(Point p) { queue[head++ % QMAX] = p; }
Point pop() { return queue[tail++ % QMAX]; }
bool isEmpty() { return head == tail; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc = 2;

	for (int tc = 0; tc < tcc; tc++)
	{
		int tcNum;

		cin >> tcNum;
		bool checker[MAX][MAX] = {};
		int res = 0;
		Point startPoint;
		Point desPoint;

		for (int i = 0; i < MAX; i++)
		{
			cin >> board[i];
			for (int j = 0; j < MAX; j++)
				if (board[i][j] == '2')
				{
					startPoint.x = i;
					startPoint.y = j;
				}
				else if (board[i][j] == '3')
				{
					desPoint.x = i;
					desPoint.y = j;
				}
		}

		push(startPoint);
		checker[startPoint.x][startPoint.y] = true;

		while (!isEmpty())
		{
			Point cur = pop();

			if (cur.x == desPoint.x && cur.y == desPoint.y)
			{
				res = 1;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				short nextX = cur.x + posX[i];
				short nextY = cur.y + posY[i];

				if (0 <= nextX && nextX < MAX && 0 <= nextY && nextY < MAX && board[nextX][nextY] != '1' && !checker[nextX][nextY])
				{
					checker[nextX][nextY] = true;
					push(Point(nextX, nextY));
				}
			}
		}

		cout << '#' << tcNum << ' ' << res << '\n';
	}

	return 0;
}