#include <iostream>
#include <string>

using namespace std;

void piterfan(int x, char board[5][75]) {
	board[0][x + 2] = board[1][x + 1] = board[1][x + 3] = board[2][x + 4] = board[3][x + 1] = board[3][x + 3] =board[4][x + 2] = '#';
	if (board[2][x] == '.') board[2][x] = '#';
}

void wendy(int x, char board[5][75]) {
	board[0][x + 2] = board[1][x + 1] = board[1][x + 3]
		= board[2][x] = board[2][x + 4] = board[3][x + 1]
		= board[3][x + 3] = board[4][x + 2] = '*';
}

int main()
{
	string str; cin >> str;
	int len = str.length();
	char board[5][75] = {};

	for (int i = 0; i < 5; i++)
		for (int j = 0; j <= (len * 5 - len); j++)
			board[i][j] = '.';

	piterfan(0, board);
	for (int i = 1; i < len; i++) {
		piterfan(i * 5 - i, board);
		if (!((i + 1) % 3))
			wendy(i * 5 - i, board);
	}

	for (int i = 0; i < len; i++)
		board[2][(4 * i) + 2] = str[i];

	for (int i = 0; i < 5; i++)
		cout << board[i] << '\n';

	return 0;
}