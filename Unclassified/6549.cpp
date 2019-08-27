#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

const int INF = 1e9 + 7;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }
ll _max(const ll a, const ll b) { return a ^ ((a ^ b) & -(a < b)); }

struct Node {
	int to, des;
	int val;

	Node() : val(INF) {};
};

void _init(vector<Node>& tree, int node, int start, int end) {

	tree[node].to = start;
	tree[node].des = end;

	if (start != end) {
		_init(tree, node * 2, start, (start + end) / 2);
		_init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

void _update(vector<Node>& tree, int node, int idx, int val) {
	if (!(tree[node].to <= idx && idx <= tree[node].des)) return;

	tree[node].val = _min(tree[node].val, val);

	if (tree[node].to != tree[node].des) {
		_update(tree, node * 2, idx, val);
		_update(tree, node * 2 + 1, idx, val);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	while (n) {
		int height = ceil(log2(n));
		int treeSize = (1 << (1 + height)) + 1;
		vector<Node> tree(treeSize);

		_init(tree, 1, 1, n);

		for (int i = 0; i < n; i++) {
			int val; cin >> val;
			_update(tree, 1, i + 1, val);
		}

		ll res = 0;

		for (int i = 1; i < treeSize; i++) {
			res = tree[i].val != INF ? _max(1LL * tree[i].val * (tree[i].des - tree[i].to + 1), res) : res;
		}

		cout << res << '\n';

		cin >> n;
	}


	return 0;
}