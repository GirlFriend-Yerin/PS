#include <iostream>

using namespace std;

const short MAX = 20;
int n, res = 0;

void funcHorizontal(int origin[MAX], int result[MAX], int start)
{
	int pos = start;
	int tar = start;
	int adder = start == 0 ? 1 : -1;

	while (true)
	{
		// Move target Point
		for (; (0 <= tar && tar < n) && origin[tar] == 0; tar += adder);

		if (!(0 <= tar && tar < n))
			break;

		if (result[pos]) {
			if (result[pos] == origin[tar])
			{
				result[pos] *= 2;
				pos += adder;
			}
			else
			{
				pos += adder;
				result[pos] = origin[tar];
			}
		}
		else
			result[pos] = origin[tar];

		tar += adder;
	}
}

void funcVertical(int origin[MAX][MAX], int result[MAX][MAX], int col, int start)
{
	int pos = start;
	int tar = start;
	int adder = start == 0 ? 1 : -1;

	while (true)
	{
		// Move target Point
		for (; (0 <= tar && tar < n) && origin[tar][col] == 0; tar += adder);

		if (!(0 <= tar && tar < n))
			break;

		if (result[pos][col]) {
			if (result[pos][col] == origin[tar][col])
			{
				result[pos][col] *= 2;
				pos += adder;
			}
			else
			{
				pos += adder;
				result[pos][col] = origin[tar][col];
			}
		}
		else
			result[pos][col] = origin[tar][col];

		tar += adder;
	}

}

void solve(int board[MAX][MAX], int cnt)
{
	if (cnt == 5)
	{
		int temp_max = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (temp_max < board[i][j])
					temp_max = board[i][j];

		if (res < temp_max)
			res = temp_max;

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int next[MAX][MAX] = {};

		for (int j = 0; j < n; j++)
		{
			if (i == 0) // left
				funcHorizontal(board[j], next[j], 0);
			else if (i == 1) // right
				funcHorizontal(board[j], next[j], n - 1);
			else if (i == 2) // top
				funcVertical(board, next, j, 0);
			else // bottom
				funcVertical(board, next, j, n - 1);
		}

		solve(next, cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int board[MAX][MAX] = {};

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	solve(board, 0);

	cout << res;

	return 0;
}