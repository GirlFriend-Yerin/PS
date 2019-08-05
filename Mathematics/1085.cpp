#include <iostream>

using namespace std;

int main()
{
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int disBigger = ((w - x) > (h - y) ? h - y : w - x);
	int res = x > y ? y : x;
	res = disBigger > res ? res : disBigger;

	cout << res;

	return 0;
}