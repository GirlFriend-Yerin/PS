#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;

struct Point {
	int x;
	int y;

	Point() {}
	Point(int x, int y) : x(x), y(y) {};
};

bool cmp(Point& p1, Point& p2) {
	if (p1.x != p2.x)
		return p1.x < p2.x;
	return p1.y < p2.y;
}

char input[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	cin >> input;

	vector<Point> flowers(n);
	Point frog;

	for (int i = 0; i < n; i++)
		cin >> flowers[i].x >> flowers[i].y;

	frog.x = flowers[0].x; frog.y = flowers[0].y;

	sort(flowers.begin(), flowers.end(), cmp);

	return 0;
}