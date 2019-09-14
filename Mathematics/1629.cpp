#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ll a, b, c; cin >> a >> b >> c;

	ll res = 1;

	while (b) {
		if (b & 1) res = (res * a) % c;
		b >>= 1;
		a = (a * a) % c;
	}

	cout << res;

	return 0;
}