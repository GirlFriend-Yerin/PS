/*
	2019 01 31
	1963 소수경로
	BFS

	- 성공 -
*/
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 10000;
const int RANGE_MAX = 9000;
bool prime[MAX + 1];

void init()
{
	prime[0] = prime[1] = true;

	for (int i = 2; i < (MAX / 2) + 1; i++)
	{
		if (prime[i])
			continue;

		for (int j = 2; (i * j) < MAX + 1; j++)
			prime[i * j] = true;
	}
}

int main()
{
	int tcc = 0;

	cin >> tcc;

	init(); // prime Init

	for (int i = 0; i < tcc; i++)
	{
		int start, des;
		int count = 0;
		queue<int> q;
		queue<int> nextQ;
		bool isOver = false;
		bool check[RANGE_MAX];
		memset(check, false, sizeof(check));

		cin >> start >> des;

		q.push(start);
		check[start] = true;

		while (!q.empty())
		{
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if (cur == des)
				{
					isOver = true;
					break;
				}

				int posMax = 10000;
				int posMin = 1000;

				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (i == 0 && j == 0)
							continue;

						int cal = ((cur / posMax) * posMax) + (j * posMin) + (cur % posMin);

						if (!prime[cal] && !check[cal-1000])
						{
							check[cal-1000] = true;
							nextQ.push(cal);
						}
					}
					posMax /= 10;
					posMin /= 10;
				}
			}

			if (isOver)
				break;
			else
			{
				while (!nextQ.empty())
				{
					q.push(nextQ.front());
					nextQ.pop();
				}
				++count;
			}
		}
		cout << count << '\n';
	}
	
	return 0;
}