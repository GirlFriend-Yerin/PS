/*
	2019-08-07
	10868 최솟값
	세그먼트 트리

*/
#include <iostream>

using namespace std;

const int LENGTH_MAX = 100000;
const int VALUE_MAX = 1e9 + 5;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

struct Node {
	int start;
	int end;
	int value;

	Node() {}
};

class SegmentTree {

public:
	void init(int cnt) {
		size = cnt;
		_init(1, cnt, 1);
	}
	void _init(int start, int end, int pos) {
		tree[pos].start = start;
		tree[pos].end = end;
		tree[pos].value = VALUE_MAX;

		if (start != end) {
			_init(start, (start + end) / 2, pos * 2);
			_init((start + end) / 2 + 1, end, pos * 2 + 1);
		}
	}

	int find(int start, int end) {
		return _find(start, end, 1);
	}

	int _find(int start, int end, int pos) {
		if (start > tree[pos].end || end < tree[pos].start)
			return VALUE_MAX;

		cout << start << ',' << end << '\n';

		if (start <= tree[pos].start && tree[pos].end <= end)
			return tree[pos].value;


		return _min(_find(start, (start + end) / 2, pos * 2), _find((start + end) / 2 + 1, end, pos * 2 + 1));
	}

	void change(int pos, const int value) {
		_change(pos, 1, value);
	}

	void _change(int idx, int pos, const int value) {
		if (tree[pos].start <= idx && idx <= tree[pos].end) {
			tree[pos].value = _min(tree[pos].value, value);

			if (tree[pos].start != tree[pos].end) {
				_change(idx, pos * 2, value);
				_change(idx, pos * 2 + 1, value);
			}
		}
	}
private:
	int size;
	Node tree[LENGTH_MAX * 2 - 1];
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	SegmentTree segTree;

	int n, m; cin >> n >> m;
	segTree.init(n);

	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		segTree.change(i + 1, val);
	}

	for (int j = 0; j < m; j++) {
		int to, des; cin >> to >> des;

		cout << "To - " << to << " Des - " << des << '\n';
		cout << segTree.find(to, des) << '\n';
	}
	return 0;
}