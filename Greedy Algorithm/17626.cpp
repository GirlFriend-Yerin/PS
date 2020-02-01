#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<int> table(223);
	for (int i = 0; i < 223; i++)
		table[i] = (i + 1) * (i + 1);

	int n; cin >> n;
	int cnt = 0;

	while (n) {
		int idx = lower_bound(table.begin(), table.end(), n) - table.begin();
		idx -= n < table[idx];
		n -= table[idx];
		cnt++;
	}

	cout << cnt;

	return 0;
}