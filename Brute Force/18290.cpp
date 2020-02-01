#include <iostream>

using namespace std;

const int MAX = 10;

const int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }
int n, m, k;

int bruteForce(int table[MAX][MAX], bool checker[MAX][MAX], const int nextCounter, const int cnt, const int sum, int ret) {
	if (k == cnt) return sum;

	for (int counter = nextCounter; counter < n * m; counter++) {
		int nextY = counter % m;
		int nextX = counter / m;

		if (nextX && checker[nextX - 1][nextY]) continue;
		if (nextY && checker[nextX][nextY - 1]) continue;

		checker[nextX][nextY] = true;
		ret = _max(ret, bruteForce(table, checker, counter + 1, cnt + 1, sum + table[nextX][nextY], ret));
		checker[nextX][nextY] = false;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	int table[MAX][MAX] = {};
	bool checker[MAX][MAX] = {};

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> table[i][j];

	cout << bruteForce(table, checker, 0, 0, 0, -1e9 + 7);

	return 0;
}