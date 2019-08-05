/*
	2018 01 05
	6603 - 로또
	DFS

	- 성공 -
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(const vector<int> num, int n, int pos, bool checker[13])
{
	if (n == 6)
	{
		for (int i = 0; i < num.size(); i++)
			if (checker[i])
				cout << num[i] << " ";
		cout << endl;
		return;
	}
	else if (n > 6 || pos == num.size())
		return;

	checker[pos] = true;
	dfs(num, n+1, pos + 1, checker);
	checker[pos] = false;
	dfs(num, n, pos + 1, checker);

}

int main()
{
	int k;

	cin >> k;

	while (k != 0)
	{
		vector<int> num(k);

		for (int i = 0; i < k; i++)
			cin >> num[i];

		bool checker[13];

		fill_n(checker, k, false);

		dfs(num, 0, 0, checker);
		cout << '\n';

		cin >> k;
	}


	return 0;
}