#include <iostream>
#include <algorithm>

using namespace std;

int score[300000];

int compare(const void *px, const void *py)
{
	int x = *(int *)px;
	int y = *(int *)py;

	if (x > y)
		return -1;
	else if (x < y)
		return 1;

	return 0;
}

int main()
{
	int n;

	int need = 0;
	int res = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> score[i];

	qsort(score, n, sizeof(int), compare);

	for (int i = 0; i < n; i++)
	{
		res += (score[i] + n >= need);

		need = max(need, score[i] + i + 1);
	}

	cout << res;

	return 0;
}