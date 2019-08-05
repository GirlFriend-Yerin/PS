#include <iostream>

using namespace std;

const short MAX = 500;

short board[MAX][MAX];

int val[MAX];

int n, m;

bool func(int pos, int xorV)
{
	bool res = false;
	if (pos == n) {
		if (xorV != 0)
			res = true;
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			val[pos] = i;
			if (func(pos + 1, xorV ^ board[pos][i])) {
				res = true;
				break;
			}
		}
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	if (func(0, 0)) {
		cout << "TAK\n";
		for (int i = 0; i < n; i++)
			cout << val[i] + 1 << ' ';
	}
	else
		cout << "NIE";

	return 0;
}