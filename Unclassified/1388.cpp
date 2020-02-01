#include <iostream>

using namespace std;

const int MAX = 105;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool checker[MAX][MAX] = {};
	char table[MAX][MAX] = {};
	int n, m, res = 0; cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> table[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (checker[i][j]) continue;
			res++;

			if (table[i][j] == '-')
				for (int cursor = j; cursor < m && table[i][cursor] == '-'; cursor++)
					checker[i][cursor] = true;
			else
				for (int cursor = i; cursor < n && table[cursor][j] == '|'; cursor++)
					checker[cursor][j] = true;
		}

	cout << res;

	return 0;
}