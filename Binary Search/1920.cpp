/*
	1920 게임
	Binary Search
	2019 01 30

	- 성공 -
*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;

	scanf("%d", &n);

	vector<int> numbers(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &numbers[i]);

	sort(numbers.begin(), numbers.end());

	scanf("%d", &m);

	vector<int> targets(m);

	for (int i = 0; i < m; i++)
		scanf("%d", &targets[i]);

	for (int i = 0; i < m; i++)
	{
		int left = 0, right = n-1;

		while (left < right)
		{
			int mid = (left + right) / 2;
			if (targets[i] < numbers[mid]) right = mid - 1;
			else if (targets[i] > numbers[mid]) left = mid + 1;
			else break;
		}

		printf("%d\n", targets[i] == numbers[(left + right) / 2] ? 1 : 0);
	}

	return 0;
}