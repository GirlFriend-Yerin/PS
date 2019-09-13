#include <iostream>

using namespace std;

const int MAX = 1000;
const int MOD = 10007;

int dp[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;

	cout << dp[n];

	return 0;
}