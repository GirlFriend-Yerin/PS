#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll _max(const ll a, const ll b) { return a ^ ((a^b) & -(a < b)); }
ll _min(const ll a, const ll b) { return b ^ ((a^b) & -(a < b)); }

struct Point {
	ll x, y;

	Point() : x(0), y(0) {}
	Point(ll x, ll y) : x(x), y(y) {};
};

int ccw(const Point& p1, const Point& p2, const Point& p3) {
	ll cal = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);

	return cal ? (cal < 0 ? -1 : 1) : 0;
}

bool isCross(const Point& a, const Point& b, const Point& c, const Point& d) {

	int abCCW = ccw(a, b, c) * ccw(a, b, d);
	int cdCCW = ccw(c, d, a) * ccw(c, d, b);

	if (abCCW <= 0 && cdCCW <= 0) {
		if ((a.x > c.x && a.x > d.x && b.x > c.x && b.x > d.x) ||
			(a.x < c.x && a.x < d.x && b.x < c.x && b.x < d.x)) return false;
		if ((a.y > c.y && a.y > d.y && b.y > c.y && b.y > d.y) ||
			(a.y < c.y && a.y < d.y && b.y < c.y && b.y < d.y)) return false;
		return true;
	}
	return false;
}

bool isContain(const Point& recStart, const Point& recEnd, const Point& p1, const Point& p2) {

	int xMin = _min(p1.x, p2.x), yMin = _min(p1.y, p2.y);
	int xMax = _max(p1.x, p2.x), yMax = _max(p1.y, p2.y);

	return (recStart.x < xMin && xMax < recEnd.x) && (recStart.y < yMin && yMax < recEnd.y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	while (n--) {

		Point p1, p2; cin >> p1.x >> p1.y >> p2.x >> p2.y;
		Point rec1, rec2; cin >> rec1.x >> rec1.y >> rec2.x >> rec2.y;

		if (p1.x < p2.x) {
			swap(p1.x, p2.x);
			swap(p1.y, p2.y);
		}

		ll r1x = _min(rec1.x, rec2.x), r2x = _max(rec1.x, rec2.x);
		ll r1y = _min(rec1.y, rec2.y), r2y = _max(rec1.y, rec2.y);

		rec1.x = r1x; rec2.x = r2x;
		rec1.y = r1y; rec2.y = r2y;

		bool res = false;

		if (isContain(rec1, rec2, p1, p2)) res = true;
		else if (isCross(p1, p2, rec1, Point(rec1.x, rec2.y))) res = true;
		else if (isCross(p1, p2, rec1, Point(rec2.x, rec1.y))) res = true;
		else if (isCross(p1, p2, rec2, Point(rec1.x, rec2.y))) res = true;
		else if (isCross(p1, p2, rec2, Point(rec2.x, rec1.y))) res = true;

		cout << (res ? 'T' : 'F') << '\n';
	}

	return 0;
}