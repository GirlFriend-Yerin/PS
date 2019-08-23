#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int ax, ay, bx, by, cx, cy; cin >> ax >> ay >> bx >> by >> cx >> cy;
	int cal = ((ax*by + bx * cy + cx * ay) - (bx*ay + cx * by + ax * cy));

	cout << (cal > 0 ? 1 : (cal < 0 ? -1 : 0));

	return 0;
}