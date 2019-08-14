#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 100000;
const int INF = 1000005;
const int MAX_DEP = 18;

typedef pair<int, int> pii;

vector<vector<pii>> adj;
pii _dep[MAX]; // 깊이, 위치
int par[MAX][MAX_DEP + 1];
int _len_min[MAX][MAX_DEP + 1];
int _len_max[MAX][MAX_DEP + 1];

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }
int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

void dfs(int node, int depth, int weight, bool visited[MAX]) {
	visited[node] = true;
	_dep[node].first = depth;
	_dep[node].second = weight;

	_len_min[node][0] = weight;
	_len_max[node][0] = weight;

	for (int i = 1; i < MAX_DEP ; i++)
		par[node][i] = par[par[node][i - 1]][i - 1];


	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i].first;
		if (!visited[next]) {
			par[next][0] = node;
			dfs(next, depth + 1, adj[node][i].second, visited);
		}
	}
}

void setMinMax(const int n) {
	for (int i = 1; i < MAX_DEP + 1; i++) {
		for (int j = 0; j < n; j++) {
			_len_min[j][i] = _min(_len_min[j][i - 1], _len_min[par[j][i - 1]][i -1]);
			_len_max[j][i] = _max(_len_max[j][i - 1], _len_max[par[j][i - 1]][i - 1]);
		}
	}
}

void solve(int to, int des) {

	int retMin = INF, retMax = -1;

	if (_dep[to].first != _dep[des].first) {

		if (_dep[to].first > _dep[des].first)
			swap(to, des);

		for (int i = MAX_DEP; i >= 0; i--) {
			if (_dep[to].first <= _dep[par[des][i]].first) {
				retMin = _min(retMin, _len_min[des][i]);
				retMax = _max(retMax, _len_max[des][i]);
				des = par[des][i];
			}
		}
	}

	int lca = to;

	if (to != des) {

		for (int i = MAX_DEP; i >= 0; i--) {
			if (par[to][i] != par[des][i]) {
				retMax = _max(retMax, _max(_len_max[to][i], _len_max[des][i]));
				retMin = _min(retMin, _min(_len_min[to][i], _len_min[des][i]));
				to = par[to][i], des = par[des][i];
			}

			lca = par[to][i];
		}

	}

	if (to != lca) {
		retMin = _min(retMin, _min(_len_min[to][0], _len_min[des][0] ));
		retMax = _max(retMax, _max(_len_max[to][0], _len_max[des][0] ));
	}


	cout << retMin << ' ' << retMax << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	adj.resize(n);

	for (int i = 0; i < n - 1; i++) {
		int a, b, len; cin >> a >> b >> len;

		adj[a - 1].push_back({ b - 1, len });
		adj[b - 1].push_back({ a - 1, len });
	}

	bool visited[MAX] = {};

	dfs(0, 0, 0, visited);
	setMinMax(n);

	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		int to, des; cin >> to >> des;

		solve(to -1, des - 1);
	}

	return 0;
}
