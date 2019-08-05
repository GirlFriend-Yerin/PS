/*
	2019 01 07
	1260 - DFS와 BFS
	DFS BFS

	- 성공 -
*/
#include <iostream>
#include <queue>

using namespace std;

int n;
bool adjMat[1000][1000];
bool dfsCheck[1000];
bool bfsCheck[1000];

void DFS(int pos)
{
	// 방문 확인
	dfsCheck[pos] = true;
	cout << pos + 1 << ' ';

	for (int i = 0; i < n; i++)
	{
		if (adjMat[pos][i] && !dfsCheck[i])
			DFS(i);
	}
}

int main()
{
	int m, start;
	queue<int> q;

	cin >> n >> m >> start;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adjMat[x - 1][y - 1] = adjMat[y - 1][x - 1] = true;
	}
	
	// DFS 실행
	DFS(start-1);

	// DFS BFS 구분
	cout << '\n';

	// BFS
	q.push(start - 1);
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		// 재 방문시 출력하지 않고 다음 노드 탐색
		if (bfsCheck[cur])
			continue;

		bfsCheck[cur] = true;
		cout << cur + 1 << ' ';

		for (int i = 0; i < n; i++)
		{
			if (adjMat[cur][i])
				q.push(i);
		}
	}

	return 0;
}