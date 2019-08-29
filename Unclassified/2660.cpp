#include <iostream>

using namespace std;

const short MAX = 50;
const int INF = 1e9 + 7;

int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }
int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int board[MAX][MAX] = {};

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = i != j ? INF : 0;

	int a, b; cin >> a >> b;
	while (a != -1 && b != -1) {
		board[a - 1][b - 1] = board[b - 1][a - 1] = 1;
		cin >> a >> b;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				board[j][k] = _min(board[j][k], board[j][i] + board[i][k]);

	int hoobo = -1;
	int score[MAX] = {};
	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < n; j++) max = _max(max, board[i][j]);

		score[i] = max;

		hoobo = hoobo == -1 ? max : _min(hoobo, max);
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (score[i] == hoobo) {
			count++;
		}
	}
	cout << hoobo << " " << count << '\n';
	for (int i = 0; i < n; i++) {
		if (score[i] == hoobo) {
			cout << i + 1 << " ";
		}
	}

	return 0;
}