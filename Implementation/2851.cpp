#include <iostream>

using namespace std;

int main()
{
	int dp[10];
	
	for (int i = 0; i < 10; i++)
		cin >> dp[i];

	int sum = 0;

	for (int i = 0; i < 10; i++) {
		if (sum + dp[i] <= 100)
			sum += dp[i];
		else {
			if (100 - sum >= (sum + dp[i] - 100))
				sum += dp[i];
			else
				break;
		}

		if (sum >= 100)
			break;
	}

	cout << sum;

	return 0;
}