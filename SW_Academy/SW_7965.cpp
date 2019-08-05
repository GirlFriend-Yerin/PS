#include <iostream>

using namespace std;

const int MAX = 1000000;
const int DIV = 1000000007;

long long dp[MAX + 1];

long long cal(long long val, int pow) {
	long long res = 1;

	while (pow > 0) {
		if (pow % 2) {
			res = res * val % DIV;
		}
		val = val * val % DIV;
		pow /= 2;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// init
	for (int i = 1; i < MAX + 1; i++)
		dp[i] = (dp[i - 1] + cal(i, i)) % DIV;

	int tcc; cin >> tcc;
	for (int tc = 1; tc <= tcc; tc++) {
		int n; cin >> n;

		cout << '#' << tc << ' ' << dp[n] << '\n';
	}

	return 0;
}