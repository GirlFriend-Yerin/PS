#include <iostream>

using namespace std;

const int MAX = 32768;

bool numbers[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int val; cin >> val;
		numbers[val] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!numbers[i])
		{
			cout << i;
			break;
		}
	}

	return 0;
}