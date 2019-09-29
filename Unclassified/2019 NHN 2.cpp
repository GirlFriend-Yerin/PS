#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	map<int, int> mmp;
	for (int i = 0; i < n; i++) {
		string order; cin >> order;

		if (order[0] == 'e') {
			int val; cin >> val;
			mmp[val]++;
		}
		else {
			priority_queue<pair<int, int>> pq;

			for (std::map<int, int>::iterator it = mmp.begin(); it != mmp.end(); it++) {
				if (it->second != 0) pq.push({ it->second , it->first });
			}

			cout << pq.top().second << ' ';
			mmp[pq.top().second]--;			
			if (!pq.top().second)
				mmp.erase(pq.top().second);
		}
	}

	return 0;
}