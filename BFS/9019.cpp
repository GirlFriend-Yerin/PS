/*
	2018 01 18
	9019 - DSLR
	BFS

	- ¼º°ø -
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int MAX = 100;
const int DIGIT_MAX = 10000;
const char DSLR[4] = { 'D', 'S', 'L', 'R' };
int pos = 0;

struct Register {
	string order;
	int res;

	Register() {};
	Register(int res) : res(res) { }
	Register(int res, string order) : res(res), order(order) {}
};

string func(int origin, int target)
{
	string answer;
	bool visited[10000] = {};
	bool isAdded[10000] = {};

	queue<Register> q;

	q.push(Register(origin));
	isAdded[origin] = true;

	while (!q.empty())
	{
		Register cur = q.front();
		q.pop();

		if (visited[cur.res])
			continue;

		visited[cur.res] = true;

		if (cur.res == target)
		{
			answer = cur.order;
			break;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int res = cur.res;
				switch (DSLR[i])
				{
				case 'D':
					res = ((res * 2) % DIGIT_MAX);
					break;
				case 'S':
					res = (res == 0 ? 9999 : res - 1);
					break;
				case 'L':
					res = ((res * 10) % DIGIT_MAX) + (res / 1000);
					break;
				case 'R':
					res = ((res % 10) * 1000) + (res / 10);
					break;
				default:
					break;
				}
				if (!isAdded[res])
				{
					isAdded[res] = true;
					q.push(Register(res, cur.order + DSLR[i]));
				}
					
			}
		}
	}

	return answer;
}

int main()
{
	int tcc;

	cin >> tcc;

	for (int i = 0; i < tcc; i++)
	{
		int origin, target;
		cin >> origin >> target;

		cout << func(origin, target) << '\n';
	}
	return 0;
}