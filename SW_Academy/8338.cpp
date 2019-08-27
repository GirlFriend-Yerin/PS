#include <iostream>

using namespace std;

const int _max(const int a, const int b) { return a ^ ((a^b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tcc; cin >> tcc;
	for (int tc = 1; tc <= tcc; tc++) {
		int n; cin >> n;
		int res; cin >> res;

		for (int i = 1; i < n; i++)
		{
			int val; cin >> val;
			res = _max(res + val, res * val);
		}

		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}