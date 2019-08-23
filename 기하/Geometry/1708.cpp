#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Point {
	ll x, y;
	ll rx, ry;

	Point() : rx(1), ry(0) {};
	Point(ll x, ll y) : x(x), y(y), rx(1), ry(0) {};

	bool operator< (const Point& p) const {
		if (ry * p.rx != rx * p.ry) return ry * p.rx < rx * p.ry;
		return y == p.y ? (x < p.x) : y < p.y;
	}
};

int ccw(const Point& a, const Point& b, const Point& c) {
	ll cal = (a.x * b.y + b.x*c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);

	return cal ? (cal < 0 ? -1 : 1) : 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<Point> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i].x >> vec[i].y;

	sort(vec.begin(), vec.end());

	for (int i = 1; i < n; i++) {
		vec[i].rx = vec[i].x - vec[0].x;
		vec[i].ry = vec[i].y - vec[0].y;
	}

	sort(vec.begin(), vec.end());

	stack<Point> stack;
	stack.push(vec[0]); stack.push(vec[1]);
	for (int next = 2; next < n; next++) {

		while (stack.size() > 1) {
			Point first = stack.top(); stack.pop();
			Point second = stack.top();

			if (ccw(second, first, vec[next]) > 0) {
				stack.push(first);
				break;
			}
		}

		stack.push(vec[next]);
	}

	cout << stack.size();

	return 0;
}