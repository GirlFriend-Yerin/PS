/*
	2019 07 24
	3049 - �ٰ����� �밢��

	Pass
*/
#include <iostream>

using namespace std;

int main()
{
	int n; cin >> n;

	cout << n * (n - 1) * (n - 2) * (n - 3) * 1 / 24;

	return 0;
}