/*
	2019 1 1
	2468 - 안전 영역
	BFS

	- 성공 -
*/

#include <iostream>
#include <queue>

using namespace std;

struct mPoint {
	int x;
	int y;

	mPoint() {};
	mPoint(int x, int y) : x(x), y(y) {};
};

const int posX[4] = { 1, 0, -1, 0 };
const int posY[4] = { 0, 1, 0, -1 };

int func(bool zone[100][100], int n)
{
	int fieldCount = 0;

	queue<mPoint> q;
	bool check[100][100];

	for (int i = 0; i < n; i++)
		fill_n(check[i], n, false);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (!zone[i][j] || check[i][j])
				continue;

			q.push(mPoint(i, j));

			while (!q.empty())
			{
				mPoint cur = q.front();
				q.pop();

				if (check[cur.x][cur.y])
					continue;

				check[cur.x][cur.y] = true;

				// check Field
				for (int pos = 0; pos < 4; pos++)
					if (0 <= cur.x + posX[pos] && cur.x + posX[pos] < n && 0 <= cur.y + posY[pos] && cur.y + posY[pos] < n)
					{
						if (zone[cur.x+posX[pos]][cur.y+posY[pos]])
							q.push(mPoint(cur.x + posX[pos], cur.y + posY[pos]));
					}
						
			}

			fieldCount++;
		}
	
	return fieldCount;
}

void checkSafe(const int map[100][100],bool zone[100][100], int n, int water)
{
	for (int i = 0 ; i < n ;i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] <= water)
				zone[i][j] = false;
			else
				zone[i][j] = true;
		}
}

int main()
{
	int maxHeight = 0;
	int maxCount = 0;
	int n;
	int map[100][100];

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (maxHeight < map[i][j])
				maxHeight = map[i][j];
		}
			
	for (int i = 0; i < maxHeight; i++)
	{
		bool safeZone[100][100];
		
		checkSafe(map, safeZone, n, i);

		int safe = func(safeZone, n);
		if (maxCount < safe)
			maxCount = safe;
	}

	cout << maxCount;

	return 0;
}