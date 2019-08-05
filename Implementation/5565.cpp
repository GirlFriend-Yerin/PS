#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int sum; cin >> sum;
	for (int i = 0; i < 9; i++)
	{
		int val; cin >> val;
		sum -= val;
	}

	cout << sum;

	return 0;
}