#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

typedef pair<int, int> pii;

int getWeight(const vector<vector<pii>>& adj, int start, int des) {

	vector<bool> visited(adj.size());
	queue<pii> q;
	visited[start] = true;
	q.push({ start, 0 });

	while (!q.empty()) {
		pii cur = q.front(); q.pop();

		if (cur.first == des)
			return cur.second;

		int childrenCount = adj[cur.first].size();
		for (int i = 0; i < childrenCount; i++) {
			int next = adj[cur.first][i].first;
			int diff = adj[cur.first][i].second;

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, cur.second + diff });
			}
		}
	}

	return INF;
}

int find(vector<int>& par, int v) {
	return v == par[v] ? v : par[v] = find(par, par[v]);
}

void _union(vector<int>& par, int left, int right) {
	int leftPar = find(par, left);
	int rightPar = find(par, right);

	if (leftPar != rightPar)
		par[left] = right;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	while (n && m) {
		vector<vector<pii>> adj(n);
		vector<int> parent(n);
		for (int i = 0; i < n; i++) parent[i] = i;

		for (int i = 0; i < m; i++) {
			char order; cin >> order;

			if (order == '!')
			{
				int to, des, weight; cin >> to >> des >> weight;
				_union(parent, to - 1, des - 1);
				adj[to - 1].push_back({ des - 1, weight });
				adj[des - 1].push_back({ to - 1 , -weight });
			}
			else {
				int to, des; cin >> to >> des;

				if (find(parent, to - 1) != find(parent, des - 1))
					cout << "UNKNOWN\n";
				else
					cout << getWeight(adj, to - 1, des - 1) << '\n';
			}

		}

		cin >> n >> m;
	}

	return 0;
}