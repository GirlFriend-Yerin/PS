#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		int l; cin >> l;
		long long pow = (l - 1) / 2;
		cout << '#' << tc << ' ' << pow * pow << '\n';
	}

	return 0;
}