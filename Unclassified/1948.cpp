#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 10000;

int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

struct Node {
	int to, time;

	Node() {};
	Node(int to, int time) : to(to), time(time) {};
};

struct rNode {
	int to, time, cnt;

	rNode() {};
	rNode(int to, int time, int cnt) : to(to), time(time), cnt(cnt) {};
};

int acc[MAX];
int record[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	int time = 0, noneStop = 0;
	vector<vector<Node>> adj(n);
	vector<vector<Node>> radj(n);

	for (int i = 0; i < m; i++) {
		int to, des, time; cin >> to >> des >> time;
		adj[to - 1].push_back(Node(des - 1, time));
		radj[des - 1].push_back(Node(to - 1, time));
		++acc[des - 1];
	}

	queue<Node> q;
	int start, goal; cin >> start >> goal;
	q.push(Node(start - 1, 0));

	while (!q.empty()) {
		Node cur = q.front(); q.pop();

		if (cur.to == goal - 1) {
			time = _max(time, cur.time);
			continue;
		}

		for (int i = 0; i < adj[cur.to].size(); i++) {
			Node next = adj[cur.to][i];
			record[next.to] = _max(record[next.to], cur.time + next.time);

			if (!--acc[next.to]) q.push(Node(next.to, record[cur.to] + next.time));
		}
	}

	queue<rNode> rq;
	rq.push(rNode(goal-1, time, 0));

	while (!rq.empty())
	{
		rNode cur = rq.front(); rq.pop();

		if (cur.to == start - 1 && !cur.time) {
			noneStop += cur.cnt;
			break;
		}

		for (int i = 0; i < radj[cur.to].size(); i++) 
			rq.push(rNode(radj[cur.to][i].to, cur.time - radj[cur.to][i].time, cur.cnt + 1));
	}

	cout << time << '\n' << noneStop;

	return 0;
}