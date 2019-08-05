/*
	2019 07 24
	2774 - 아름다운 수

	Pass
*/
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	while (tcc--) {
		int counter[10] = {};

		int val; cin >> val;

		do {
			counter[val % 10]++;
			val /= 10;
		} while (val);

		int res = 0;
		for (int i = 0; i < 10; i++)
			res += !!counter[i];

		cout << res << '\n';
	}

	return 0;
}