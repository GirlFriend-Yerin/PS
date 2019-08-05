#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;

const short MAX = 1120;
const short PRIME_MAX = 187;
const short SELECT_MAX = 14;

int prime_dp[SELECT_MAX + 1][MAX + 1];

void find_prime() {

	bool prime[MAX + 1] = { true, true };

	for (int i = 2; i < MAX; i++) {
		if (!prime[i]) {
			primes.push_back(i);
			for (int j = 2; i * j <= MAX; j++)
				prime[j*i] = true;
		}
	}

}

void init_dp() {

	prime_dp[0][0] = 1;

	for (int i = 0; i < PRIME_MAX; i++) {
		for (int j = MAX; j >= primes[i]; j--)
			for (int k = 1; k <= SELECT_MAX; k++)
				prime_dp[k][j] += prime_dp[k - 1][j - primes[i]];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Init
	find_prime();
	init_dp();

	int n; cin >> n;

	while (n--)
	{
		int tar, cnt; cin >> tar >> cnt;

		cout << prime_dp[cnt][tar] << '\n';
	}
	return 0;
}