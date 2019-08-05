/*
	2019 01 07
	1697 - 숨바꼭질
	BFS

	- 성공 -
*/

#include <iostream>
#include <queue>

using namespace std;

bool check[110001];

int main()
{
	int subin, bro;
	int step = 0;
	bool found = false;
	queue<int> curQ;
	queue<int> nextQ;

	cin >> subin >> bro;

	if (subin != bro)
	{
		curQ.push(subin);

		while (!found)
		{
			while (!curQ.empty())
			{
				int cur = curQ.front();
				curQ.pop();

				if (cur == bro)
				{
					found = true;
					break;
				}
					
				check[cur] = true;

				if (cur > 0 && !check[cur - 1])
					nextQ.push(cur - 1);
				if (cur < bro && !check[cur + 1])
					nextQ.push(cur + 1);
				if (cur * 2 < 110000 && !check[cur * 2])
					nextQ.push(cur * 2);
			}

			if (!found)
			{
				while (!nextQ.empty())
				{
					curQ.push(nextQ.front());
					nextQ.pop();
				}
				step++;
			}

		}
		
	}

	cout << step;

	return 0;
}
