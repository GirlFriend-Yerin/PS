#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> incomeCnt(n + 1);

	for (int i = 0; i < m; i++) {
		int to, des; cin >> to >> des;
		adj[to].push_back(des);
		incomeCnt[des]++;
	}

	priority_queue<int> q;

	for (int i = 1; i < n + 1; i++)
		if (!incomeCnt[i]) q.push(-i);

	while (!q.empty()) {
		int cur = -q.top(); q.pop();

		cout << cur << ' ';

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];

			if (!--incomeCnt[next])
				q.push(-next);
		}
	}

	return 0;
}