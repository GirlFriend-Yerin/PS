#include <iostream>

using namespace std;

bool inCircle(double x, double y, double r, int pX, int pY) {
	double pD = ((pX - x) * (pX - x)) + ((pY - y) * (pY - y));
	double r2 = r * r;

	return pD <= r2;
}

bool inRect(int x1, int y1, int x2, int y2, int pX, int pY) {
	return (x1 <= pX && pX <= x2) && (y1 <= pY && pY <= y2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int w, h, x, y, p; cin >> w >> h >> x >> y >> p;
	int res = 0;

	for (int i = 0; i < p; i++) {
		int pX, pY; cin >> pX >> pY;
		res += inRect(x, y, x + w, y + h, pX, pY) || inCircle(x, y + h/2.f, h/2.f, pX, pY) || inCircle(x + w, y + h/2.f, h/2.f, pX, pY);
	}

	cout << res;

	return 0;
}