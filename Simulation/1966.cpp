/*
	2019 01 10
	1966 프린터 큐
	Simulation

	- 성공 -
*/
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int getVeryImportant(int& n, int priority[100], bool out[100])
{
	int top = 0;

	for (int i = 0; i < n; i++)
		if (!out[i] && top < priority[i])
			top = priority[i];

	return top;
}

int solution(int n, int pos, int priority[100])
{
	bool isOut[100];
	memset(isOut, false, sizeof(isOut));
	int res = 1;
	int veryImportant = getVeryImportant(n, priority, isOut);
	int now = 0;
	queue<int> q;

	for (int i = 0; i < n; i++)
		q.push(i);

	while (true)
	{
		now = q.front();
		q.pop();

		if (now == pos && veryImportant == priority[now])
			break;

		if (veryImportant == priority[now])
		{
			res++;
			isOut[now] = true;
			veryImportant = getVeryImportant(n, priority, isOut);
		}
		else
			q.push(now);
	}

	return res;
}

int main()
{
	int tcc;

	cin >> tcc;

	for (int i = 0; i < tcc; i++)
	{
		int n, pos;
		int priority[100];
		cin >> n >> pos;
		for (int j = 0; j < n; j++)
			cin >> priority[j];

		cout << solution(n, pos, priority) << '\n';
	}

	return 0;
}