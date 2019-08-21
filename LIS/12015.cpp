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
	deque<int> lis;

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	lis.push_back(vec[0]);

	for (int i = 1; i < n; i++) {
		if (lis.back() < vec[i]) {
			lis.push_back(vec[i]);
		}
		else {
			int lower = lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin();
			lis[lower] = vec[i];
		}
	}

	cout << lis.size();

	return 0;
}