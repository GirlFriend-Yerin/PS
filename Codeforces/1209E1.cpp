#include <iostream>

using namespace std;

const int MAX = 100;

const int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int board[MAX + 1][MAX + 1] = {};

	int tcc; cin >> tcc;

	while (tcc--) {
		int n, m; cin >> n >> m;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> board[i][j];

		int res = 0;
		for (int i = 0; i < m; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {

			}
		}
	}


	return 0;
}