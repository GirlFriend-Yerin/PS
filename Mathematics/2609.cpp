#include <iostream>

using namespace std;

int gcd(const int a, const int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int main()
{
	int a, b; cin >> a >> b;
	int GCD = gcd(a, b);
	int MCD = (a / GCD) * (b / GCD) * GCD;

	cout << GCD << ' ' << MCD;

	return 0;
}