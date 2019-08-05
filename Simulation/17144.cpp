/*
	2019 04 17
	17144 미세먼지 안녕!
	시뮬레이션

	- 성공 -
*/
#include <iostream>

using namespace std;

const short MAX = 50;

const short posX[4] = { 1, 0, -1, 0 };
const short posY[4] = { 0, 1, 0, -1 };

short board[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int row, col, time;
	int airCleanTop = -1, airCleanBottom;

	cin >> row >> col >> time;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == -1 && airCleanTop == -1)
				airCleanTop = i;
		}
	}

	airCleanBottom = airCleanTop + 1;

	for (int tc = 0; tc < time; tc++) {
		short tempBoard[MAX][MAX];

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				tempBoard[i][j] = board[i][j];
				board[i][j] = 0;
			}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++)
			{
				if (!tempBoard[i][j])
					continue;

				if (tempBoard[i][j] < 5)
					board[i][j] += tempBoard[i][j];
				else
				{
					int count = 0;
					for (int k = 0; k < 4; k++) {
						int nextX = i + posX[k];
						int nextY = j + posY[k];
						if (0 <= nextX && nextX < row && 0 <= nextY && nextY < col && tempBoard[nextX][nextY] != -1)
							count++;
					}

					int spread = tempBoard[i][j] / 5;

					board[i][j] += tempBoard[i][j] - (spread * count);

					for (int k = 0; k < 4; k++) {
						int nextX = i + posX[k];
						int nextY = j + posY[k];
						if (0 <= nextX && nextX < row && 0 <= nextY && nextY < col && tempBoard[nextX][nextY] != -1)
							board[nextX][nextY] += spread;
					}
				}
			}
		}
		// Rotation
		// Top
		for (int i = airCleanTop - 1; i > 0; i--)
			board[i][0] = board[i - 1][0];
		for (int i = 0; i < col - 1; i++)
			board[0][i] = board[0][i + 1];
		for (int i = 0; i < airCleanTop; i++)
			board[i][col -1] = board[i + 1][col -1];
		for (int i = col - 1; i > 1; i--)
			board[airCleanTop][i] = board[airCleanTop][i - 1];

		// Bottom
		for (int i = airCleanBottom + 1; i < row - 1; i++)
			board[i][0] = board[i + 1][0];
		for (int i = 0; i < col - 1; i++)
			board[row - 1][i] = board[row - 1][i + 1];
		for (int i = row - 1; i > airCleanBottom; i--)
			board[i][col - 1] = board[i-1][col - 1];
		for (int i = col - 1; i > 1; i--)
			board[airCleanBottom][i] = board[airCleanBottom][i-1];

		board[airCleanTop][1] = board[airCleanBottom][1] = 0;
	}

	int res = 0;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (board[i][j] > 0)
				res += board[i][j];

	cout << res;

	return 0;
}