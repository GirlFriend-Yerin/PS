#include <iostream>

using namespace std;

int main()
{
	int a, b, c; cin >> a >> b >> c;

	cout << (b >= c ? -1 : (-a / (b - c)) + 1);

	return 0;
}