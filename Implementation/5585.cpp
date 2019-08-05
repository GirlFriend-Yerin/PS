#include <iostream>

using namespace std;

int en[] = { 500, 100, 50, 10, 5, 1 };

int main()
{
	int val; cin >> val;
	val = 1000 - val;
	int cnt = 0;

	for (int i = 0; i < 6; i++)
	{
		cnt += val / en[i];
		val %= en[i];
	}

	cout << cnt;

	return 0;
}