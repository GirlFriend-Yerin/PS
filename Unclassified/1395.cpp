#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void _update_lazy(vector<int>& vec, vector<int>& lazy,int node, int start, int end) {

	if (lazy[node]) {
		vec[node] = end - start + 1 - vec[node];

		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}

		lazy[node] = 0;
	}
}

int _update(vector<int>& vec, vector<int>& lazy, int node, int start, int end, int left, int right) {
	_update_lazy(vec, lazy, node, start, end);

	if (right < start || end < left ) return vec[node];

	if (left <= start && end <= right) {
		vec[node] = end - start + 1 - vec[node];

		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}

		return vec[node];
	}

	int mid = (start + end) / 2;
	return vec[node] = _update(vec, lazy, node * 2, start, mid, left, right) + _update(vec, lazy, node * 2 + 1, mid + 1, end, left, right);
}

int _find(vector<int>& vec, vector<int>& lazy, int node, int start, int end, int left, int right) {
	_update_lazy(vec, lazy, node, start, end);

	if (right < start || end < left) return 0;

	if (left <= start && end <= right) return vec[node];

	int mid = (start + end) / 2;
	return _find(vec, lazy, node * 2, start, mid, left, right) + _find(vec, lazy, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	int h = ceil(log2(n)) + 1;
	vector<int> segTree(1 << h);
	vector<int> lazyTree(1 << h);

	for (int i = 0; i < m; i++) {
		int order, to, des; cin >> order >> to >> des;

		if (order) {
			cout << _find(segTree, lazyTree, 1, 1, n, to, des) << '\n';
		}
		else {
			_update(segTree, lazyTree, 1, 1, n, to, des);
		}
	}

	return 0;
}