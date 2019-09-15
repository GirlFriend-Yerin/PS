#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& adj, vector<int>& visited, int cur, int pos, int pre) {

	if (visited[cur] != -1) {
		return pos - visited[cur];
	}
	
	visited[cur] = pos;

	for (int i = 0; i < adj[cur].size(); i++) {
		if (visited[adj[cur][i]] != -1 && adj[cur][i] == pre) continue;

		int dis = dfs(adj, visited, adj[cur][i], pos + 1, cur);
		if (dis) return dis;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		int n; cin >> n;

		vector<vector<int>> adj(n);
		vector<int> visited(n, -1);

		for (int i = 0; i < n; i++) {
			int to, des; cin >> to >> des;

			adj[to - 1].push_back(des - 1);
			adj[des - 1].push_back(to - 1);
		}

		int res = dfs(adj, visited, 0, 1, -1);

		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}