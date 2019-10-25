#include <iostream>

using namespace std;

typedef long long ll;

ll lca(ll a, ll b, int k)
{
	if (k == 1) 
		return a < b ? (b - a) : (a - b);

	ll res = 0;

	for (;a != b; res++)
	{
		if (a < b) b = (b - 2) / k + 1;
		else a = (a - 2) / k + 1;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, k, q; cin >> n >> k >> q;

	for (int i = 0; i < q; i++) {
		ll a, b; cin >> a >> b;
		cout << lca(a, b, k) << '\n';
	}

	return 0;
}