#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 100;

ll memo[MAX + 1];

ll _max(const ll a, const ll b) { return a ^ ((a ^ b) & -(a < b)); }

ll func(int n) {
	
	ll& ref = memo[n];
	if (ref != -1)
		return ref;

	ref = 1 + func(n - 1);
	
	if (n >= 3)
		for (int i = 1; i <= n - 2; i++)
			ref = _max(ref, func((n - 2) - i) * (i + 1));

	return ref;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int dp[MAX + 1] = { 0, 1, 2, 3, 4, 5, 6};
	for (int i = 0; i <= MAX + 1; i++)
		memo[i] = -1;

	int n; cin >> n;
	memo[0] = 0;	
	cout << func(n);

	return 0;
}