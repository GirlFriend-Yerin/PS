#include <iostream>

using namespace std;

const int MAX = 1'000'000;
const int MOD = 1'000'000'000;

int memo[MAX + 1] = {0, 1};

int main()
{
	int n; cin >> n;

	for (int i = 2; i <= MAX; i++)
		memo[i] = (memo[i - 1] + memo[i - 2]) % MOD;

	cout << (n >= 0 ? (n ? 1 : 0 ) : (n == -1 ? 1 : (-n % 2? 1 : -1))) << '\n' << memo[n < 0 ? -n : n];

	return 0;
}