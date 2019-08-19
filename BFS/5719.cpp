#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const short MAX = 500;
const int INF = 1e8 + 5;

typedef pair<short, int> psi;
typedef pair<int, int> pii;

void dijkstra(int weight[MAX][MAX], vector<int>& mem, const int start, const int des, const int n) {

	mem.resize(n);
	for (int i = 0; i < n; i++) mem[i] = -1;

	priority_queue<psi> pq;

	pq.push({ 0, start });

	while (!pq.empty()) {
		psi cur = pq.top(); pq.pop();

		if (mem[cur.second] != -1) continue;
		mem[cur.second] = -cur.first;

		for (int i = 0; i < n; i++) {
			if (weight[cur.second][i] && mem[i] == -1) {
				pq.push({ cur.first - weight[cur.second][i], i });
			}
		}
	}
}

void removePath(int weight[MAX][MAX], vector<int>& mem, const int end, const int n) {
	queue<int> q;

	q.push(end);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < n; i++) {
			if (mem[cur] == mem[i] + weight[i][cur] && weight[i][cur]) {
				weight[i][cur] = 0;
				q.push(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	while (n && m) {
		int start, end; cin >> start >> end;

		int weight[MAX][MAX] = {};

		for (int i = 0; i < m; i++) {
			int t, d, w; cin >> t >> d >> w;

			weight[t][d] = w;
		}

		vector<int> mem;

		dijkstra(weight, mem, start, end, n);
		removePath(weight, mem, end, n);
		dijkstra(weight, mem, start, end, n);

		cout << mem[end] << '\n';

		cin >> n >> m;
	}

	return 0;
}