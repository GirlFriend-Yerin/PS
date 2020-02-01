#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	while (tcc--)
	{
		int res = -1;
		int r, c; cin >> r >> c;
		if (r > 11 && c > 3) res = c * 11 + 4;
		
		cout << res << '\n';
	}

	return 0;
}