#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
	int stuIdx;
	int thumb;
	int when;

	Node() : stuIdx(1005) {};

	bool operator<(const Node& n) {
		return stuIdx < n.stuIdx;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<Node> lfu(n);

	int curCount = 0;
	for (int i = 0; i < m; i++) {

		int stu; cin >> stu;
		int minIdx = 0;
		bool isExist = false;
		for (int j = 0; j < curCount; j++) {
			if (lfu[j].stuIdx == stu) {
				lfu[j].thumb++;
				isExist = true;
				break;
			}
			else {
				if (lfu[j].thumb < lfu[minIdx].thumb)
					minIdx = j;
				else if (lfu[j].thumb == lfu[minIdx].thumb && lfu[j].when < lfu[minIdx].when)
					minIdx = j;
			}
		}
		if (isExist) continue;

		if (curCount < n) {
			lfu[curCount].stuIdx = stu;
			lfu[curCount].thumb = 0;
			lfu[curCount].when = i;
			curCount++;
		}
		else {
			lfu[minIdx].stuIdx = stu;
			lfu[minIdx].thumb = 0;
			lfu[minIdx].when = i;
		}
	}

	sort(lfu.begin(), lfu.end());
	for (int i = 0; i < curCount; i++)
		cout << lfu[i].stuIdx << ' ';

	return 0;
}