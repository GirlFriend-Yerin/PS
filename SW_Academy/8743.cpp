#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		ll r, b; cin >> r >> b;

		cout << '#' << tc << ' ' << (abs(r - b) <= 1 ? "DH" : "KJ") << '\n';
	}

	return 0;
}