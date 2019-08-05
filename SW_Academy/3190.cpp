#include <iostream>

using namespace std;

struct Point
{
	short x;
	short y;

	Point() {}
	Point(short x, short y) : x(x), y(y) {};
};

const short MAX = 100;
const short T_MAX = 10000;
bool apples[MAX][MAX];
char orders[T_MAX+1];
Point snake[MAX + 1];
int snakeLen = 1;

const short posX[4] = { 0, 1, 0, -1 };
const short posY[4] = { 1, 0, -1, 0 };

void shift(short x, short y)
{
	for (int i = 0; i < snakeLen - 1; i++)
		snake[i] = snake[i + 1];

	snake[snakeLen - 1].x = x; snake[snakeLen - 1].y = y;
}

bool isCross(short x, short y)
{
	for (int i = 0; i < snakeLen; i++)
		if (snake[i].x == x && snake[i].y == y)
			return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, apple, cc, res = 1;
	int look = 0;

	cin >> n >> apple;
	for (int i = 0; i < apple; i++)
	{
		short x, y;
		cin >> x >> y;
		apples[x - 1][y - 1] = true;
	}

	cin >> cc;
	for (int i = 0; i < cc; i++)
	{
		int turn;
		cin >> turn;
		cin >> orders[turn];
	}

	snake[0].x = snake[0].y = 0;

	for (; res < T_MAX; res++)
	{
		short nextX = snake[snakeLen - 1].x + posX[look];
		short nextY = snake[snakeLen - 1].y + posY[look];

		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n)
		{
			if (isCross(nextX, nextY))
				break;

			if (apples[nextX][nextY])
			{
				apples[nextX][nextY] = false;
				snake[snakeLen].x = nextX; snake[snakeLen].y = nextY;
				snakeLen++;
			}
			else
				shift(nextX, nextY);
		}
		else
			break;

		if (orders[res])
		{
			if (orders[res] == 'D')
				look = (look + 1) % 4;
			else
				look = look - 1 < 0 ? 3 : look - 1;
		}
	}

	cout << res;

	return 0;
}