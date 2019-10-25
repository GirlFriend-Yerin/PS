#include <iostream>
#include <string>

using namespace std;

const int MAX = 50;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

int counter(char board[MAX][MAX + 1], int s, int e) {
	int sW = 0, sB = 0;

	bool flag = true;

	for (int i = 0; i < 8; i++) {
		char start = flag ? 'W' : 'B';
		for (int j = 0; j < 8; j++) {
			char cur = board[s + i][e + j];
			sW += j % 2 ? start == cur : start != cur;
		}
		flag = !flag;
	}

	flag = false;

	for (int i = 0; i < 8; i++) {
		char start = flag ? 'W' : 'B';
		for (int j = 0; j < 8; j++) {
			char cur = board[s + i][e + j];
			sB += j % 2 ? start == cur : start != cur;
		}
		flag = !flag;
	}

	return _min(sW, sB);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int r, c; cin >> r >> c;
	char board[MAX][MAX + 1] = {};

	for (int i = 0; i < r; i++)
		cin >> board[i];

	int res = 64;

	for (int i = 0; i <= r - 8; i++)
		for (int j = 0; j <= c - 8; j++)
			res = _min(res, counter(board, i, j));

	cout << res;

	return 0;
}