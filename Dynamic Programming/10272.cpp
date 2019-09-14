#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const short POINT_MAX = 512;

struct Point {
	short x, y;

	Point() {};
};

double dist(const Point& p1, const Point& p2) { return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); }
double _min(const double a, const double b) { return a > b ? b : a; }
int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }
int n;

double bitonic(int x, int y,const vector<Point>& vec, double dp[POINT_MAX][POINT_MAX]) {

	if (x == n - 1 || y == n - 1) {
		if (y != n - 1) return dist(vec[y], vec[n - 1]);
		if (x != n - 1) return dist(vec[x], vec[n - 1]);
		return 0.0;
	}

	double& ref = dp[x][y];
	if (ref != -1.0) return ref;

	int next = _max(x, y) + 1;
	ref = 1e11;
	ref = _min(ref, bitonic(next, y, vec, dp) + dist(vec[x], vec[next]));
	ref = _min(ref, bitonic(x, next, vec, dp) + dist(vec[y], vec[next]));

	return ref;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	while (tcc--) {
		cin >> n;
		vector<Point> vec(n);

		for (int i = 0; i < n; i++) cin >> vec[i].x >> vec[i].y;
		double dp[POINT_MAX][POINT_MAX] = {};

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dp[i][j] = -1.0;

		printf("%.12lf\n", bitonic(0, 0, vec, dp));
	}

	return 0;
}