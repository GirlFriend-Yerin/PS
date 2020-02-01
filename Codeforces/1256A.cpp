#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc; cin >> tc;

	while (tc--) {
		int a, b, n, s; cin >> a >> b >> n >> s;
		bool check = false;

		for (int i = 1; i < n; i++) {
			if (a * i + b * (n - i) == s) {
				check = true;
				break;
			}
		}

		cout << (check ? "YES" : "NO") << '\n';
	}

	return 0;
}