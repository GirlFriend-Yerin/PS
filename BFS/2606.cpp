/*
	2019 03 06
	2606 바이러스
	bfs

	- 성공 -
*/
#include <iostream>
#include <queue>

using namespace std;

const short MAX = 100;

bool adj[MAX][MAX];
bool checker[MAX] = { true , };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int computers, line, res = 0;
	queue<int> q;

	cin >> computers >> line;

	for (int i = 0; i < line; i++)
	{
		int to, des;

		cin >> to >> des;

		adj[to - 1][des - 1] = adj[des - 1][to - 1] = true;
	}

	q.push(0);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < computers; i++)
			if (adj[cur][i] && !checker[i])
			{
				checker[i] = true;
				q.push(i);
			}
	}

	for (int i = 1; i < computers; i++)
		if (checker[i])
			res++;

	cout << res;

	return 0;
}