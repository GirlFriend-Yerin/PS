#include <iostream>

using namespace std;

int _min(int& x, int& y) { return y ^ ((x ^ y) & -(x < y)); }
bool _max(int& x, int& y) { return x != (x ^ ((x ^ y) & -(x < y))); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		int val[2]; cin >> val[0] >> val[1];

		bool win = true; // true - B, false - A
		while (val[0] && val[1]) {
			int min = _min(val[0], val[1]);
			bool max = _max(val[0], val[1]);
			if ((val[max] / 2) % 2)
				win = !win;
			val[max] %= min;
		}

		cout << '#' << tc << ' ' << (win ? 'A' : 'B') << '\n';
	}

	return 0;
}