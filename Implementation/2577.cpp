#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c; cin >> a >> b >> c;

	int cal = a * b * c;

	short check[10] = {};

	do
	{
		check[cal % 10]++;
		cal /= 10;
	} while (cal);

	for (int i = 0; i < 10; i++) {
		cout << check[i] << '\n';
	}

	return 0;
}