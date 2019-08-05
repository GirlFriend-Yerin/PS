#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		long long res = 0;

		int p; cin >> p;

		vector<int> input(p);

		for (int i = 0; i < p; i++)
			cin >> input[i];

		sort(input.begin(), input.end());

		res = input[0] * input[p - 1];

		cout << '#' << tc << ' ' << res << '\n';
	}
	return 0;
}