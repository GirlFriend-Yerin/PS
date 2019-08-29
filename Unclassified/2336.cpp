#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9 + 7;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

struct Grade {
	int grade[3];
};

bool cmpFirst(const Grade& n1, const Grade& n2) {
	return n1.grade[0] < n2.grade[0];
}

int _update(vector<int>& tree, int node, int start, int end, int idx, int value) {
	if (!(start <= idx && idx <= end)) return tree[node];

	if (start == end) return tree[node] = value;

	int mid = (start + end) >> 1;

	return tree[node] = _min(_update(tree, node * 2, start, mid, idx, value), _update(tree, node * 2 + 1, mid + 1, end, idx, value));
}

int _find(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (end < left || right < start) return INF;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) >> 1;
	return _min(_find(tree, node * 2, start, mid, left, right), _find(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<Grade> grades(n);

	int h = (int)ceil(log2(n)) + 1;
	vector<int> segTree(1 << h);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++) {
			int num; cin >> num;
			grades[num - 1].grade[i] = j + 1;
		}

	sort(grades.begin(), grades.end(), cmpFirst);

	for (int i = 0; i < n; i++) _update(segTree, 1, 1, n, i + 1, INF);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (_find(segTree, 1, 1, n, 1, grades[i].grade[1]) > grades[i].grade[2]) ans++;
		_update(segTree, 1, 1, n, grades[i].grade[1], grades[i].grade[2]);
	}

	cout << ans;

	return 0;
}