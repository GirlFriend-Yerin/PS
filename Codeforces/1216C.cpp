#include <iostream>
#include <algorithm>

using namespace std;

struct Rect {
	int x1, y1;
	int x2, y2;
};

struct Point {
	int x, y;
};

bool checkContatin(const Point& p, const Rect& rec) {
	return rec.x1 <= p.x && p.x <= rec.x2 && rec.y1 <= p.y && p.y <= rec.y2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	Rect rec[3] = {};

	for (int i = 0; i < 3; i++)
		cin >> rec[i].x1 >> rec[i].y1 >> rec[i].x2 >> rec[i].y2;

	if (rec[1].x1 < rec[2].x1)
		swap(rec[1], rec[2]);

	Point p[4] = {};

	p[0].x = rec[0].x1; p[0].y = rec[0].y1;
	p[1].x = rec[0].x1; p[1].y = rec[0].y2;
	p[2].x = rec[0].x2; p[2].y = rec[0].y1;
	p[3].x = rec[0].x2; p[2].y = rec[0].y2;

	bool res = false;

	for (int i = 0; i < 4; i++) {
		if (checkContatin(p[i], rec[1]) || checkContatin(p[i], rec[2])) {
			res = true;
			break;
		}
	}

	cout << res

	return 0;
}