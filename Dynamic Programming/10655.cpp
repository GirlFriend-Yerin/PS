#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;

typedef long long ll;

struct Point {
	short x, y;

	Point() {};
};

int dist(const Point& a, const Point& b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

ll dp[MAX + 1][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<Point> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i].x >> vec[i].y;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 
	}

	return 0;
}