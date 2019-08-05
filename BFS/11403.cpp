/*
	2018 12 26
	11403 - 경로찾기
	BFS

	- 성공 - 
*/

#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
int moveMap[100][100];

int main()
{
	int caseCount;

	cin >> caseCount;

	for (int i = 0; i < caseCount; i++)
		for (int j = 0; j < caseCount; j++)
			cin >> map[j][i];

	for (int i = 0; i < caseCount; i++)
	{
		queue<int> q;
		bool check[100] = { false , };
		// Start
		q.push(i);

		while (!q.empty())
		{
			// Current Point
			int cLine = q.front();
			q.pop();

			if (check[cLine])
				continue;

			check[cLine] = true;

			// Check Connect Point
			for (int j = 0; j < caseCount; j++)
			{
				if (map[j][cLine] == 1)
				{
					q.push(j);
					moveMap[j][i] = 1;
				}
			}
		}
	}

	for (int i = 0; i < caseCount; i++)
	{
		for (int j = 0; j < caseCount; j++)
			cout << moveMap[j][i] << " ";
		cout << endl;
	}
	

	return 0;
}