#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll _max(const ll a, const ll b) { return a ^ ((a^b) & -(a < b)); }
ll _min(const ll a, const ll b) { return b ^ ((a^b) & -(a < b)); }

struct Point {
	ll x, y;

	Point() : x(0), y(0) {}
	Point(ll x, ll y) : x(x), y(y) {};

	bool operator<(const Point& p) const {
		return x == p.x ? (y < p.y) : x < p.x;
	}
	bool operator==(const Point& p) const {
		return x == p.x && y == p.y;
	}
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

bool isCrossLine(const Point& a, const Point& b, const Point& c, const Point& d) {
	int abCCW = ccw(a, b, c) * ccw(a, b, d);
	int cdCCW = ccw(c, d, a) * ccw(c, d, b);

	return abCCW < 0 && cdCCW <= 0;
}

bool isOver(const Point& a, const Point& b, const Point& c, const Point& d) {

	int abCCW = ccw(a, b, c) * ccw(a, b, d);
	int cdCCW = ccw(c, d, a) * ccw(c, d, b);

	return !abCCW && cdCCW <= 0;
}

bool isIncParell(Point a, Point b, Point c, Point d) {
	if (!isCross(a, b, c, d))return false;
	if (ccw(a, b, c) || ccw(a, b, d)) return false;

	if (b < a) swap(b, a);
	if (d < c) swap(d, c);

	return a < c && c < b || c < a && a < d || a < d && d < b || c < b && b < d || a == c && b == d;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	while (n--) {

		Point rec1, rec2; cin >> rec1.x >> rec1.y >> rec2.x >> rec2.y;
		Point p1, p2; cin >> p1.x >> p1.y >> p2.x >> p2.y;

		int res = 0;

		bool cross = false;

		if (isCross(p1, p2, rec1, Point(rec1.x, rec2.y))) cross = true;
		else if (isCross(p1, p2, rec1, Point(rec2.x, rec1.y))) cross = true;
		else if (isCross(p1, p2, rec2, Point(rec1.x, rec2.y))) cross = true;
		else if (isCross(p1, p2, rec2, Point(rec2.x, rec1.y))) cross = true;

		if (cross) {
			bool inf = false;

			if (isIncParell(p1, p2, rec1, Point(rec1.x, rec2.y))) inf = true;
			else if (isIncParell(p1, p2, rec1, Point(rec2.x, rec1.y))) inf = true;
			else if (isIncParell(p1, p2, rec2, Point(rec1.x, rec2.y))) inf = true;
			else if (isIncParell(p1, p2, rec2, Point(rec2.x, rec1.y))) inf = true;

			if (inf)
				res = 4;
			else
			{
				int line = 0, dot = 0;

				line += isCrossLine(p1, p2, rec1, Point(rec1.x, rec2.y));
				line += isCrossLine(p1, p2, rec1, Point(rec2.x, rec1.y));
				line += isCrossLine(p1, p2, rec2, Point(rec1.x, rec2.y));
				line += isCrossLine(p1, p2, rec2, Point(rec2.x, rec1.y));
				dot += isOver(p1, p2, rec1, Point(rec1.x, rec2.y));
				dot += isOver(p1, p2, rec1, Point(rec2.x, rec1.y));
				dot += isOver(p1, p2, rec2, Point(rec1.x, rec2.y));
				dot += isOver(p1, p2, rec2, Point(rec2.x, rec1.y));

				res = line + dot / 2;
			}
		}

		cout << res << '\n';
	}

	return 0;
}