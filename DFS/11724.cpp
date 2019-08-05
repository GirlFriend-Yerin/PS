/*
	2019 1 1
	11724 연결 요소의 개수
	DFS

	- 성공 -
*/

#include <iostream>

using namespace std;

bool adjMatrix[1000][1000];
bool check[1000];

void func(int start, int n) {

	if (check[start])
		return;

	check[start] = true;

	for (int i = 0; i < n; i++)
	{
		if (adjMatrix[start][i])
			func(i, n);
	}
}

int main()
{
	int n, m, count = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		adjMatrix[x-1][y-1] = adjMatrix[y-1][x-1] = true;
	}

	for (int i = 0 ; i < n ; i++)
	{
		if (check[i])
			continue;

		func(i, n);
		count++;
	}

	cout << count;

	return 0;
}