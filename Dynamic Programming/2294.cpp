#include <iostream>

using namespace std;

const int NMAX = 100;
const int KMAX = 10000;
const int INF = 10001;

const int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;

	int dp[KMAX + 1] = {};

	for (int i = 1; i < KMAX + 1; i++)
		dp[i] = INF;

	for (int i = 0; i < n; i++) {
		int val; cin >> val;

		for (int j = val; j <= k; j++) {
			dp[j] = _min(dp[j], dp[j - val] + 1);
		}
	}
	
	cout << (dp[k] == INF ? -1 : dp[k]);

	return 0;
}