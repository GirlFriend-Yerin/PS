#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }
int res = 1e7;

vector<vector<int>> elseGroup(vector<vector<int>>& adj, vector<bool> check) {

	vector<vector<int>> group;

	for (int i = 0; i < adj.size(); i++) {
		if (check[i]) continue;
		
		vector<int> curGroup;
		queue<int> q;

		curGroup.push_back(i);
		q.push(i);
		check[i] = true;

		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int j = 0; j < adj[cur].size(); j++) {
				int next = adj[cur][j];
				if (!check[next]) {
					check[next] = true;
					curGroup.push_back(next);
					q.push(next);
				}
			}
		}

		group.push_back(curGroup);
	}

	return group;
}

void dfs(int v,vector<int>& peo, vector<vector<int>>& adj, vector<bool>& check, int n) {

	int first = 0;
	for (int i = 0; i < n; i++)
		first += check[i] * peo[i];

	vector<vector<int>> eGroup = elseGroup(adj, check);

	if (check[0] & !check[1] & check[2] & check[3] & !check[4] & !check[5])
		cout << eGroup.size() << '\n';

	if (eGroup.size() < 2) {
		int second = 0;
		for (int i = 0; i < eGroup[0].size(); i++)
			second += peo[eGroup[0][i]];
		res = _min(res, abs(first - second));
	}

	for (int i = 0; i < adj[v].size(); i++) {
		int next = adj[v][i];
		if (check[next]) continue;

		check[next] = true;
		dfs(next, peo, adj, check, n);
		check[next] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> people(n); for (int i = 0; i < n; i++) cin >> people[i];
	vector<vector<int>> adj(n);
	vector<bool> check(n);

	for (int i = 0; i < n; i++) {
		int cnt; cin >> cnt;
		for (int j = 0; j < n; j++) {
			int r; cin >> r;
			adj[i].push_back(r-1);
			adj[r - 1].push_back(i);
		}
	}

	check[0] = true;

	dfs(0, people, adj, check, n);

	cout << (res == 1e7 ? -1 : res);

	return 0;
}