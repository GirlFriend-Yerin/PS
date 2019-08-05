#include <iostream>

using namespace std;

int main()
{
	int tcc;

	cin >> tcc;

	while (tcc--)
	{
		int cnt;
		char out;

		cin >> cnt >> out;

		for (int i = 0; i < cnt; i++)
			cout << out;
		cout << '\n';
	}

	return 0;
}