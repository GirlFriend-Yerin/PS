#include <iostream>

using namespace std;

const short MAX = 10000;

int step[MAX + 1];

int dp[MAX + 1];

int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> step[i];

	dp[1] = step[1];
	dp[2] = dp[1] + step[2];

	for (int i = 3; i <= n; i++)
		dp[i] = _max(_max(dp[i - 3] + step[i - 1] + step[i], dp[i - 1]), dp[i-2] + step[i]);

	cout << dp[n];

	return 0;
}