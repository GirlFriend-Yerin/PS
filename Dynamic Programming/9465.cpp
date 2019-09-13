#include <iostream>

using namespace std;

const int MAX = 100000;

int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	while (tcc--) {
		int n; cin >> n;
		int input[MAX][2] = {};

		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> input[j][i];

		int dp[MAX+1][2] = {};

		dp[0][0] = dp[1][0] = 0;
		dp[1][0] = input[1][0]; dp[1][1] = input[1][1];

		for (int i = 2; i <= n; i++) {
			dp[i][0] = _max(dp[i - 1][1], dp[i - 2][1]) + input[i][0];
			dp[i][1] = _max(dp[i - 1][0], dp[i - 2][0]) + input[i][1];
		}

		cout << _max(dp[n][0], dp[n][1]) << '\n';
	}

	return 0;
}