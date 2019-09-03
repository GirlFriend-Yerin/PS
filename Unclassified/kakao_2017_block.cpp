#include <iostream>
#include <vector>
#include <string>

using namespace std;

const short MAX = 30;

int remove(int m, int n, vector<string>& board) {

	int res = 0;
	bool removeState[MAX][MAX] = {};

	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (!board[i][j]) continue;
			if (board[i][j] == board[i][j + 1] && board[i + 1][j] == board[i + 1][j + 1] && board[i][j] == board[i + 1][j])
				for (int k = 0; k < 4; k++) {
					int nextX = i + (k / 2);
					int nextY = j + (k % 2);
					res += !removeState[nextX][nextY];
					removeState[nextX][nextY] = true;
				}
		}
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			board[i][j] = removeState[i][j] ? 0 : board[i][j];

	return res;
}

void pull(int m, int n, vector<string>& board) {

	for (int i = 0; i < n; i++) {
		int tar = 0, pos = 1;
		while (pos < m) {
			while (tar < m && board[tar][i]) tar++;
			pos = tar + 1;
			while (pos < m && !board[pos][i]) pos++;

			if (pos < m) {
				board[tar][i] = board[pos][i];
				board[pos][i] = 0;
			}
		}
	}
}

void print(int m, int n, vector<string>& board) {
	cout << "---------" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << board[i][j];
		cout << endl;
	}
	cout << "---------" << endl;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	for (int i = 0; i < m / 2; i++)
		swap(board[i], board[m - i - 1]);

	int res;
	while (res = remove(m, n, board)) {
		answer += res;

		print(m, n, board);
		pull(m, n, board);
		print(m, n, board);
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, n; cin >> m >> n;
	vector<string> str(m);

	for (int i = 0; i < m; i++)
		cin >> str[i];

	cout << solution(m, n, str);

	return 0;
}