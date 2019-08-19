#include <iostream>
#include <vector>

using namespace std;

const short MAX = 500;
const int INF = 1e9 + 5;

typedef pair<int, int> pii;

vector<vector<pii>> adj;

void bellman_ford(vector<int>& dist, const int n) {

	bool check = false;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < adj[j].size(); k++) {

				int next = adj[j][k].first;
				int wei = adj[j][k].second;

				if (dist[j] != INF && dist[next] > dist[j] + wei) {
					dist[next] = dist[j] + wei;
					if (i == n) check = true;
				}
			}
		}
	}

	if (check) cout << "-1\n";
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] != INF)
				cout << dist[i] << '\n';
			else
				cout << "-1\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> dist(n + 1, INF);
	dist[1] = 0;

	adj.resize(n + 1);
	
	for (int i = 0; i < m; i++)
	{
		int t, d, w; cin >> t >> d >> w;

		adj[t].push_back({ d, w });
	}

	bellman_ford(dist, n);

	return 0;
}