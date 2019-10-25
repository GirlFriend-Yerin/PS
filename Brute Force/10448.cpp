#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k; cin >> k;

	int val[5] = { 4, 6, 11, 20, 29 };
	while (k--) {
		int n; cin >> n;

		bool exist = false;
		for (int i = 0; i < 5; i++)
			if (n == val[i]) {
				exist = true;
				break;
			}

		cout << (exist ? 0 : 1) << '\n';
	}

	return 0;
}