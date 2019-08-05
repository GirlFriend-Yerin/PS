/*
	2019 01 11
	1010 다리놓기
	Dynamic Programming

	- 성공 -
*/
#include <iostream>

using namespace std;

const int MAX = 30;

int dp[MAX][MAX + 1];

int main()
{
	int n;

	cin >> n;

	//dp init
	for (int i = 0; i < MAX; i++)
	{
		for (int j = i; j < MAX; j++)
		{
			if (i == 0) // 첫번째 다리의 경우
				dp[i][j] = j + 1;
			else if (i == j) // 같은 번호의 다리의 경우
				dp[i][j] = 1;
			else // 그 외의 경우
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
		}
	}

	for (int i = 0; i < n; i++)
	{
		int left, right;
		cin >> left >> right;

		cout << dp[left-1][right-1] << '\n';
	}

	return 0;
}