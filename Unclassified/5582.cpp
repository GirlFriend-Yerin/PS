#include <iostream>
#include <string>

using namespace std;

int _max(const int a, const int b) { return a ^ ((a^b) & -(a < b)); }

const int MAX = 4000;

int dp[MAX + 1][MAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2;

	cin >> s1 >> s2;

	int s1Len = s1.length(), s2Len = s2.length();
	int res = 0;

	for (int i = 0; i < s1Len; i++) {
		for (int j = 0; j < s2Len; j++) {
			if (s1[i] == s2[j]) {
				if (!i || !j)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;

				res = _max(res, dp[i][j]);
			}
		}
	}

	cout << res;

	return 0;
}