#include <iostream>

using namespace std;

const int MAX = 100;

int main()
{
	long long dp[MAX] = { 1,1,1 };
	int tcc; cin >> tcc;

	for (int i = 3; i < MAX; i++)
		dp[i] = dp[i - 2] + dp[i - 3];

	while (tcc--) {
		int n; cin >> n;
		cout << dp[n - 1] << '\n';
	}

	return 0;
}