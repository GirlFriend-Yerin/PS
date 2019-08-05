/*
	2018 12 31
	5014 스타트링크
	bfs

	-  -
*/

#include <iostream>
#include <queue>

using namespace std;

bool check[1000000];

int main()
{
	int roofTop, start, target, up, down;
	int tryCount = 0;

	queue<int> recordQ;
	queue<int> tryQ;

	cin >> roofTop >> start >> target >> up >> down;

	tryQ.push(start);

	do {
		while (!tryQ.empty())
		{
			int cur = tryQ.front();
			tryQ.pop();

			if (cur == target)
			{
				cout << tryCount;
				return 0;
			}

			if (cur + up <= roofTop)
				if (!check[cur + up])
				{
					recordQ.push(cur + up);
					check[cur + up] = true;
				}
					
			if (cur - down > 0)
				if (!check[cur - up])
				{
					recordQ.push(cur - down);
					check[cur - up] = true;
				}
		}

		tryCount++;
		while (!recordQ.empty())
		{
			tryQ.push(recordQ.front());
			recordQ.pop();
		}
	} while (!tryQ.empty());
	
	cout << "use the stairs";
	return 0;
}