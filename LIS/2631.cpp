#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<int> vec(n); for (int i = 0; i < n; i++) cin >> vec[i];
	deque<int> lis; 

	lis.push_back(vec[0]);

	for (int i = 1; i < n; i++) {
		if (lis.back() < vec[i])
			lis.push_back(vec[i]);
		else {
			int idx = lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin();
			lis[idx] = vec[i];
		}
	}

	cout << n - lis.size();

	return 0;
}

//const int MAX = 200;
//
//int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n; cin >> n;
//
//	vector<int> vec(n); for (int i = 0; i < n; i++) cin >> vec[i];
//	vector<int> sorted(vec);
//
//	int dp[MAX + 1][MAX + 1] = {};
//
//	sort(sorted.begin(), sorted.end());
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++) {
//			if (vec[i - 1] == sorted[j - 1])
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			else
//				dp[i][j] = _max(dp[i - 1][j], dp[i][j - 1]);
//		}
//
//	cout << n - dp[n][n];
//
//	return 0;
//}