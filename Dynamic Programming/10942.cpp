#include <iostream>

using namespace std;

const int MAX = 2000;

int value[MAX + 1];
int dp[MAX + 1][MAX + 1];

void init(int n) {

	for (int i = 1; i <= n; i++)
		dp[i][i] = true;

	for (int i = 1; i < n; i++)
		dp[i][i + 1] = value[i] == value[i + 1];

	for (int i = 2; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (value[j] == value[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> value[i];

	init(n);

	int m; cin >> m;
	while (m--) {
		int to, des; cin >> to >> des;

		cout << dp[to][des] << '\n';
	}


	return 0;
}