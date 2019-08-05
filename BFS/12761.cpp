/*
	2019 01 31
	12761 돌다리
	BFS

	- 성공 -
*/
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;

bool check[MAX + 1];

int pos[8] = { 1, -1 , 1, 1, -1, -1, 1, 1};

int main()
{
	bool isOver = false;
	int count = 0;
	int a, b, n, m;
	queue<int> q;
	queue<int> nextQ;

	cin >> a >> b >> n >> m;

	q.push(n);
	check[n] = true;

	while (!q.empty())
	{
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			if (cur == m)
			{
				isOver = true;
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				int next = cur + pos[i]; // 좌우 1칸

				if (i < 2)
					next = cur + pos[i];
				else if (i < 6)
					next = cur + (pos[i] * (i % 2 ? a : b)); // 좌우 A B 칸 이동
				else
					next = cur * (pos[i] * (i % 2 ? a : b)); // 우 현재의 A B 배 이동 ( 좌측은 존재가 불가 )

				if (0 <= next && next <= MAX && !check[next])
				{
					check[next] = true;
					nextQ.push(next);
				}
			}
		}

		if (isOver)
			break;

		while (!nextQ.empty())
		{
			q.push(nextQ.front());
			nextQ.pop();
		}
		count++;
	}

	cout << count;

	return 0;
}