#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int tcc;

	cin >> tcc;

	for (int tcn = 1; tcn <= tcc; tcn++)
	{
		int left, right;
		int res = 1;
		cin >> left >> right;

		int root = sqrt(right);

		cout << left << " : ";
		for (int i = 2; i <= root && i <= left; i++) {
			if (right % i == 0)
			{
				cout << i << ' ';
				res *= i;
			}
		}

		cout << '#' << tcn << ' ' << res << '\n';
	}

	return 0;
}