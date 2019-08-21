#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> vec(n);
	deque<int> lds;

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	lds.push_back(-vec[0]);

	for (int i = 1; i < n; i++) {
		int val = -vec[i];

		if (lds.back() < val) {
			lds.push_back(val);
		}
		else {
			int lower = lower_bound(lds.begin(), lds.end(), val) - lds.begin();
			lds[lower] = val;
		}
	}

	cout << lds.size();

	return 0;
}