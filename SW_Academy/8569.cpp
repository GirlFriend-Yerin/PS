#include <iostream>

using namespace std;

const int MAX = 90;

pair<long long, long long> dp[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	dp[1] = { 2, 1 };
	for (int i = 2; i < MAX + 1; i++)
		dp[i] = { dp[i - 1].first + dp[i - 1].second , dp[i - 1].first };

	int tcc; cin >> tcc;
	for (int tc = 1; tc <= tcc; tc++) {
		int n; cin >> n;
		cout << '#' << tc << ' ' << dp[n].first << ' ' << dp[n].second << '\n';
	}

	return 0;
}