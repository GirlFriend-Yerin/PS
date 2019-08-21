#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

const int INF = -1;

int _max(const int a, const int b) { return a ^ ((a^b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> vec(n);
	vector<int> dp(n);

	int res = 0;

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j <= i; j++) {
			if (vec[i] > vec[j]) {
				max = _max(max, dp[j]);
			}
		}
		dp[i] = max + vec[i];
		res = _max(res, dp[i]);
	}

	cout << res;

	return 0;
}