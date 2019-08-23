#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

struct Point {
	ll x, y;
	ll rx, ry;

	Point() : rx(1), ry(0) {};
	Point(ll x, ll y, bool isBlack) : x(x), y(y), rx(1), ry(0) {};

	bool operator< (const Point& p) const {
		if (ry * p.rx != rx * p.ry) return ry * p.rx < rx * p.ry;
		return y == p.y ? (x < p.x) : y < p.y;
	}
};

int ccw(const Point& a, const Point& b, const Point& c) {
	ll cal = (a.x * b.y + b.x*c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);

	return cal ? (cal < 0 ? -1 : 1) : 0;
}

void preProcessing(vector<Point>& vec, int n) {

	sort(vec.begin(), vec.end());

	for (int i = 1; i < n; i++) {
		vec[i].rx = vec[i].x - vec[0].x;
		vec[i].ry = vec[i].y - vec[0].y;
	}

	sort(vec.begin() + 1, vec.end());
}

void convexHull(deque<Point>& stack, const vector<Point>& vec, int n) {

	stack.push_back(vec[0]);
	if (vec.size() > 1)
		stack.push_back(vec[1]);

	for (int next = 2; next < n; next++) {

		while (stack.size() > 1) {
			Point first = stack.back(); stack.pop_back();
			Point second = stack.back();

			if (ccw(second, first, vec[next]) > 0) {
				stack.push_back(first);
				break;
			}
		}

		stack.push_back(vec[next]);
	}
}

bool isInside(Point p, const deque<Point>& vec) {
	int crosses = 0;

	for (int i = 0; i < vec.size(); i++) {
		int j = (i + 1) % vec.size();

		if ((vec[i].y > p.y) != (vec[j].y > p.y)) {
			double atX = (vec[j].x - vec[i].x)*(p.y - vec[i].y) / (vec[j].y - vec[i].y) + vec[i].x;
			crosses += p.x < atX;
		}
	}

	return crosses % 2 > 0;
}

bool disjoint(ll a, ll b, ll c, ll d) {
	if (a > b) swap(a, b); if (c > d) swap(c, d);
	return b < c || d < a;
}

bool isOverlap(const Point& a, const Point& b, const Point& c, const Point & d) {
	int abCCW = ccw(a, b, c) * ccw(a, b, d);
	int cdCCW = ccw(c, d, a) * ccw(c, d, b);

	if (!abCCW && !cdCCW)
		return !disjoint(a.x, b.x, c.x, d.x) || !disjoint(a.y, b.y, c.y, d.y);

	return abCCW <= 0 && cdCCW <= 0;
}

bool isAble(deque<Point>& black, deque<Point>& white) {
	int b = black.size(), w = white.size();

	if (isInside(black[0], white) || isInside(white[0], black)) return false;

	if (b == 1 && b == w) return !(black[0].x == white[0].x && black[0].y == white[0].y);

	for (int i = 0; i < b; i++)
		for (int j = 0; j < w; j++)
			if (isOverlap(black[i], black[(i + 1) % b], white[j], white[(j + 1) % w]))
				return false;

	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;
	while (tcc--) {

		int b, w; cin >> b >> w;
		vector<Point> blackVec(b);
		vector<Point> whiteVec(w);

		for (int i = 0; i < b; i++)
			cin >> blackVec[i].x >> blackVec[i].y;

		for (int i = 0; i < w; i++)
			cin >> whiteVec[i].x >> whiteVec[i].y;

		preProcessing(blackVec, b);
		preProcessing(whiteVec, w);

		deque<Point> blackConvex, whiteConvex;

		convexHull(blackConvex, blackVec, b);
		convexHull(whiteConvex, whiteVec, w);

		cout << (isAble(blackConvex, whiteConvex) ? "YES" : "NO") << '\n';
	}

	return 0;
}