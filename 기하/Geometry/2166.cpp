#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long > pll;
typedef pair<int, int> vec;

double calLen(const vec& v1) {
	return sqrt(pow(v1.first, 2) + pow(v1.second, 2));
}

vec toVec(const pii& p1, const pii& p2) {
	return{ p1.first - p2.first, p1.second - p2.second };
}

double inner(const vec& v1, const vec& v2) {
	return v1.first * v2.first + v1.second * v2.second;
}

double getCos(const vec& v1, const vec& v2) {
	return inner(v1, v2) / (calLen(v1) * calLen(v2));
}

double calSize(const pii& p1, const pii& p2, const pii& p3) {

	vec v1 = toVec(p1, p2);
	vec v2 = toVec(p1, p3);

	return 0.5 * sqrt((pow(calLen(v1), 2) * pow(calLen(v2), 2)) - pow(inner(v1, v2), 2));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector<pll> points(n);

	for (int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;

	double res = 0;
	double add = 0;
	double sub = 0;

	for (int i = 0; i < n; i++)
		add += points[i].first * points[(i + 1) % n].second;
	for (int i = 0; i < n; i++)
		sub += points[(i + 1) % n].first * points[i].second;

	/*pii gijun = points[0];
	double res = 0;

	for (int i = 1; i < n - 1; i++)
		res += calSize(gijun, points[i], points[i + 1]);*/

	printf("%.1lf", 0.5 * abs(add - sub));

	return 0;
}
