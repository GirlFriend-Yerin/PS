#include <iostream>

using namespace std;

const short MAX = 100;

bool board[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	while (n--) {
		int x, y; cin >> x >> y;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				int nextX = x + i -1;
				int nextY = y + j -1;

				board[nextX][nextY] = true;
			}
		}
	}

	int res = 0;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			res += board[i][j];

	cout << res;
	return 0;
}