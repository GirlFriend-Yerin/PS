/*
	2019 01 06
	1389 케빈베이컨의 6단계 법칙
	DFS

	- 성공 -
*/
#include <iostream>

using namespace std;

bool adjMap[100][100];
int bacon[100];
int n;

void dfs(int num, int cnt, int checker[100])
{
	checker[num] = cnt;

	for (int i = 0; i < n; i++)
		if (adjMap[num][i] && checker[i] == -1)
			dfs(i, cnt + 1, checker);
		else if (adjMap[num][i] && checker[i] > cnt + 1)
			dfs(i, cnt + 1, checker);
}

int main()
{
	int m;
	int min = 100000;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		short x, y;
		cin >> x >> y;
		adjMap[x-1][y-1] = adjMap[y-1][x-1] = true;
	}

	for (int i = 0; i < n; i++)
	{
		int check[100];
		fill_n(check, n, -1);

		dfs(i, 0, check);

		for (int j = 0; j < n; j++)
			bacon[i] += check[j];

		if (min > bacon[i])
			min = bacon[i];
	}

	for (int i = 0; i < n; i++)
		if (min == bacon[i])
		{
			cout << i + 1;
			break;
		}
}