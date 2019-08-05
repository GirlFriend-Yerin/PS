/*
	2018 12 31
	1987 ¾ËÆÄºª
	DFS

	- ¼º°ø -
*/
#include <iostream>
#include <string>

using namespace std;

int posX[4] = { 1, 0, -1, 0 };
int posY[4] = { 0, 1, 0 , -1 };
char map[20][20];
int row, col;
int mMax = 1;

void algo(int x, int y, int step, bool alpha[26]) {

	if (alpha[map[x][y] - 'A'])
	{
		if (step > mMax)
			mMax = step;
	}

	alpha[map[x][y] - 'A'] = true;

	for (int i = 0; i < 4; i++) // Right, Bottom, Left, Top
	{
		if (0 <= x + posX[i] && x + posX[i] < row && 0 <= y + posY[i] && y + posY[i] < col)
		{
			int idx = int(map[x + posX[i]][y + posY[i]]) - 'A';
			if (!alpha[idx])
			{
				alpha[idx] = true;
				algo(x + posX[i], y + posY[i], step + 1, alpha);
				alpha[idx] = false;
			}
		}
	}
}

int main()
{
	cin >> row >> col;

	cin.ignore();
	for (int i = 0; i < row; i++)
		cin >> map[i];

	bool alpha[26];
	fill_n(alpha, 26, false);

	algo(0, 0, 1, alpha);

	cout << mMax;

	return 0;
}