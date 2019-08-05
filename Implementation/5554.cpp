#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int val; cin >> val;
		sum += val;
	}

	cout << sum / 60 << '\n' << sum % 60;

	return 0;
}