/*
	2019 02 02
	2573 ����
	bfs

	- ���� -
*/
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 300;
const short posX[4] = { 1, 0, -1, 0 };
const short posY[4] = { 0, 1, 0, -1 };
short board[MAX + 1][MAX + 1];

int n, m;

struct Ice {
	short x;
	short y;
	short val;

	Ice() : x(0), y(0), val(0) {};
	Ice(short x, short y, short v) : x(x), y(y), val(v) {};
};

int countIcePiece()
{
	queue<Ice> q;
	int ret = 0;

	bool check[MAX + 1][MAX + 1] = {};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (!board[i][j] || check[i][j])
				continue;

			q.push(Ice(i, j, 0)); // ���� ��ġ�� ����
			check[i][j] = true; // ���� ��ġ�� �湮�� ������ �Ǻ�

			while (!q.empty())
			{
				Ice cur = q.front();
				q.pop();

				for (int i = 0; i < 4; i++)
				{
					short nextX = cur.x + posX[i];
					short nextY = cur.y + posY[i];

					if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m && board[nextX][nextY] && !check[nextX][nextY]) // ������ �κ��� Push
					{
						check[nextX][nextY] = true;
						q.push(Ice(nextX, nextY, 0));
					}
				}
			}
			++ret;
		}
	}

	return ret;
}

int main()
{
	queue<Ice> iceberg;
	queue<Ice> meltIce;
	int turn = 0;
	int piece = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j])
				iceberg.push(Ice(i, j, board[i][j]));
		}

	while ((piece = countIcePiece()) == 1) // ���� ���� ��� ���� ���ϰ� �����Ѵ�.(���� ��� �Ǻ���)
	{
		while (!iceberg.empty())
		{
			Ice cur = iceberg.front();
			iceberg.pop();

			int count = 0;
			for (int i = 0; i < 4; i++)
			{
				short nextX = cur.x + posX[i];
				short nextY = cur.y + posY[i];

				if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m && !board[nextX][nextY]) // �ٴ幰�� �κ��� ���� ���Ѵ�.
					++count;
			}
			meltIce.push(Ice(cur.x, cur.y, count)); // ���� �κ��� �����Ų��.
		}

		while (!meltIce.empty())
		{
			Ice cur = meltIce.front();
			meltIce.pop();

			if ((board[cur.x][cur.y] -= cur.val < board[cur.x][cur.y] ? cur.val : board[cur.x][cur.y])) // ���� ���� ���� ������ ũ�� ���� ���� ����.
				iceberg.push(Ice(cur.x, cur.y, board[cur.x][cur.y])); // ���ϰ� �� ��Ƴ��� �� �ִٸ� �ٽ� �����Ѵ�.
		}
		++turn; // �� �߰�
	}

	if (piece > 1) // �� ��� �̻����� �и� �� ���
		cout << turn;
	else // ���� ���� ���
		cout << 0;

	return 0;
}