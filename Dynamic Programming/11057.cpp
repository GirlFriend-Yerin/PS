/*
	2019 01 11
	11057 오르막수
	Dynamic Programming

	- 성공 -
*/
#include <iostream>

using namespace std;

const int MAX = 1000;
const int DIGIT_MAX = 10;
int dp[MAX][DIGIT_MAX];

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < DIGIT_MAX; i++)
		dp[0][i] = 1;

	//DP Table Init
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 0; j < DIGIT_MAX; j++)
		{
			if (j)
			{
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
				dp[i][j] %= 10007;
			}
			else
				dp[i][j] = 1;
		}
	}

	int sum = 0;
	for (int i = 0; i < DIGIT_MAX; i++)
		sum += dp[n - 1][i];

	cout << sum % 10007 << endl;

	return 0;
}