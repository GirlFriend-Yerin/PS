/*
	2019 04 17

	Success
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> sums;
	sums.resize(4);

	for (int i = 0; i < 4; i++)
		cin >> sums[i];

	sort(sums.begin(), sums.end());

	for (int i = 0; i < 3; i++)
		cout << sums[3] - sums[i] << ' ';

	return 0;
}