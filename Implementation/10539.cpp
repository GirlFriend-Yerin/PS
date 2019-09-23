#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int prefix = 0;

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int val; cin >> val;

		cout << (val * i) - prefix << ' ';
		prefix = (val * i);
	}

	return 0;
}