//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//const int INF = 1e9 + 7;
//
//int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }
//int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }
//
//struct Node {
//	int v, w;
//
//	Node() {}
//	Node(int v, int w) : v(v), w(w) { };
//};
//
//bool bfs(vector<vector<Node>>& adj, const int n, const int to, const int des, const int limits) {
//
//	vector<bool> checker(n);
//	queue<int> q;
//
//	q.push(to);
//	checker[to] = true;
//
//	while (!q.empty()) {
//		int cur = q.front(); q.pop();
//
//		if (cur == des) return true;
//
//		for (int i = 0; i < adj[cur].size(); i++) {
//			int next = adj[cur][i].v;
//			int cost = adj[cur][i].w;
//;			if (!checker[next] && limits <= cost) {
//				checker[next] = true;
//				q.push(adj[cur][i].v);
//			}
//		}
//	}
//
//	return false;
//}
//
//int binary(vector<vector<Node>>& adj, int n, int start, int end, int left, int right) {
//
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (bfs(adj, n, start, end, mid)) left = mid + 1;
//		else right = mid - 1;
//	}
//
//	return right;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n, m; cin >> n >> m;
//	int max = 0;
//	vector<vector<Node>> adj(n);
//
//	for (int i = 0; i < m; i++) {
//		int to, des, weight; cin >> to >> des >> weight;
//		max = _max(max, weight);
//
//		adj[to - 1].push_back(Node(des - 1, weight));
//		adj[des - 1].push_back(Node(to - 1, weight));
//	}
//
//	int to, des; cin >> to >> des;
//
//	cout << binary(adj, n, to - 1, des - 1, 1, max);
//
//	return 0;
//}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int to, des, weight;

	Node() {}
	Node(int to, int des, int weight) : to(to), des(des), weight(weight) {}

	bool operator<(const Node& n) const {
		return weight < n.weight;
	}
};

int _find(vector<int>& parent, int pos) {
	return parent[pos] = parent[pos] == pos ? pos : _find(parent, parent[pos]);
}

void _union(vector<int>& parent, int p1, int p2) {
	p1 = _find(parent, p1);
	p2 = _find(parent, p2);

	parent[p2] = p1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	int res = -1;

	priority_queue<Node> pq;
	vector<int> parent(n + 1); for (int i = 0; i < n + 1; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int to, des, weight; cin >> to >> des >> weight;

		pq.push(Node(to, des, weight));
	}

	int to, des; cin >> to >> des;

	while (!pq.empty())
	{
		Node cur = pq.top(); pq.pop();
		
		_union(parent, cur.to, cur.des);

		if (_find(parent, to) == _find(parent, des)) {
			res = cur.weight;
			break;
		}
	}

	cout << res;

	return 0;
}