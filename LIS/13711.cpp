#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> pos(n + 1);
	vector<int> second(n);

	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		pos[val] = i;
	}

	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		second[i] = pos[val];
	}

	deque<int> lis;
	lis.push_back(second[0]);

	for (int i = 1; i < n; i++) {
		if (second[i] < lis.front())
			lis[0] = second[i];
		else if (lis.back() < second[i])
			lis.push_back(second[i]);
		else {
			int bound = lower_bound(lis.begin(), lis.end(), second[i]) - lis.begin();
			lis[bound] = second[i];
		}
	}

	cout << lis.size();

	return 0;
}