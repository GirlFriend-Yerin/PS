#include <iostream>
#include <vector>

using namespace std;

bool isAble(int val) {
	if (!val) return true;

	int count[10] = {};
	
	while (val) {
		count[val % 10]++;
		val /= 10;
	}

	for (int i = 0; i < 10; i++)
		if (count[i] && count[i] > 1)
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int l, r; cin >> l >> r;
	int res = -1;
	for (int i = l; i <= r; i++) {
		if (isAble(i)) {
			res = i;
			break;
		}
	}

	cout << res;

	return 0;
}