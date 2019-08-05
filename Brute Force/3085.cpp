#include <iostream>

using namespace std;

const short MAX = 50;

char board[MAX][MAX+1];

int posX[] = { 1, 0 };
int posY[] = { 0, 1 };

int calXChain(int y,int n) {
	int res = 0;

	for (int i = 0; i < n;)
	{
		int chain = 0;
		for (int j = 0; i + j < n; j++) {
			if (board[i][y] == board[i + j][y])
				chain++;
			else
				break;
		}
		if (res < chain)
			res = chain;
		i += chain;
	}
	return res;
}
int calYChain(int x, int n) {
	int res = 0;

	for (int i = 0; i < n;)
	{
		int chain = 0;
		for (int j = 0; i + j < n; j++) {
			if (board[x][i] == board[x][i+j])
				chain++;
			else
				break;
		}
		if (res < chain)
			res = chain;
		i += chain;
	}
	return res;
}

int calMaxChain(int n) {
	int res = 0;

	for (int i = 0; i < n; i++) {
		int calX = calXChain(i, n);
		int calY = calYChain(i, n);
		if (res < calX)
			res = calX;
		if (res < calY)
			res = calY;
	}

	return res;
}

int main()
{
	int n; cin >> n;
	int res = 0;

	for (int i = 0; i < n; i++)
		cin >> board[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 2; k++) {
				int nextX = i + posX[k];
				int nextY = j + posY[k];
				if (nextX < n && nextY < n) {
					swap(board[i][j], board[nextX][nextY]);
					int cal = calMaxChain(n);
					if (res < cal)
						res = cal;
					swap(board[i][j], board[nextX][nextY]);
				}
			}
		}
	}

	cout << res;

	return 0;
}