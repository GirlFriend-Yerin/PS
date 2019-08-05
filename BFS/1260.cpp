/*
	2019 01 07
	1260 - DFS�� BFS
	DFS BFS

	- ���� -
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
	// �湮 Ȯ��
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
	
	// DFS ����
	DFS(start-1);

	// DFS BFS ����
	cout << '\n';

	// BFS
	q.push(start - 1);
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		// �� �湮�� ������� �ʰ� ���� ��� Ž��
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