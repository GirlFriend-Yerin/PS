/*
	2019 01 21
	1057 토너먼트
	MatheMatics

	- 성공 -
*/
#include <iostream>

using namespace std;

int main()
{
	int n, kim, im;
	int res = -1;

	cin >> n >> kim >> im;

	for (int rnd = 1; n > 0; rnd++)
	{
		// cout << rnd << ' ' << kim << ' ' << im << ' ' << n << endl; // For Debug

		kim = (kim / 2) + (kim % 2);
		im = (im / 2) + (im % 2);

		if (kim == im)
		{
			res = rnd;
			break;
		}

		n /= 2;
	}

	cout << res;

	return 0;
}