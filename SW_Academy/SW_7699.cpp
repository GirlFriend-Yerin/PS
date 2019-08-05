#include <iostream>

using namespace std;

const short MAX = 20;

int row, col;
char board[MAX][MAX + 1];
bool check[26];

const short posX[4] = { 1, 0, -1, 0 };
const short posY[4] = { 0 ,1, 0, -1 };

int dfs(int curX, int curY, int count) {

	int res = count;

	for (int i = 0; i < 4; i++) {
		short nextX = curX + posX[i];
		short nextY = curY + posY[i];

		if (0 <= nextX && nextX < row && 0 <= nextY && nextY < col) {
			short alphaIdx = board[nextX][nextY] - 'A';

			if (!check[alphaIdx]) {
				check[alphaIdx] = true;
				int cur = dfs(nextX, nextY, count + 1);

				if (res < cur)
					res = cur;

				check[alphaIdx] = false;
			}
				
		}
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {

		cin >> row >> col;

		for (int i = 0; i < row; i++)
			cin >> board[i];

		short start = board[0][0] - 'A';
		check[start] = true;
		int res = dfs(0, 0, 1);
		check[start] = false;
		

		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}