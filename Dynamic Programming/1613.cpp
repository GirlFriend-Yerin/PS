#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;

	vector<vector<int>> board(n, vector<int>(n, INF));

	for (int i = 0; i < k; i++) {
		int to, des; cin >> to >> des;
		board[to - 1][des - 1] = 1;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				board[k][j] = _min(board[k][j], board[k][i] + board[i][j]);

	int s; cin >> s;
	for (int i = 0; i < s; i++) {
		int his1, his2; cin >> his1 >> his2;
		if (board[his1 - 1][his2 - 1] == board[his2 - 1][his1 - 1]) cout << 0 << '\n';
		else if (board[his1 - 1][his2 - 1] < board[his2 - 1][his1 - 1]) cout << -1 << '\n';
		else cout << 1 << '\n';
	}

	return 0;
}