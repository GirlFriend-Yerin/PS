/*
	2019 04 02
	1141E Superhero Battles
	Math

	- Success - 6 Submission
*/
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int start, des;
	int res = 0;
	bool isOver = false;

	cin >> start >> des;

	queue<int> q;
	queue<int> nextQ;

	q.push(start);
	
	while (!q.empty())
	{
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			if (cur == des) {
				isOver = true;
				break;
			}

			int mulBy2 = cur * 2;
			int mulBy3 = cur * 3;
			if (0 <= mulBy2 && mulBy2 <= des)
				nextQ.push(mulBy2);

			if (0 <= mulBy3 && mulBy3 <= des)
				nextQ.push(mulBy3);
		}

		if (isOver)
			break;

		while (!nextQ.empty()) {
			q.push(nextQ.front());
			nextQ.pop();
		}

		res++;
	}

	if (isOver)
		cout << res;
	else
		cout << -1;

	return 0;
}