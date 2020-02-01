#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> source(n); for (int i = 0; i < n; i++) cin >> source[i];
	int m; cin >> m;

	sort(source.begin(), source.end());

	for (int i = 0; i < m; i++) {
		int val; cin >> val;
		int low = lower_bound(source.begin(), source.end(), val) - source.begin();
		int up = upper_bound(source.begin(), source.end(), val) - source.begin();

		cout << up - low << ' ';
	}

	return 0;
}