#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
	short x;
	short y;

	Point() : x(0), y(0) {};
	Point(short x, short y) : x(x), y(y) {};
};

vector<Point> points;
Point yumi;

int main()
{
	cin >> yumi.x >> yumi.y;

	int x, y;

	while (cin >> x >> y) {
		points.push_back(Point(x, y));
	}

	vector<bool> visited(points.size());

	int dist = 0;

	for (int i = 0; i < points.size(); i++)
	{
		int selected = -1;
		int md = 50;
		for (int j = 0; j < points.size(); j++)
		{
			if (visited[j])
				continue;
			int curDist = abs(yumi.x - points[j].x) + abs(yumi.y - points[j].y);

			if (md > curDist) {
				md = curDist;
				selected = j;
			}
		}

		visited[selected] = true;
		dist += sqrt(pow(yumi.x - points[selected].x, 2) + pow(yumi.y - points[selected].y, 2));
		yumi.x = points[selected].x; yumi.y = points[selected].y;
	}

	cout << (int)dist;

	return 0;
}