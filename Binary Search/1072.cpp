/*
	1072 게임
	Binary Search
	2019 02 15

	- 성공 -
*/

#include <iostream>

using namespace std;

const int MAX = 1500000000;

int main()
{
	int res = -1;
	long long x, y;
	int z;

	while (cin >> x >> y)
	{
		long long left = 0, right = MAX;
		z = 100 * y / x;

		if (z >= 99)
			left = -1;
		else
		{
			while (left <= right)
			{
				long long middle = (left + right) / 2;
				long long cal = 100 * (y + middle) / (x + middle);

				if (cal <= z)
					left = middle + 1;
				else
					right = middle - 1;
			}

		}
		cout << left << '\n';
	}

	return 0;
}