#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iostream>

using namespace std;

struct Point {
	int x, y;
	int num;

	Point() : x(-1), y(-1), num(0) {}

	bool operator<(Point& p) {
		return y != p.y ? y > p.y : x < p.x;
	}
};

void post(vector<int>& ans, const vector<Point>& tree, int pos) {
	ans.push_back(tree[pos].num);

	if (pos*2 < tree.size() && tree[pos * 2].num)
		post(ans, tree, pos * 2);
	if (pos*2 +1  < tree.size() && tree[pos * 2 + 1].num)
		post(ans, tree, pos * 2 + 1);
}

void pre(vector<int>& ans, const vector<Point>& tree, int pos) {
	if (pos*2 < tree.size() && tree[pos * 2].num)
		pre(ans, tree, pos * 2);
	if (pos*2 + 1 < tree.size() &&  tree[pos * 2 + 1].num)
		pre(ans, tree, pos * 2 + 1);

	ans.push_back(tree[pos].num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer(2);

	int nodeCnt = nodeinfo.size();
	int h = ceil(log2(nodeCnt)) + 1;

	vector<Point> points(nodeCnt);
	vector<Point> tree((1 << h) + 1);

	for (int i = 0; i < nodeCnt; i++) {
		points[i].num = i + 1;
		points[i].x = nodeinfo[i][0];
		points[i].y = nodeinfo[i][1];
	}

	sort(points.begin(), points.end());

	for (auto point : points) {
		int pos = 1;
		while (true) {
			if (tree[pos].num) {
				if (tree[pos].x > point.x)
					pos *= 2;
				else
					pos = pos * 2 + 1;
			}
			else {
				tree[pos].num = point.num;
				tree[pos].x = point.x;
				tree[pos].y = point.y;
				break;
			}
		}
	}

	post(answer[0], tree, 1);
	pre(answer[1], tree, 1);

	return answer;
}

int main() {
	
	int n; cin >> n;
	vector<vector<int>> nodeinfo(n);

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		nodeinfo[i].push_back(x);
		nodeinfo[i].push_back(y);
	}
	
	vector<vector<int>> res = solution(nodeinfo);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}

	return 0;
}