#include <iostream>

using namespace std;

const int MAX = 405;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;
	
	while (tcc--)
	{
		int r, c; cin >> r >> c;
		char table[MAX][MAX] = {};

		for (int i = 0; i < r; i++)
			cin >> table[i];
	
		int res = 0;

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				res += (table[i][j] == '>' && j + 2 < c && table[i][j + 1] == 'o' && table[i][j + 2] == '<') || (table[i][j] == 'v' && i + 2 < r && table[i + 1][j] == 'o' && table[i + 2][j] == '^');

		cout << res << '\n';
	}

	return 0;
}