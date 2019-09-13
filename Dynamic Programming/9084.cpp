#include <iostream>

using namespace std;

const int MAX = 100000;
const int NMAX = 100;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n, m; cin >> n >> m;
	int input[NMAX + 1] = {};  for (int i = 1; i <= n; i++) cin >> input[i];

	int dp[MAX + 1] = { 1 };

	for (int i = 1; i <= n; i++)
		for (int j = input[i]; j <= m; j++)
			dp[j] += dp[j - input[i]];

	cout << dp[m] << '\n';


	return 0;
}