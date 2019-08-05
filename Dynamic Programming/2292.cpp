/*
	2019 01 15
	2292 À°°¢Çü
	Dynamic Programming

	- ¼º°ø -
*/

#include <iostream>

using namespace std;

const int MAX = 1000000000;

int dp[100000];

int main()
{
	int n;
	int counter = 0;

	cin >> n;

	// dp init
	dp[0] = 1;
	for (int i = 1; dp[i -1] < MAX; i++)
		dp[i] = dp[i - 1] + (6 * i);

	for (int i = 0; i < 5; i++)
		cout << dp[i] << ' ';
	cout << endl;

	while (n > dp[counter])
		counter++;

	cout << counter + 1;

	return 0;
}