/*
	2019 1 1
	11724 연결 요소의 개수
	BFS

	- 성공 -
*/

#include <iostream>
#include <queue>

using namespace std;

bool adjMatrix[1000][1000];
bool check[1000];

int main()
{
	int n, m, count = 0;
	int startNum = -1;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		adjMatrix[x - 1][y - 1] = adjMatrix[y - 1][x - 1] = true;
	}

	for (int i = 0 ;i < n ; i++)
	{	
		if (check[i])
			continue;

		queue<int> q;
		q.push(i);

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			if (check[cur])
				continue;

			check[cur] = true;

			for (int j = 0; j < n; j++)
			{
				if (adjMatrix[cur][j])
					q.push(j);
			}
		}

		count++;
	}

	cout << count;

	return 0;
}