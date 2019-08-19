#include <iostream>

using namespace std;

const short RAN_MIN = 0;
const short RAN_MAX = 20;
const int MAX = 100;

typedef long long ll;

int numbers[MAX];
ll dp[MAX + 1][RAN_MAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	dp[0][numbers[0]] = 1;

	for (int i = 1; i < n; i++)
		for (int j = 0; j < RAN_MAX + 1; j++) {
			if (dp[i - 1][j]) {
				if (j + numbers[i] <= RAN_MAX) dp[i][j + numbers[i]] += dp[i - 1][j];
				if (j - numbers[i] >= RAN_MIN) dp[i][j - numbers[i]] += dp[i - 1][j];
			}
		}

	cout << dp[n - 2][numbers[n - 1]];

	return 0;
}