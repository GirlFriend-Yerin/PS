#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main()
{
	int n, m; cin >> n >> m;
	cout << m - gcd(n, m);

	return 0;
}