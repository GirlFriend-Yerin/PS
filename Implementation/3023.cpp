#include <iostream>
#include <string>

using namespace std;

const int MAX = 50;

int main()
{
	int n, m; cin >> n >> m;
	char board[MAX * 2][MAX * 2 + 1] = {};
	char input[MAX][MAX + 2] = {}; for (int i = 0; i < n; i++) cin >> input[i];
	int ex, ey; cin >> ex >> ey;


	// left top
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board[i][j] = input[i][j];

	// right top
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board[i][(2 * m) - j - 1] = input[i][j];

	// left bottom
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board[(2 * n) - i - 1][j] = input[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board[(2 * n) - i - 1][(2 * m) - j - 1] = input[i][j];

	board[ex - 1][ey - 1] = board[ex - 1][ey - 1] == '.' ? '#' : '.';

	for (int i = 0; i < 2 * n; i++)
		cout << board[i] << '\n';


	return 0;
}