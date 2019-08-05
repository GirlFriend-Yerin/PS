#include <iostream>

using namespace std;

int main()
{
	int m, n;
	int resMax = 0, res = -1;

	cin >> m >> n;

	for (int i = 1; i <= 100; i++)
	{
		int pow = i * i;

		if (pow < m)
			continue;

		if (res == -1)
			res = pow;

		if (pow > n)
			break;

		resMax += pow;
	}

	if (resMax == 0)
		cout << -1;
	else
		cout << resMax << '\n' << res;


	return 0;
}