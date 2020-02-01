#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;

struct Node {
	int	des, val;

	Node() {};
	Node(int des, int val) : des(des), val(val) {};

	bool operator<(const Node& n) const {
		return val < n.val;
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> dist(n, INF);
	vector<int> parent(n, -1);
	vector<vector<Node>> adj(n);
	priority_queue<Node> pq;

	for (int i = 0; i < m; i++) {
		int to, des, val; 
		cin >> to >> des >> val;

		adj[to - 1].push_back(Node(des - 1, val));
		adj[des - 1].push_back(Node(to - 1, val));
	}

	dist[0] = 0;
	pq.push(Node(0, 0));

	while (!pq.empty()) {
		Node cur = pq.top(); pq.pop();
		int to = cur.des;
		int cost = cur.val;

		for (Node& node : adj[to]) {
			int next = node.des;
			int nextCost = cost + node.val;

			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				parent[next] = to;

				pq.push(Node(next, nextCost));
			}
		}
	}

	cout << n - 1 << '\n';

	for (int i = 1; i < n; i++)
		cout << parent[i] + 1 << ' ' << i + 1 << '\n';
	return 0;
}