/*
	2019 07 24
	5032 - Åº»êÀ½·á

	Pass
*/
#include <iostream>

using namespace std;

int main()
{
	int e, f, c; cin >> e >> f >> c;
	int res = 0;

	e += f;

	while (e >= c) {
		int eat = e / c;
		res += eat;
		e = (e % c) + eat;
	}

	cout << res;

	return 0;
}