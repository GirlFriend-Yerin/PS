#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;
	cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		double res = 0;

		int n, k;
		vector<int> values;

		cin >> n >> k;
		values.resize(n);

		for (int i = 0; i < n; i++)
			cin >> values[i];

		sort(values.begin(), values.end());

		for (int i = n - k; i < n; i++)
			res = (res + values[i]) / 2;

		cout << fixed; 
		cout.precision(6);
		cout <<'#' << tc << ' ' << res << '\n';
	}

}