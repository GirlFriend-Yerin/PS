/*
	2018 12 28
	2644 - 촌수계산
	BFS

	- 성공 -
*/

#include <iostream>

using namespace std;

int relation[100][100];
int check[100];

int queue[100];
int pos = -1;

void push(int val)
{
	queue[++pos] = val;
}

int pop()
{
	return queue[pos--];
}

bool isEmpty()
{
	return pos == -1;
}

int main()
{
	int n;
	int m;
	int t_x, t_y; // target_x, target_y
	int res = 0;
	bool isFind = false;

	cin >> n >> t_x >> t_y >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y; // x - parent, y - child
		cin >> x >> y;
		relation[x][y] = 1;
		relation[y][x] = 1;
	}

	push(t_x);
	check[t_x] = 1;
	while (!isEmpty())
	{
		int cur = pop();

		if (cur == t_y)
		{
			isFind = true;
			res = check[cur] -1 ;
			break;
		}

		for (int i = 1; i < n+1; i++)
		{
			if (relation[cur][i] == 1 && check[i] == 0)
			{
				check[i] = check[cur] + 1;
				push(i);
			}
		}
	}

	if (isFind)
		cout << res;
	else
		cout << -1;

	return 0;
}