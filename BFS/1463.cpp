/*
	2019 03 30
	1로 만들기
	BFS

	- 성공 -
*/

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000000;

bool check[MAX + 1];

int main()
{
	int n;
	int res = 0;
	bool isOver = false;
	queue<int> q;
	queue<int> nextQ;

	cin >> n;

	q.push(n);
	check[n] = true;

	while (!isOver)
	{
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			if (cur == 1)
			{
				isOver = true;
				break;
			}

			if (cur % 3 == 0 && cur / 3 != 0 && !check[cur / 3])
			{
				check[cur / 3] = true;
				nextQ.push(cur / 3);
			}

			if (cur % 2 == 0 && cur / 2 != 0 && !check[cur / 2])
			{
				check[cur / 2] = true;
				nextQ.push(cur / 2);
			}

			if (cur - 1 > 0 && !check[cur - 1])
			{
				check[cur - 1] = true;
				nextQ.push(cur - 1);
			}
		}

		if (isOver)
			continue;

		while (!nextQ.empty())
		{
			q.push(nextQ.front());
			nextQ.pop();
		}

		res++;
	}

	cout << res;

	return 0;
}