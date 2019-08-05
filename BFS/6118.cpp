#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 20000;

vector<vector<int>> adj;

int dist[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	queue<int> q;

	cin >> n >> m;

	adj.resize(n);

	for (int i = 0; i < m; i++)
	{
		int to, des;

		cin >> to >> des;

		adj[to-1].push_back(des-1);
		adj[des-1].push_back(to-1);
	}

	q.push(0);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int curNodeCount = adj[cur].size();

		for (int i = 0; i < curNodeCount; i++) {
			int next = adj[cur][i];

			if (dist[next] == 0) {
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}

	int maxDist = 1;
	for (int i = 2; i < n; i++)
		if (dist[maxDist] < dist[i])
			maxDist = i;

	int sameCount = 0;
	for (int i = 1; i < n; i++)
		if (dist[maxDist] == dist[i])
			sameCount++;

	cout << maxDist + 1 << ' ' << dist[maxDist] << ' ' << sameCount;

	return 0;
}