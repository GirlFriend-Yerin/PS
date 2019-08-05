#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200000;

const short posX[2] = { -1, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int conny, brown;
	bool isOver = false;
	int acc = 0;
	int res = 0;
	queue<int> bQ;
	queue<int> nQ;

	cin >> conny >> brown;

	bQ.push(brown);

	while (conny < MAX)
	{
		while (!bQ.empty())
		{
			int cur = bQ.front();
			bQ.pop();

			if (cur == conny || conny > MAX)
			{
				isOver = true;
				break;
			}

			for (int i = 0; i < 2; i++)
			{
				int next = cur + posX[i];
				if (0 <= next && next <= MAX)
					nQ.push(next);
			}

			int next = cur * 2;
			if (next <= MAX)
				nQ.push(next);
		}
		
		if (isOver)
			break;

		conny += (++acc);
		res++;
	
		while (!nQ.empty())
		{
			bQ.push(nQ.front());
			nQ.pop();
		}
	}

	if (isOver)
		cout << res;
	else
		cout << -1;

	return 0;
}