#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;

const int INF = 10007;

ll _min(const ll a, const ll b) { return b ^ ((a ^ b) & -(a < b)); }

struct Point {
	int x, y;

	Point() {};
	Point(int x, int y) : x(x), y(y) {};

	bool operator<(const Point& p) const {
		return x != p.x ? x < p.x : y < p.y;
	}
};

struct Point2 {
	int x, y;

	Point2(int x, int y) : x(x), y(y) {};
	Point2(Point& p) : x(p.x), y(p.y) {};

	bool operator<(const Point2& p) const {
		return y != p.y ? y < p.y : x < p.x;
	}
};

ll dist(const Point& a, const Point& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll dist(const Point2& a, const Point2& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<Point> vec(n);
	set<Point2> set;

	for (int i = 0; i < n; i++)
		cin >> vec[i].x >> vec[i].y;

	sort(vec.begin(), vec.end());

	ll min = dist(vec[0], vec[1]);
	set.insert(vec[0]);
	set.insert(vec[1]);

	int start = 0;
	for (int i = 2; i < n; i++) {
		Point cur = vec[i];

		while (start < i) {
			Point pivot = vec[start];
			int x = pivot.x - cur.x;

			if (1LL * x * x > min) {
				set.erase(pivot);
				start++;
			}
			else break;
		}

		ll sqrtD = min;
		Point2 lowerPoint(-INF, vec[i].y - sqrtD);
		Point2 highPoint(INF, vec[i].y + sqrtD);

		auto left = set.lower_bound(lowerPoint);
		auto right = set.upper_bound(highPoint);

		for (auto it = left; it != right; it++) {
			sqrtD = _min(1LL * sqrtD, dist(*it, Point2(vec[i])));
		}
		set.insert(vec[i]);
	}

	cout << min;

	return 0;
}