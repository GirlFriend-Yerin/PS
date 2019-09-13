#include <iostream>

using namespace std;

const int MAX = 100;
const int DIGIT = 10;
const int MOD = 1'000'000'000;

long long dp[MAX + 1][DIGIT + 1];

int pos[] = { -1 , 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= DIGIT; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= DIGIT; j++) {
			int sum = 0;
			for (int k = 0; k < 2; k++) {
				int next = j + pos[k];
				if (0 <= next && next < DIGIT)
					sum = (sum + dp[i - 1][next]) % MOD;
			}
			dp[i][j] = sum;
		}
	}

	int res = 0;
	for (int i = 0; i < DIGIT; i++)
		res = (res + dp[n][i]) % MOD;
	cout << res;


	return 0;
}