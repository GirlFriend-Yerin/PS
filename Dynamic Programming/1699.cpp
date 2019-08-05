/*
	2019 01 11
	1699 제곱수의 합
	Dynamic Programming

	- 성공 -
*/
#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100000;
int dp[MAX + 1];

int min(int a, int b) { return a < b ? a : b; }

int func(int n)
{
	if (dp[n]) return dp[n];

	if (n == pow(int(sqrt(n)), 2))
		return 1;

	dp[n] = n;
	for (int i = 2; i <= sqrt(n); i++) {
		int res = func(n - (i * i)) + 1;
		if (dp[n] > res)
			dp[n] = res;
	}

	return dp[n];
}

int main()
{
	int n;

	cin >> n;

	for (int i = 1; i < 4; i++)
		dp[i] = i;

	// dp Init
	for (int i = 4; i < MAX + 1; i++)
		dp[i] = func(i);
		
	cout << dp[n];

	return 0;
}