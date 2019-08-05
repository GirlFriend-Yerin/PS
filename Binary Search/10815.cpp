/*
	10815 카드 게임
	Binary Search
	2019 02 18

	- 성공 -
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nArray, mArray;

bool search(int target, int len)
{
	int left = 0, right = len -1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (target <= nArray[middle])
			right = middle - 1;
		else
			left = middle + 1;
	}

	if (nArray[left] == target)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;

	nArray.resize(n);

	for (int i = 0; i < n; i++)
		cin >> nArray[i];

	cin >> m;

	mArray.resize(m);
	for (int i = 0; i < m; i++)
		cin >> mArray[i];
	
	sort(nArray.begin(), nArray.end());

	for (int i = 0; i < m; i++)
		cout << search(mArray[i], n) << ' ';

	return 0;
}