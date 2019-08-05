/*
	2019 01 08
	15683 감시
	Brute force

	-  -
*/
#include <iostream>

using namespace std;

struct CCTV
{
	int x;
	int y;
	int type;

	CCTV() : x(0), y(0), type(0) {};
	CCTV(int x, int y, int type) : x(y), y(x), type(type) {};
};

CCTV cctvs[8];

int see[8];
int rooms[8][8];
int cctvCount;
int myMin = 65;
int cctvSee[8];
int n, m;
const int posX[4] = { 0, 1, 0, -1 };
const int posY[4] = { 1, 0, -1, 0 };

void func(int pos)
{
	if (pos == cctvCount)
	{
		int count = 0;

		bool blind[8][8];

		for (int i = 0; i < n; i++)
			fill_n(blind[i], m, true);

		for (int i = 0; i < pos; i++)
		{
			blind[cctvs[i].x][cctvs[i].y] = false;
			bool canShow[4] = { false, false, false, false };
			bool blocked[4] = { false, false, false, false };

			if (cctvs[i].type == 1)
				canShow[cctvSee[i] - 1] = true;
			else if (cctvs[i].type == 2)
				canShow[cctvSee[i] - 1] = canShow[(cctvSee[i] + 1) % 4] = true;
			else if (cctvs[i].type == 3)
				canShow[cctvSee[i] - 1] = canShow[cctvSee[i] % 4] = true;
			else if (cctvs[i].type == 4)
				canShow[cctvSee[i] - 1] = canShow[cctvSee[i] % 4] = canShow[(cctvSee[i] + 1) % 4] = true;
			else
				for (int j = 0; j < 4; j++)
					canShow[j] = true;

			for (int step = 1; (canShow[0] && !blocked[0]) || (canShow[1] && !blocked[1]) || (canShow[2] && !blocked[2]) || (canShow[3] && !blocked[3]); step++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (blocked[j] || !canShow[j]) // 막혔거나 감시가 불가하면 continue
						continue;

					int x = cctvs[i].x + (posX[j] * step);
					int y = cctvs[i].y + (posY[j] * step);

					if (0 <= x && x < n && 0 <= y && y < m) // 범위를 넘지 않으면 진행
					{
						if (rooms[x][y] == 6)
						{
							blocked[j] = true;
							continue;
						}
						if (!blind[x][y])
							continue;

						blind[x][y] = false;
					}
					else
						blocked[j] = true;
				}
			}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (blind[i][j] && rooms[i][j] != 6)
					count++;

		if (myMin > count)
			myMin = count;
	}
	else
	{
		if (cctvs[pos].type == 2) // 양방향 cctv의 경우 2가지 경우
		{
			for (int i = 0; i < 2; i++)
			{
				cctvSee[pos]++;
				func(pos + 1);
			}
			cctvSee[pos] = 0;
		}
		else if (cctvs[pos].type == 5) // 전방향 cctv의 경우 1가지 경우
		{
			func(pos + 1);
		}
		else
		{
			for (int i = 0; i < 4; i++) // 나머지 cctv는 4가지 경우
			{
				cctvSee[pos]++;
				func(pos + 1);
			}
			cctvSee[pos] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> rooms[i][j];
			if (rooms[i][j] != 0 && rooms[i][j] != 6)
			{
				cctvs[cctvCount].x = i;
				cctvs[cctvCount].y = j;
				cctvs[cctvCount].type = rooms[i][j];
				cctvCount++;
			}
		}

	func(0);

	cout << myMin;

	return 0;
}