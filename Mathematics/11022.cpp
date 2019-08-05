#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;

	cin >> tcc;

	for (int i = 0; i < tcc; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << "Case #" << i + 1 << ": " << a + b << '\n';
	}

	return 0;
}