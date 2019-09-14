#include <iostream>

using namespace std;

long long _pow(int n) {
	long long res = 1;
	for (int i = 0; i < n; i++)
		res *= 2;
	return res;
}

int main()
{
	long long n; cin >> n;

	cout << (1ll + _pow(n)) * (1ll + _pow(n));

	return 0;
}