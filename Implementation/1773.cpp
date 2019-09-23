#include <iostream>

using namespace std;

const int MAX = 2000000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool check[MAX + 1] = {};

	int n, c; cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		for (int j = 1; val * j <= c; j++)
			check[val*j] = true;
	}

	int res = 0;
	for (int i = 0; i <= c; i++)
		res += check[i];

	cout << res;

	return 0;
}