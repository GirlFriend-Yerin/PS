#include <iostream>

using namespace std;

int main()
{
	long long n; cin >> n;
	cout << (n != 1 ? (n * n * (n - 1) / 2) + (n * (n - 1) / 2) : 1) ;

	return 0;
}

