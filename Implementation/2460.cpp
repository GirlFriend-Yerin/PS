#include <iostream>

using namespace std;

int _max(const int& a, const int& b) { return a ^ ((a ^ b) & -(a < b)); }

int main()
{
	int sum = 0;
	bool flag = true;

	int res = 0;

	for (int i = 0; i < 20; i++) {
		int val; cin >> val;
		sum += (flag ? -1 : 1) * val;
		flag = !flag;

		res = _max(res, sum);
	}

	cout << res;

	return 0;
}