#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;
const int TIME_MAX = 130;

typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	char init[MAX + 1] = {}; cin >> init;
	bool status[MAX + 1]; for (int i = 0; i < n; i++) status[i] = init[i] == '1';

	vector<pii> stat(n);
	for (int i = 0; i < n; i++)
		cin >> stat[i].first >> stat[i].second;

	int res = 0;

	for (int i = 0; i < TIME_MAX; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			bool onoff = status[j];
			if (i >= stat[j].second) {
				int mok = (i - stat[j].second) / stat[j].first;
				if (!(mok % 2))
					onoff = !onoff;
			}
			sum += onoff;
		}

		res = res < sum ? sum : res;
	}

	cout << res;
	
	return 0;
}