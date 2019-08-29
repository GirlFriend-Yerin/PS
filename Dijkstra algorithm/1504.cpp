#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 160'000'007;
const short MAX = 800;

typedef long long ll;
typedef pair<int, long long> pil;
typedef pair<long long, int> pli;

struct Edge {
	int v;
	ll w;

	Edge() : v(0), w(0) {}
	Edge(int v, ll w) : v(v), w(w) {};

	bool operator<(const Edge& e) const {
		return w < e.w;
	}
};

ll djikstra(const vector<vector<pil>>& adj, int n, int to, int des) {

	priority_queue<Edge> pq;
	vector<ll> dist(n, INF);
	dist[to] = 0;
	
	for (int i = 0; i < n; i++)
		pq.push(Edge(i, dist[i]));

	while (!pq.empty()) {
		Edge cur = pq.top(); pq.pop();

		for (auto& item : adj[cur.v]) {
			int vtx = item.first;
			ll cost = item.second;

			if (cur.w + cost < dist[vtx]) {
				dist[vtx] = cur.w + cost;
				pq.push(Edge(vtx, cur.w + cost));
			}
		}
	}

	return dist[des];
}

void _dist_init(vector<ll>& dist, int n, int start) {

	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[start] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, e; cin >> n >> e;
	vector<vector<pil>> adj(n);

	for (int i = 0; i < e; i++) {
		int vt1, vt2, c; cin >> vt1 >> vt2 >> c;

		adj[vt1 - 1].push_back({ vt2 - 1, c });
		adj[vt2 - 1].push_back({ vt1 - 1, c });
	}

	int point1, point2; cin >> point1 >> point2;

	ll o2P1 = djikstra(adj, n, 0, point1 -1);
	ll o2P2 = djikstra(adj, n, 0, point2 - 1);
	ll p12des = djikstra(adj, n, point1 - 1, n -1);
	ll p22des = djikstra(adj, n, point2 - 1, n -1);
	ll p12p2 = djikstra(adj, n, point1 - 1, point2 - 1);

	ll oP1P2Des= o2P1 + p12p2 + p22des;
	ll oP2P1Des = o2P2 + p12p2 + p12des;

	ll res = oP1P2Des < oP2P1Des ? oP1P2Des : oP2P1Des;

	if (res > INF || res < 0)
		res = -1;

	cout << res;

	return 0;
}