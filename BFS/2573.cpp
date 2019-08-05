/*
	2019 02 02
	2573 빙하
	bfs

	- 성공 -
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

			q.push(Ice(i, j, 0)); // 현재 위치를 저장
			check[i][j] = true; // 현재 위치를 방문한 것으로 판별

			while (!q.empty())
			{
				Ice cur = q.front();
				q.pop();

				for (int i = 0; i < 4; i++)
				{
					short nextX = cur.x + posX[i];
					short nextY = cur.y + posY[i];

					if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m && board[nextX][nextY] && !check[nextX][nextY]) // 빙하인 부분을 Push
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

	while ((piece = countIcePiece()) == 1) // 현재 빙하 덩어리 수를 구하고 저장한다.(빙하 덩어리 판별용)
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

				if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m && !board[nextX][nextY]) // 바닷물인 부분의 수를 구한다.
					++count;
			}
			meltIce.push(Ice(cur.x, cur.y, count)); // 녹일 부분을 저장시킨다.
		}

		while (!meltIce.empty())
		{
			Ice cur = meltIce.front();
			meltIce.pop();

			if ((board[cur.x][cur.y] -= cur.val < board[cur.x][cur.y] ? cur.val : board[cur.x][cur.y])) // 녹을 값이 현재 값보다 크면 현재 값을 뺀다.
				iceberg.push(Ice(cur.x, cur.y, board[cur.x][cur.y])); // 빙하가 더 녹아내릴 수 있다면 다시 저장한다.
		}
		++turn; // 해 추가
	}

	if (piece > 1) // 두 덩어리 이상으로 분리 된 경우
		cout << turn;
	else // 전부 녹은 경우
		cout << 0;

	return 0;
}