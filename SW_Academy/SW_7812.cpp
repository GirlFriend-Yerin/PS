#include <iostream>

using namespace std;

const int MAX = 10000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		int res = 0;
		int n, m; cin >> n >> m;

		int values[MAX] = {};

		for (int i = 0; i < n; i++)
			cin >> values[i];

		int left = 0, right = 0, sum = 0;

		while (true) {
			if (sum < m) sum += values[right++];
			else sum -= values[left++];
			if (right > n) break;
			if (sum == m)
				res++;
		}

		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}