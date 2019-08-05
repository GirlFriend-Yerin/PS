#include <iostream>

using namespace std;

int solve(int k)
{
	int res = k;
	for (; k; k /= 10)
		res += k % 10;
	return res;
}

int main()
{
	int n; cin >> n;

	int res = 0;

	for (int i = 1; i <= n; i++) {
		int divSum = solve(i);
		if (divSum == n) {
			res = i;
			break;
		}
	}

	cout << res;

	return 0;
}