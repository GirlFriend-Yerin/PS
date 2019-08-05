/*
	2019 01 12
	11559 Puyo Pyuo
	BFS

	- 성공 -
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int ROW = 12;
const int COL = 6;
const int MAX_LABEL = 72;

char board[ROW][COL+1];
const short posX[4] = { 1, 0, -1, 0 };
const short posY[4] = { 0, 1, 0, -1 };

struct Point {
	short x;
	short y;

	Point() {}
	Point(short x, short y) : x(x), y(y) {}
};

bool removePuyo()
{
	bool res = false;
	queue<Point> q;
	vector<int> connectCount(MAX_LABEL);

	// 제거
	int label = 1;
	short visitTable[ROW][COL] = {};

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (visitTable[i][j] != 0 || board[i][j] == '.')
				continue;

			q.push(Point(i, j));

			while (!q.empty())
			{
				Point cur = q.front();
				q.pop();

				if (visitTable[cur.x][cur.y])
					continue;

				visitTable[cur.x][cur.y] = label;
				connectCount[label -1]++;

				for (int pos = 0; pos < 4; pos++)
				{
					short nextX = cur.x + posX[pos];
					short nextY = cur.y + posY[pos];

					if (0 <= nextX && nextX < ROW && 0 <= nextY && nextY < COL)
						if (board[nextX][nextY] != '.' && board[nextX][nextY] == board[cur.x][cur.y])
							q.push(Point(nextX, nextY));
				}
			}

			label++;
		}
	}

	for (int i = 0; i < MAX_LABEL; i++)
	{
		// 값이 4가 넘는 경우에만 터진 것으로 판정
		if (connectCount[i] < 4)
			continue;

		// 터진 경우가 존재한다.
		if (res == false)
			res = true;

		for (int j = 0; j < ROW; j++)
			for (int k = 0; k < COL; k++)
				if (visitTable[j][k] == i+1)
					board[j][k] = '.';
	}

	return res;
}

void refreshBoard()
{
	for (int i = 0; i < COL; i++)
	{
		int target = 1, base = 0; // 목표지점, 현재 지점

		while (base + target < ROW)
		{
			if (board[base][i] != '.') // 공백 지점 탐색
				base++;
			else if (board[target + base][i] == '.') // 바꿔야할 지점 탐색
				target++;
			else // 현재 지점이 공백 이면서 바꿔야 할 지점이 Puyo인 경우
			{
				swap(board[base][i], board[base + target][i]);
				base++;
				target = 1;
			}
		}
	}
}

int solution()
{
	int count = 0;
	// 제거 및 확인 // 제거되면 +1
	for (; removePuyo(); count++)
		refreshBoard(); // 빈칸 채우기
	
	return count;
}

int main()
{
	for (int i = ROW - 1; i >= 0 ; --i)
		cin >> board[i];

	cout << solution();

	return 0;
}