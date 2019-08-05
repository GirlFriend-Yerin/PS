/*
	2018 12 26
	2583 - 영역 구하기
	BFS

	- 성공 -
*/

#include <iostream>
#include <queue>

using namespace std;

int paper[100][100];
int checkMap[100][100];
int mSize[500];

struct Point
{
	int x, y;

	Point(int x, int y) : y(y), x(x) {}
};

int main()
{
	// m - row, n - col, k - count
	int m, n, k;
	int label = 1;
	queue<Point> q;

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int sx, sy, ex, ey; // start_x, start_y, end_x, end_y

		cin >> sx >> sy >> ex >> ey;

		for (int j = sx; j < ex; j++)
			for (int k = sy; k < ey; k++)
				paper[j][k] = 1;
	}

	// 4 - Connectivity Labeling
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (checkMap[j][i] == 0 && paper[j][i] == 0)
			{
				q.push(Point(i,j));
				checkMap[j][i] = label;

				while (!q.empty())
				{
					Point cur = q.front();
					q.pop();

					// Size Acc
					mSize[label - 1]++;

					// check Right
					if (checkMap[cur.y + 1][cur.x] == 0 && paper[cur.y + 1][cur.x] == 0 && cur.y+1 < n)
					{
						q.push(Point(cur.x, cur.y + 1));
						checkMap[cur.y + 1][cur.x] = label;
					}

					// check Bottom
					if (checkMap[cur.y][cur.x + 1] == 0 && paper[cur.y ][cur.x + 1] == 0 && cur.x+1 < m)
					{
						q.push(Point(cur.x + 1, cur.y));
						checkMap[cur.y][cur.x + 1] = label;
					}
					
					// check Left
					if (cur.y - 1 >= 0)
					{
						if (checkMap[cur.y - 1][cur.x] == 0 && paper[cur.y - 1][cur.x] == 0)
						{
							q.push(Point(cur.x, cur.y - 1));
							checkMap[cur.y - 1][cur.x] = label;
						}
					}

					// check Top
					if (cur.x - 1 >= 0)
					{
						if (checkMap[cur.y][cur.x - 1] == 0 && paper[cur.y][cur.x - 1] == 0)
						{
							q.push(Point(cur.x - 1, cur.y));
							checkMap[cur.y][cur.x - 1] = label;
						}
					}
				}

				// NextLabel Number;
				label++;
			}
		}
	}
	cout << label - 1 << endl;
	
	// Selection Sort
	for (int i = 0; i < label - 1; i++)
	{
		int max = i;
		for (int j = i; j < label - 1; j++)
		{
			if (mSize[max] > mSize[j])
				max = j;
		}
		swap(mSize[max], mSize[i]);
	}

	for (int i = 0; i < label-1; i++)
		cout << mSize[i] << " ";

	return 0;
}