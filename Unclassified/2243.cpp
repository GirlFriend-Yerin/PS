#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;

typedef long long ll;

ll result;

void add(vector<ll>& tree, int node, int start, int end, int index, int val) {

	if (!(start <= index && index <= end)) return;

	tree[node] += val;

	if (start != end) {
		add(tree, node * 2, start, (start + end) / 2, index, val);
		add(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);

	}
}

ll _find(vector<ll>& tree, int node, int start, int end, int rank) {

	if ((start == end) && !result) {
		cout << start << '\n';
		return start;
	}

	if (!result && tree[node * 2] >= rank)
		return result = _find(tree, node * 2, start, (start + end) / 2, rank);

	rank -= tree[node * 2];

	if (!result && tree[node * 2 + 1] >= rank)
		return result = _find(tree, node * 2 + 1, (start + end) / 2 + 1, end, rank);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h = (int)ceil(log2(MAX));

	vector<ll> segTree(1 << (1 + h));

	int tc; cin >> tc;

	for (int i = 0; i < tc; i++) {
		int a, b; cin >> a >> b;

		if (a == 1) {
			int idx = _find(segTree, 1, 0, MAX - 1, b);
			result = 0;
			add(segTree, 1, 0, MAX - 1, idx, -1);
		}
		else {
			int c; cin >> c;

			add(segTree, 1, 0, MAX - 1, b, c);
		}

	}

	return 0;
}