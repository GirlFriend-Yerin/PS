#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int SMAX = 2000000;

typedef long long ll;

ll _max(const ll a, const ll b) { return a ^ ((a ^ b) & -(a < b)); }

int bound;
ll counter[SMAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val; cin >> val;
		bound = _max(bound, val);
		
		for (int j = 1; j * j <= val; j++)
		{
			if (val % j) continue;
			counter[j]++;
			counter[val / j] += j != val / j;
		}
	}

	ll res = 0;
	for (int i = 1; i <= bound; i++)
		res = _max(res, i * counter[i] * (counter[i] > 1));
	
	cout << res;

	return 0;
}