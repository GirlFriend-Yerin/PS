#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long n;

	cin >> n;

	long long square = (long long)sqrt(n);

	if (square * square == n)
		cout << 0;
	else
	{
		long long res = square;

		while (res > 0)
		{
			res--;
			long double cal = n / res;

			if (cal * res != n)
				continue;
			else
			{
				cout << abs(cal - res);
				break;
			}
				
		}
	}

	return 0;
}