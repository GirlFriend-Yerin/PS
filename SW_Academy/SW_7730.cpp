/*
	2805 나무자르기
	Binary Search
	2019 02 15

	- 성공 -
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long remain(vector<int>& vec, int val)
{
	long long sum = 0;

	for (int i = 0; i < vec.size(); i++)
		if (vec[i] > val)
			sum += (vec[i] - val);
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++)
	{
		long long n, m;
		cin >> n >> m;

		vector<int> woods(n);

		int left = 0, right = 0;

		for (int i = 0; i < n; i++) {
			cin >> woods[i];

			if (right < woods[i])
				right = woods[i];
		}

		right += 3;

		int res = 0;
		while (left <= right)
		{
			int middle = (left + right) / 2;

			if (remain(woods, middle) >= m)
			{
				left = middle + 1;
				res = max(res, middle);
			}
			else
			{
				right = middle - 1;
			}
		}
		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}