#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll _max(const ll a, const ll b) { return a ^ ((a ^ b) ^ -(a < b)); }

struct Point {
	ll x, y;
	ll rx, ry;

	Point() : x(), y(), rx(1), ry(0) {};
	Point(ll x, ll y, ll rx, ll ry) : x(x), y(y), rx(rx), ry(ry) {};
	Point(ll x, ll y) : x(x), y(y), rx(0), ry(0) {}

	bool operator< (const Point& p) const {
		if (ry * p.rx != rx * p.ry) return ry * p.rx < rx * p.ry;
		return y == p.y ? (x < p.x) : y < p.y;
	}
};

ll distance(const Point& a, const Point& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void preProcessing(vector<Point>& vec, int n) {

	sort(vec.begin(), vec.end());

	for (int i = 1; i < n; i++) {
		vec[i].rx = vec[i].x - vec[0].x;
		vec[i].ry = vec[i].y - vec[0].y;
	}

	sort(vec.begin() + 1, vec.end());
}

int ccw(const Point& a, const Point& b, const Point& c) {
	ll cal = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);

	return cal ? (cal < 0 ? -1 : 1) : 0;
}

void convex(deque<Point>& res, const vector<Point> vec, int n) {

	res.push_back(vec[0]);
	if (n > 1)
		res.push_back(vec[1]);

	for (int next = 2; next < n; next++) {

		while (res.size() > 1) {
			Point first = res.back(); res.pop_back();
			Point second = res.back();

			if (ccw(second, first, vec[next]) > 0) {
				res.push_back(first);
				break;
			}
		}

		res.push_back(vec[next]);
	}
}

vector<Point> getMaxDis(const deque<Point> convexHull) {
	vector<Point> res;

	int n = convexHull.size();

	ll maxDist = 0;

	Point left, right;
	int j = 1;
	for (int i = 0; i < n; i++) {
		Point next_I = convexHull[(i + 1) % n];

		while (true) {
			Point next_J = convexHull[(j + 1) % n];
			Point b(next_I.x - convexHull[i].x, next_I.y - convexHull[i].y);
			Point c(next_J.x - convexHull[j].x, next_J.y - convexHull[j].y);

			int zbcCCW = ccw(Point(0, 0), b, c);
			if (zbcCCW > 0) j = (j + 1) % n;
			else break;
		}

		ll dist = distance(convexHull[i], convexHull[j]);
		if (maxDist < dist) {
			maxDist = dist;
			res.clear();
			res.push_back(convexHull[i]);
			res.push_back(convexHull[j]);
		}
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;
	while (tcc--) {
		int n; cin >> n;
		vector<Point> vec(n);

		for (int i = 0; i < n; i++)
			cin >> vec[i].x >> vec[i].y;

		preProcessing(vec, n);

		deque<Point> hull;

		convex(hull, vec, n);

		vector<Point> max = getMaxDis(hull);

		printf("%lld %lld %lld %lld\n", max[0].x, max[0].y, max[1].x, max[1].y);
	}

	return 0;
}