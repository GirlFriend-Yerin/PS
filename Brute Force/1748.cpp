/*
	2019 01 05
	1748 �� �̾�� 1
	Brute force

	- ���� -
*/
#include <iostream>

using namespace std;

int main()
{
	int n;
	int res = 0;

	cin >> n;

	for (int i = 1; i <= n; i *= 10)
		res += n - i + 1;

	cout << res;
}