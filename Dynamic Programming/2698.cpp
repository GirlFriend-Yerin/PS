#include <iostream>

using namespace std;

const int MAX = 100;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int dp[MAX + 1][MAX + 1][2] = {};
	dp[1][0][0] = dp[1][0][1] = 1;

	for (int i = 0; i < MAX; i++)
		for (int j = 2; j <= MAX; j++) {
			dp[j][i][0] += dp[j - 1][i][0] + dp[j - 1][i][1];
			dp[j][i][1] += i ? dp[j - 1][i - 1][1] + dp[j - 1][i][0] : dp[j - 1][i][0];
		}

	int tcc; cin >> tcc;

	while (tcc--) {
		int n, k; cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << '\n';
	}

	return 0;
}