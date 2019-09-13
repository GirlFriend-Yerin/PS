#include <iostream>

using namespace std;

const int MAX = 1000;

int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int values[MAX + 1] = {}; for (int i = 1; i <= n; i++) cin >> values[i];

	int dp[MAX + 1] = {};

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = _max(dp[i], dp[i - j] + values[j]);

	cout << dp[n];

	return 0;
}