#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

const int MAX = 1000;

typedef pair<int, int> pii;

vector<vector<pii> >  adj;
vector<priority_queue<int> > res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	adj.resize(n + 1);
	res.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int t, d, w; cin >> t >> d >> w;

		adj[t].push_back({ d, w });
	}

	priority_queue<pii, vector<pii>, greater<> > pq;

	pq.push({ 0, 1 });
	res[1].push(0);

	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();

		for (int i = 0; i < adj[cur.second].size(); i++) {
			
			int next = adj[cur.second][i].first;
			int cost = adj[cur.second][i].second;
			
			if (res[next].size() < k) {
				res[next].push(cur.first + cost);
				pq.push({ cur.first + cost, next });
			}
			else if (res[next].top() > cur.first + cost) {
				res[next].pop();
				res[next].push(cur.first + cost);
				pq.push({ cur.first + cost, next });
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << (res[i].size() == k ? res[i].top() : -1) << '\n';

	return 0;
}