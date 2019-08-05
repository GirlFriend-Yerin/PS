/*
	2110 공유기 설치
	Binary Search
	2019 02 12

	- 성공 -
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 200000;

bool exist[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, c;
	cin >> n >> c;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int left = 0, right = 1000000003;

	while (left <= right)
	{
		int cleft = c - 2;
		int cc = 0;
		int m = (left + right) / 2;

		for (int i = 0; i < n - 1; i++)
		{
			int d = v[i + 1] - v[i];
			if (cc + d <= m)
				cc += d;
			else
			{
				cleft--;
				cc = 0;
			}
		}

		if (cleft >= 0) right = m - 1;
		else
			left = m + 1;
	}

	cout << left;

	return 0;
}