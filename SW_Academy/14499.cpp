#include <iostream>

using namespace std;

const short BOARD_MAX = 20;
const short ORDER_MAX = 1000;

short board[BOARD_MAX][BOARD_MAX];

const short posX[5] = { 0, 0, 0, -1, 1 }; // µ¿ ¼­ ºÏ ³²
const short posY[5] = { 0, 1, -1, 0, 0 };
short dice[6];

void rollDice(int cmd)
{
	short temp[6];
	for (int i = 0; i < 6; i++)
		temp[i] = dice[i];

	if (cmd == 1)
	{
		dice[0] = temp[2];
		dice[2] = temp[5];
		dice[4] = temp[0];
		dice[5] = temp[4];

	}
	else if (cmd == 2)
	{
		dice[0] = temp[4];
		dice[2] = temp[0];
		dice[4] = temp[5];
		dice[5] = temp[2];
	}
	else if (cmd == 3)
	{
		dice[0] = temp[1];
		dice[1] = temp[5];
		dice[3] = temp[0];
		dice[5] = temp[3];
	}
	else if (cmd == 4)
	{
		dice[0] = temp[3];
		dice[1] = temp[0];
		dice[3] = temp[5];
		dice[5] = temp[1];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int row, col, d_x, d_y, order;

	cin >> row >> col >> d_x >> d_y >> order;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> board[i][j];

	for (int i = 0; i < order; i++)
	{
		int cmd;
		cin >> cmd;

		int nextX = d_x + posX[cmd];
		int nextY = d_y + posY[cmd];

		if (0 <= nextX && nextX < row && 0 <= nextY && nextY < col)
		{
			rollDice(cmd);

			d_x = nextX;
			d_y = nextY;

			if (board[d_x][d_y])
			{
				dice[0] = board[d_x][d_y];
				board[d_x][d_y] = 0;
			}
			else
				board[d_x][d_y] = dice[0];

			cout << dice[5] << '\n';
		}
	}

	return 0;
}