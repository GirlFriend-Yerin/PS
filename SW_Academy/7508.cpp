#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;
	cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {

		int res = -1;
		int n; cin >> n;
		vector<int> worker(n); for (int i = 0; i < n; i++) cin >> worker[i];
		vector<int> count(n, 0);
		int m; cin >> m;
		vector<int> item(m); for (int i = 0; i < m; i++) cin >> item[i];

		sort(worker.begin(), worker.end());
		sort(item.begin(), item.end());

		if (worker[n - 1] >= item[m - 1]) {
			int pos = 0;
			double turnMax = double(m) / n;

			for (int i = 0; i < n; i++) {
				for (int j = pos; j < m && j < (turnMax * (i + 1)) ; j++) {
					if (worker[i] >= item[j])
						count[i]++;
					else
						break;
				}
				pos += count[i];
			}

			int greedyTurnMax = (int)turnMax + (m % n != 0);

			for (int i = 1; i < n; i++) {
				if (count[i - 1] > greedyTurnMax) {
					int diff = count[i - 1] - greedyTurnMax;
					count[i] += diff;
					count[i - 1] -= diff;
				}
			}

			/*for (int i = 0; i < n; i++)
				cout << worker[i] << " - " << count[i] << ' ';*/

			for (int i = 0; i < n; i++)
				if (res < count[i])
					res = count[i];
		}

		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}