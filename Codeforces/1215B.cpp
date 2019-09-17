#include <iostream>
#include <vector>

using namespace std;

const int MAX = 200000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<bool> items(n, false);
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		items[i] = val < 0;
	}
	
	bool dp[2][MAX];
	for (int i = 0; i < n; i++)
		dp[0][i] = items[i];
	
	int neg = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++)
			dp[1][j] = dp[0][i - 1] ^ items[j];
		
		for (int j = i; j < n; j++)
			neg += dp[1][j];

		swap(dp[0], dp[1]);
	}

	cout << neg << ' ' << (n * (n + 1)) / 2 - neg;

	return 0;
}