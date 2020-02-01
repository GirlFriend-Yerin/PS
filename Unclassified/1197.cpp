#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int VMAX = 10000;

int par[VMAX];

struct Node {
	int t;
	int d;
	int w;

	Node() {};
	Node(int t, int d, int w) : t(t), d(d), w(w) {};

	bool operator<(const Node& n) const {
		return w > n.w;
	}
};

int _find(int v) {
	return par[v] == v ? v : v = _find(par[v]);
}

bool _union(int t, int d) {
	int parT = _find(t);
	int parD = _find(d);

	if (parT == parD) return false;

	par[parD] = parT;
	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int vCount, eCount; cin >> vCount >> eCount;

	priority_queue<Node> pq;

	for (int i = 0; i < eCount; i++) {
		int t, d, w; cin >> t >> d >> w;
		pq.push(Node(t, d, w));
	}

	for (int i = 0; i < vCount; i++)
		par[i] = i;

	int res = 0;
	
	for (int i = 0; i < vCount - 1;) {
		Node top = pq.top(); pq.pop();

		if (_union(top.t, top.d)){
			res += top.w;
			i++;
		}
	}

	cout << res;

}