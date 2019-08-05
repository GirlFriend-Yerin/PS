#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
	long long n; cin >> n;
	long long res = 1;

	while (n) {
		res *= n - 1;
		res %= MOD;
		
		n -= 2;
	}

	cout << res;

	return 0;
}