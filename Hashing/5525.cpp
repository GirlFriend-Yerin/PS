#include <iostream>

using namespace std;

const int MAX = 1000000;
const int MOD = 100000007;

int targetHash = 1;
int topHash = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, s; cin >> n >> s;
	int res = 0;

	char input[MAX + 1] = {};
	cin >> input;

	bool trigger = true;
	for (int i = 0; i < n; i++)
		targetHash = ((targetHash * 4) + 1) % MOD;

	int hash = 0;
	for (int i = 0; i < 2 * n + 1; i++) {
		hash = (hash * 2 + (input[i] == 'I')) % MOD;
	}

	for (int i = 0; i < 2 * n; i++)
		topHash = (topHash * 2) % MOD;

	for (int i = 0; i < s - (2 * n); i++)
	{
		res += targetHash == hash;
		if (input[i] == 'I')
			hash = (hash - topHash) % MOD;
		if (hash < 0)
			hash += MOD;
		hash = ((hash * 2) + (input[i + (2 * n + 1)] == 'I')) % MOD;
	}

	cout << res;

	return 0;
}