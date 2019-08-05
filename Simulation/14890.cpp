#include <iostream>

using namespace std;

const short MAX = 100;

short board[MAX][MAX];

bool checkVertical(const int row, int max, int len)
{
	bool stair[MAX] = {};

	for (int cur = 0; cur < max;)
	{
		int next = cur + 1;
		if (next == max)
			break;

		if (board[cur][row] == board[next][row])
			cur = next;
		else if (board[cur][row] - 1 == board[next][row])
		{
			if (cur + len >= max)
				return false;

			short origin = board[next][row];

			for (int i = 0; i < len; i++)
				if (stair[next + i] || origin != board[next + i][row])
					return false;
				else
					stair[next + i] = true;

			cur += len;
		}
		else if (board[cur][row] + 1 == board[next][row])
		{
			if (next - len < 0)
				return false;

			short origin = board[cur][row];

			for (int i = 0; i < len; i++)
				if (stair[cur - i] || origin != board[cur - i][row])
					return false;
				else
					stair[cur - i] = true;

			cur = next;
		}
		else
			return false;
	}

	return true;
}

bool checkHorizontal(int col, int max, int len)
{
	bool stair[MAX] = {};

	for (int cur = 0; cur < max;)
	{
		int next = cur + 1;
		if (next == max)
			break;

		if (board[col][cur] == board[col][next])
			cur = next;
		else if (board[col][cur] - 1 == board[col][next])
		{
			if (cur + len >= max)
				return false;

			short origin = board[col][next];

			for (int i = 0; i < len; i++)
				if (stair[next + i] || origin != board[col][next + i])
					return false;
				else
					stair[next + i] = true;

			cur += len;

		}
		else if (board[col][cur] + 1 == board[col][next])
		{
			if (next - len < 0)
				return false;

			short origin = board[col][cur];

			for (int i = 0; i < len; i++)
				if (stair[cur - i] || origin != board[col][cur - i])
					return false;
				else
					stair[cur - i] = true;

			cur = next;
		}
		else
			return false;
	}

	return true;
}

int main()
{
	int n, l;
	int res = 0;

	cin >> n >> l;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++)
	{
		res += checkVertical(i, n, l);
		res += checkHorizontal(i, n, l);
	}

	cout << res;

	return 0;
}