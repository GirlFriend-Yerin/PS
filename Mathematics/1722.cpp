#include <iostream>
#include <vector>

using namespace std;

const short MAX = 20;

typedef long long ll;

ll facto[MAX + 1] = { 1 };

void init() {

	for (int i = 1; i < MAX + 1; i++)
		facto[i] = facto[i - 1] * i;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	int order; cin >> order;
	init();

	vector<bool> checker(n + 1, false);

	if (order == 1) {
		ll k; cin >> k;

		vector<int> res(n);


		for (int i = 0; i < n; i++) {

			for (int j = 1; j < n + 1; j++)
			{
				if (checker[j])
					continue;

				if (facto[n - i - 1] < k) k -= facto[n - i - 1];
				else {
					res[i] = j;
					checker[j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < n; i++)
			cout << res[i] << ' ';

	}
	else {
		ll ans = 0;

		vector<int> permu(n);

		for (int i = 0; i < n; i++)
			cin >> permu[i];

		for (int i = 0; i < n; i++) {

			for (int j = 1; j < permu[i]; j++) {
				if (!checker[j])
					ans += facto[n - i - 1];
			}

			checker[permu[i]] = true;
		}

		cout << ans + 1;
	}

	return 0;
}