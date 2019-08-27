#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 1e9 + 7;

int _min(const int a, const int b) { return b ^ ((a^b) & -(a < b)); }

void _insert(vector<int>& tree, int node, int start, int end, int idx, int val) {
	if (!(start <= idx && idx <= end)) return;

	tree[node] = _min(tree[node], val);

	if (start != end) {
		_insert(tree, node * 2, start, (start + end) / 2, idx, val);
		_insert(tree, node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
	}
}

int _find(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return INF;

	if (left <= start && end <= right) return tree[node];

	return _min(_find(tree, node * 2, start, (start + end) / 2, left, right), _find(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	int h = ceil(log2(n));
	vector<int> segTree(1 << (1 + h), INF);
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		_insert(segTree, 1, 1, n, i + 1, val);
	}

	for (int i = 0; i < m; i++) {
		int to, des; cin >> to >> des;
		cout << _find(segTree, 1, 1, n, to, des) << '\n';
	}

	return 0;
}