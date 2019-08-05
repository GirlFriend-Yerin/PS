#include <iostream>

using namespace std;

const short MAX = 500;
const short TETRO_MAX = 19;

short board[MAX][MAX];

const short sizeX[TETRO_MAX] = { 4, 1, 2, 2, 2, 3, 2, 3, 2, 2, 3, 3, 2, 3, 2, 3, 2, 3, 3 };
const short sizeY[TETRO_MAX] = { 1, 4, 2, 3, 3, 2, 3, 2, 3, 3, 2, 2, 3, 2, 3, 2, 3, 2, 2 };

bool tetro[TETRO_MAX][4][4];

void initTetro()
{
	tetro[0][0][0] = tetro[0][1][0] = tetro[0][2][0] = tetro[0][3][0] = 1;
	tetro[1][0][0] = tetro[1][0][1] = tetro[1][0][2] = tetro[1][0][3] = 1;
	tetro[2][0][0] = tetro[2][0][1] = tetro[2][1][0] = tetro[2][1][1] = 1;
	tetro[3][0][0] = tetro[3][0][1] = tetro[3][0][2] = tetro[3][1][2] = 1;
	tetro[4][1][0] = tetro[4][1][1] = tetro[4][1][2] = tetro[4][0][2] = 1;
	tetro[5][0][0] = tetro[5][0][1] = tetro[5][1][0] = tetro[5][2][0] = 1;
	tetro[6][0][0] = tetro[6][1][0] = tetro[6][1][1] = tetro[6][1][2] = 1;
	tetro[7][0][1] = tetro[7][1][1] = tetro[7][2][1] = tetro[7][2][0] = 1;
	tetro[8][0][0] = tetro[8][0][1] = tetro[8][1][1] = tetro[8][1][2] = 1;
	tetro[9][1][0] = tetro[9][1][1] = tetro[9][0][1] = tetro[9][0][2] = 1;
	tetro[10][0][1] = tetro[10][1][1] = tetro[10][1][0] = tetro[10][2][0] = 1;
	tetro[11][0][0] = tetro[11][1][0] = tetro[11][2][0] = tetro[11][1][1] = 1;
	tetro[12][1][0] = tetro[12][1][1] = tetro[12][1][2] = tetro[12][0][1] = 1;
	tetro[13][1][0] = tetro[13][0][1] = tetro[13][1][1] = tetro[13][2][1] = 1;
	tetro[14][0][0] = tetro[14][0][1] = tetro[14][0][2] = tetro[14][1][1] = 1;
	tetro[15][0][0] = tetro[15][0][1] = tetro[15][1][1] = tetro[15][2][1] = 1;
	tetro[16][0][0] = tetro[16][1][0] = tetro[16][0][1] = tetro[16][0][2] = 1;
	tetro[17][0][0] = tetro[17][1][0] = tetro[17][2][0] = tetro[17][2][1] = 1;
	tetro[18][0][0] = tetro[18][1][0] = tetro[18][1][1] = tetro[18][2][1] = 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	initTetro();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int res = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < TETRO_MAX; k++) {
				short ranX = j + sizeX[k];
				short ranY = i + sizeY[k];

				if (0 <= ranX && ranX <= m && 0 <= ranY && ranY <= n) {
					int sum = 0;

					for (int row = 0; row < sizeX[k]; row++)
						for (int col = 0; col < sizeY[k]; col++) {
							sum += board[i + col][j + row] * tetro[k][row][col];
						}

					if (res < sum)
						res = sum;
				}
			}
		}
	}

	cout << res;

	return 0;
}