/*
	2018 12 28
	1325 - ȿ������ ��ŷ
	bfs

	- ���� -
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> childs[10001];
int childcount[10001];
int mqueue[100001];
int top = 0;
int bot = 0;

void push(int x)
{
	mqueue[top++%(100000)] = x;
}

int pop() {
	return mqueue[bot++% (100000)];
}

bool isempty() {
	return (top% (100000)) == (bot% (100000));
}

int main()
{
	int n, m;
	int max = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		childs[b].push_back(a);
	}

	for (int i = 1; i < n + 1; i++)
	{
		push(i);

		bool check[10001]; // Ž���� �ߴ��� Ȯ��
		bool isadded[10001]; // ���� ��尡 �̹� �߰��� ������� Ȯ��

		fill_n(check, n + 1, false);
		fill_n(isadded, n + 1, false);

		isadded[i] = true; // ���� ���� �߰��� ������ ����

		while (!isempty())
		{
			int cur = pop();

			if (check[cur])
				continue;

			check[cur] = true; 

			for (int j = 0; j < childs[cur].size(); j++)
			{
				int idx = childs[cur][j];

				if (!isadded[idx])
				{
					push(idx);
					childcount[i]++;
					isadded[idx] = true;
				}
			}
		}
	}

	for (int i = 1; i < n +1; i++)
		if (max < childcount[i])
			max = childcount[i];

	for (int i = 1; i < n + 1; i++)
		if (max == childcount[i])
			cout << i << " ";

	return 0;
}