/*
	8986 Àüº¿´ë
	Binary Search
	2019 02 15

	-  -
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];

	int left = 0, right = vec[n - 1];
	long long res = 10000000000000;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		long long moveSum = 0;
		for (int i = 1; i < n; i++)
			moveSum += abs(vec[i - 1] + middle - vec[i]);

		if (res > moveSum)
			left = middle + 1;
		else
			right = middle - 1;
		res = min(res, moveSum);
	}

	return 0;
}