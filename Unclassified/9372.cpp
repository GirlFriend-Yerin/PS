#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int VMAX = 10000;

int par[VMAX];

int _find(int v) {
	return par[v] == v ? v : v = _find(par[v]);
}

bool _union(int t, int d) {
	int parT = _find(t);
	int parD = _find(d);

	if (parT == parD) return false;

	par[parD] = parT;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	while (tcc--) {
		int vCount, eCount; cin >> vCount >> eCount;

		for (int i = 0; i < vCount; i++) par[i] = i;

		int res = 0;

		while( eCount-- ) {
			int t, d; cin >> t >> d;
			res += _union(t - 1, d - 1);
		}

		cout << res << '\n';
	}

	return 0;
}