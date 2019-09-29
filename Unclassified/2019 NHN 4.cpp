#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Edge {
	int next;
	int cost;

	Edge() {};
	Edge(int n,int  c) : next(n), cost(c) {};
};

struct Path {
	string path;
	int remain;
	int fuel;
	bool reach;

	Path() {};
	Path(string path, int r, int f, bool reach) : path(path), remain(r), fuel(f), reach(reach) {};

	bool operator<(Path& p) {
		if (reach != p.reach)
			return reach < p.reach;

		if (remain != p.remain)
			return remain > p.remain;
		return fuel < p.fuel;
	}
};
vector<vector<Edge>> adj(26);
vector<Path> res;
int n;

bool visited[26] = {};

void bruteForce(int cur, int fuel, int remain, string path) {

	if (cur == n - 1)
		res.push_back(Path(path, remain + 100, fuel, true));
	else {
		int pathCnt = adj[cur].size();
		for (int i = 0; i < pathCnt; i++) {
			Edge next = adj[cur][i];

			if (next.cost <= fuel && !visited[next.next]) {
				char nextCh = next.next + 'A';
				visited[next.next] = true;
				bruteForce(next.next, fuel - next.cost + 10, remain + 200, path + nextCh);
				visited[next.next] = false;
			}
			else {
				if (!visited[next.next])
					res.push_back(Path(path, remain + 300, fuel, false));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int f; cin >> n >> f;
	int k; cin >> k;

	for (int i = 0; i < k; i++) {
		char to, des;
		int cost;
		cin >> to >> des >> cost;
		adj[to - 'A'].push_back(Edge(des - 'A', cost));
		adj[des - 'A'].push_back(Edge(to - 'A', cost));

	}

	visited[0] = true;

	bruteForce(0, 30, 0, "A");

	sort(res.begin(), res.end());

	if (res.size() == 1) {
		for (int i = 0; res[0].path[i]; i++)
			cout << res[0].path[i] << ' ';
		cout << res[0].remain << ' ' << res[0].fuel;
	}
	else {
		bool same = false;
		for (int i = 0; i < n; i++) {
			if (res[i].fuel == res[i + 1].fuel && res[i].remain == res[i + 1].remain)
				same = true;
			else {
				for (int i = 0; res[0].path[i]; i++)
					cout << res[0].path[i] << ' ';
				cout << res[0].remain << ' ' << res[0].fuel;
			}
		}
	}

	return 0;
}