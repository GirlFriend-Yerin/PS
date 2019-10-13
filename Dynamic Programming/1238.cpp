#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;

int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

vector<int> dajikstra(vector<vector<pii>>& adj, int n, int start) {

	vector<int> table(n, INF);
	table[start] = 0;
	priority_queue<pii> pq;

	pq.push({ 0, start });

	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();

		for (register unsigned int i = 0; i < adj[cur.second].size(); i++) {
			int next = adj[cur.second][i].first;
			int cost = adj[cur.second][i].second;

			if (table[next] > cost - cur.first) {
				table[next] = cost - cur.first;

				pq.push({ -table[next], next });
			}
		}
	}

	return table;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x; cin >> n >> m >> x;
	vector<vector<pii>> adj(n);

	for (int i = 0; i < m; i++) {
		int to, des, weight; cin >> to >> des >> weight;

		adj[to - 1].push_back({ des - 1, weight });
	}

	vector<int> toX(n);
	for (int i = 0; i < n; i++)
		toX[i] = dajikstra(adj, n, i)[x-1];
	vector<int> forX = dajikstra(adj, n, x - 1);

	int res = 0;
	for (int i = 0; i < n; i++)
		res = _max(res, toX[i] + forX[i]);

	cout << res;

	return 0;
}