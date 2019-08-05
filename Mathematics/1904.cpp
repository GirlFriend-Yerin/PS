#include <iostream>

using namespace std;

const int MAX = 1000000;
const int DIV = 15746;

int dp[MAX] = { 1, 2, };

int main()
{
	for (int i = 2; i < MAX; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % DIV;

	int n;

	cin >> n;

	cout << dp[n-1];

	return 0;
}