/*
	2019 07 24
	2783 - »ï°¢±è¹ä

	Pass
*/

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int base, val; cin >> val >> base;

	int n; cin >> n;

	double min = (double)val / base * 1000.f;
	for (int i = 0; i < n; i++) {
		double x, y; cin >> y >> x;

		double pay = y / x * 1000.f;

		min = min < pay ? min : pay;

	}

	printf("%.3f", min);

	return 0;
}