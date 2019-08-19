#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> save;
int n, k;

void permutation(const vector<int>& cards, vector<bool>& checker, int pos, int cnt, long long sum) {

	if (pos < n && cnt < k) {
		for (int i = 0; i < n; i++) {
			if (checker[i]) continue;
			int _log = log10(cards[i]) + 1;
			int digit = pow(10, _log);
			checker[i] = true;
			permutation(cards, checker, pos + 1, cnt + 1, sum * digit + cards[i]);
			checker[i] = false;
		}
	}
	else
	{
		if (cnt == k) {
			//cout << sum << '\n';
			int lower = lower_bound(save.begin(), save.end(), sum) - save.begin();
			int upper = upper_bound(save.begin(), save.end(), sum) - save.begin();

			if (upper - lower < 1) {
				save.push_back(sum);
				sort(save.begin(), save.end());
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	vector<int> cards(n);
	vector<bool> checker(n, false);

	for (int i = 0; i < n; i++)
		cin >> cards[i];

	permutation(cards, checker, 0, 0, 0);

	cout << save.size();

	return 0;
}