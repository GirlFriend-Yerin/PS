/*
	2018 01 18
	1600 ���� �ǰ��� ������
	BFS

	- ���� -
*/
#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

struct Monkey {
	short x;
	short y;
	short jpCount;

	Monkey() {};
	Monkey(short x, short y, short cnt) : x(x), y(y), jpCount(cnt) {};
};

const short posX[12] = { 1, 0, -1, 0 , 1, 2, 2, 1, -1, -2, -2 , -1 };
const short posY[12] = { 0, 1, 0, -1, 2, 1, -1, -2, -2, -1, 1, 2 };
const short MAX = 200;
const short MAX_STEP = 31;

int main()
{
	bool board[MAX][MAX];
	bool isVisited[MAX][MAX][MAX_STEP];
	bool isAdded[MAX][MAX][MAX_STEP];
	queue<Monkey> curQ;
	queue<Monkey> nextQ;
	bool isOver = false;
	int res = 0;

	memset(isVisited, false, sizeof(isVisited));
	memset(isAdded, false, sizeof(isAdded));

	short w, h, jmp;

	cin >> jmp >> w >> h;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> board[i][j]; // 0 - false , 1 - true

	curQ.push(Monkey(0, 0, 0));
	isAdded[0][0][0] = true;

	while (!curQ.empty())
	{
		//cout << "--------" << res << "---------" << endl; For Debug
		while (!curQ.empty())
		{
			Monkey cur = curQ.front();
			curQ.pop();

			if (isVisited[cur.x][cur.y][cur.jpCount])
				continue;

			//cout << cur.x << ", " << cur.y << " - " << cur.jpCount << endl; For Debug

			if (cur.x == h - 1 && cur.y == w - 1) // ��ǥ���� ������
			{
				isOver = true;
				break;
			}

			isVisited[cur.x][cur.y][cur.jpCount] = true;

			for (int i = 0; i < 12; i++)
			{
				if (i > 3 && cur.jpCount >= jmp) // ���� ����
					break;

				int nextX = cur.x + posX[i];
				int nextY = cur.y + posY[i];

				if (0 <= nextX && nextX < h && 0 <= nextY && nextY < w && !board[nextX][nextY] && !isAdded[nextX][nextY][cur.jpCount]) // ����, �� �� �ִ���, �̹� �߰� �Ǿ�����
				{
					if (i < 4) // ����ĭ �̵�
					{
						isAdded[nextX][nextY][cur.jpCount] = true;
						nextQ.push(Monkey(nextX, nextY, cur.jpCount));
					}
					else // ����
					{
						isAdded[nextX][nextY][cur.jpCount+1] = true;
						nextQ.push(Monkey(nextX, nextY, cur.jpCount + 1));
					}
				}
			}
		}

		if (!isOver) // ���� Ȯ��
		{
			while (!nextQ.empty())
			{
				curQ.push(nextQ.front());
				nextQ.pop();
			}
		}
		else
			break;
		res++;
	}

	if (isOver)
		cout << res;
	else
		cout << -1;

	return 0;
}