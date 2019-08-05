#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, b; cin >> a >> b;
	double m = (b - a) / 400.0l;

	cout << 1.0l / (1.0f + pow(10, m));


	return 0;
}