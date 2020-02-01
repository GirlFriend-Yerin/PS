#include <iostream>
#include <vector>
#include <deque>

using namespace std;

bool isExist(const vector<int>& vec, int size, int val) {
	for (int i = 0; i < size; i++)
		if (vec[i] == val) return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;

	vector<deque<int>> save(k);
	vector<int> items(k);
	vector<int> cache;
	int res = 0;

	for (int i = 0; i < k; i++) {
		cin >> items[i];
		--items[i];
		save[items[i]].push_back(i);
	}

	for (int i = 0; i < k; i++) {
		save[items[i]].pop_front();

		int cSize = cache.size();
		if (isExist(cache, cSize, items[i])) continue;

		if (cSize < n) cache.push_back(items[i]);
		else {
			int outIdx = 0;
			for (int j = 1; j < n; j++) {
				if (!save[cache[j]].size()) {
					outIdx = j;
					break;
				}
				else if (!save[cache[outIdx]].size()) break;
				else if (save[cache[j]].front() > save[cache[outIdx]].front()) outIdx = j;
			}
			
			cache[outIdx] = items[i];

			++res;
		}
	}

	cout << res;

	return 0;
}