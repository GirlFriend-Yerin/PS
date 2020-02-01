#include <iostream>

using namespace std;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;

	int left = 1, right = k;
	int res = -1;

	while (left <= right) {
		long long cnt = 0;
		int mid = (left + right) / 2;
		for (int i = 1; i <= n; i++) cnt += _min(mid / i, n);
		if (cnt < k) left = mid + 1;
		else {
			res = mid;
			right = mid - 1;
		}
	}

	cout << res;

	return 0;
}