#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	ll a, b; cin >> a >> b;

	ll res = 0;
	if (a > 0 && b > 0) {
		if (a > b)
			swap(a, b);

		ll sigb = b * (b + 1) / 2;
		ll siga = a * (a - 1) / 2;

		res = sigb - siga;
	}
	else if (a < 0 && b < 0) {
		a *= -1; b *= -1;
		if (a > b)
			swap(a, b);

		ll sigb = b * (b + 1) / 2;
		ll siga = a * (a - 1) / 2;

		res = -(sigb - siga);
	}
	else {
		if (a > b)
			swap(a, b);

		ll siga = -((-a) * ((-a) + 1) / 2);
		ll sigb = b * (b + 1) / 2;

		res = sigb + siga;
	}

	cout << res;

	return 0;
}