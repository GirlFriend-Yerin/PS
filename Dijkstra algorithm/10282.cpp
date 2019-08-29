#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000 * 10000 + 7;

int _max(const int a, const int b) { return a ^ ((a^b) & -(a < b)); }

struct Node {
	int vertex;
	int weight;

	Node(int vertex, int weight) : vertex(vertex), weight(weight) {};

	bool operator<(const Node& node) const {
		return weight > node.weight;
	}
};

pair<int, int> djikstra(vector<vector<Node>>& adj, int n, int start) {

	priority_queue<Node> pq;
	vector<int> dist(n, INF);
	vector<bool> visited(n, false);

	dist[start] = 0;
	int reachedCount = 0;
	int maxTime = 0;

	pq.push(Node(start, dist[start]));

	while (!pq.empty()) {
		Node cur = pq.top(); pq.pop();

		if (visited[cur.vertex]) continue;

		visited[cur.vertex] = true;
		reachedCount++;
			
		maxTime = _max(maxTime, cur.weight >= INF ? 0 : cur.weight);

		for (unsigned int i = 0; i < adj[cur.vertex].size(); i++) {
			int next = adj[cur.vertex][i].vertex;
			int cost = adj[cur.vertex][i].weight;

			if (!visited[next])
				if (cur.weight + cost < dist[next]) {
					dist[next] = cur.weight + cost;
					pq.push(Node(next, cur.weight + cost));
				}
		}
	}

	return { reachedCount, maxTime };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	while (tcc--) {
		int n, q, s; cin >> n  >> q >> s;
		vector<vector<Node>> adj(n);

		for (int i = 0; i < q; i++) {
			int to, des, time; cin >> to >> des >> time;

			adj[des - 1].push_back(Node(to - 1, time));
		}

		pair<int, int> res = djikstra(adj, n, s - 1);

		cout << res.first << ' '  << res.second << '\n';
	}

	return 0;
}