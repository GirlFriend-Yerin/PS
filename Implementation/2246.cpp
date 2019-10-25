#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int res = 0;
	vector<pii> vec(n);

	for (int i = 0; i < n; i++) cin >> vec[i].first >> vec[i].second;

	for (int i = 0; i < n; i++) {
		bool able = true;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			if (vec[i].first > vec[j].first && vec[i].second >= vec[j].second) {
				able = false;
				break;
			}
			else if (vec[i].second > vec[j].second && vec[i].first >= vec[j].first) {
				able = false;
				break;
			}
		}

		res += able;
	}

	cout << res;

	return 0;
}