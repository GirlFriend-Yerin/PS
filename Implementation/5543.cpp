#include <iostream>

using namespace std;

int main()
{
	int burger = 2500;
	for (int i = 0; i < 3; i++)
	{
		int val; cin >> val;
		burger = burger < val ? burger : val;
	}

	int bever = 2500;
	for (int i = 0; i < 2; i++) {
		int val; cin >> val;
		bever = bever < val ? bever : val;
	}

	cout << burger + bever - 50;
	return 0;
}