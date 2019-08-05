#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;

	cin >> tcc;

	while (tcc--)
	{
		short a, b;

		cin >> a >> b;

		cout << a + b << '\n';
	}

	return 0;
}