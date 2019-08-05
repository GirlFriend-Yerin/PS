#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, p; cin >> a >> b >> c >> d >> p;

	int calX = a * p;
	int calY = c > p ? b : (b + ((p - c) * d));

	cout << (calX < calY ? calX : calY);

	return 0;
}