#include <iostream>

using namespace std;

int main()
{
	long long n;

	cin >> n;

	long long res = 1;

	for (; (res + 1) * (res + 2) / 2 <= n; res++);

	cout << res;

	return 0;
}