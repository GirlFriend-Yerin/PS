#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;

struct Node {
	int des;
	int value;

	bool operator<(const Node& n) const {
		return value > n.value;
	}

	Node() {}
	Node(int des, int value) : des(des), value(value) {}
};

int djiksta(const vector<vector<Node>>& adj, int to, int des)
{
	vector<int> distance(adj.size(), INF);
	priority_queue<Node> pq;

	distance[to] = 0;

	pq.push(Node(to, 0));

	while (!pq.empty()) {
		Node cur = pq.top(); pq.pop();

		for (int i = 0; i < adj[cur.des].size(); i++) {
			int next = adj[cur.des][i].des;
			int cost = cur.value + adj[cur.des][i].value;

			if (cost < distance[next]) {
				distance[next] = cost;
				pq.push(Node(next, cost));
			}
		}
	}

	return distance[des];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<Node>> adj(n);

	for (int i = 0; i < m; i++) {
		int to, des, value; cin >> to >> des >> value;

		adj[to - 1].push_back(Node(des - 1, value));
	}

	int start, end; cin >> start >> end;

	cout << djiksta(adj, start - 1, end - 1);

	return 0;
}