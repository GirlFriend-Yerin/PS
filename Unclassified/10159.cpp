#include <iostream>

using namespace std;

const int MAX = 100;
const int INF = 1e9 + 7;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	int board[MAX][MAX] = {};

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		board[a - 1][b - 1] = 1;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (board[j][i] && board[i][k])
					board[j][k] = 1;

	for (int i = 0; i < n; i++) {
		int res = 0;
		for (int j = 0; j < n; j++)
			res += !board[i][j] && !board[j][i];
		cout << res - 1 << '\n';
	}

	return 0;
}