#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	while (tcc--) {
		int val; cin >> val;
		int op; cin >> op;
		while (op--) {
			int cnt, pay; cin >> cnt >> pay;
			val += cnt * pay;
		}

		cout << val << '\n';
	}

	return 0;
}