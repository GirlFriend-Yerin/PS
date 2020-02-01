/*
	2019 11 10
	5014 스타트링크
	bfs

	- 성공 -
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Step {
	int cur;
	int cnt;

	Step() {};
	Step(int cur, int cnt) : cur(cur), cnt(cnt) {};
};

int bfs(vector<bool>& visited, int start, int goal, int u, int d) {

	int top = visited.size();
	visited[start] = true;
	int pos[] = { u , -d };

	queue<Step> q;
	q.push(Step(start, 0));

	while (!q.empty())
	{
		Step cur = q.front(); q.pop();

		if (cur.cur == goal)
			return cur.cnt;

		for (int i = 0; i < 2; i++) {
			int next = cur.cur + pos[i];

			if (0 < next && next < top && !visited[next]) {
				visited[next] = true;
				q.push(Step(next, cur.cnt + 1));
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int f, s, g, u, d; cin >> f >> s >> g >> u >> d;
	vector<bool> visited(f + 1);

	int res = bfs(visited, s, g, u, d);

	if (res == -1)
		cout << "use the stairs";
	else
		cout << res;
	return 0;
}