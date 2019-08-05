#include <iostream>

using namespace std;

const short MAX = 50;

bool board[MAX][MAX];
bool target[MAX][MAX];

void invert(bool board[MAX][MAX], int sX, int sY)
{
	for (int r = 0; r < 3; r++)
		for (int c = 0; c < 3; c++)
			board[sX + r][sY + c] = !board[sX + r][sY + c];
}

int solveHorizon(int n, int m)
{
	int res = 0;
	bool temp[MAX][MAX] = {};

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp[i][j] = board[i][j];

	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 2; j++)
		{
			if (temp[i][j] ^ target[i][j])
			{
				invert(temp, i, j);
				res++;
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (temp[i][j] != target[i][j])
				return -1;

	return res;
}

int solveVertical(int n, int m)
{
	int res = 0;
	bool temp[MAX][MAX] = {};

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp[i][j] = board[i][j];

	for (int i = 0; i < m - 2; i++)
	{
		for (int j = 0; j < n - 2; j++)
		{
			if (temp[j][i] ^ target[j][i])
			{
				invert(temp, j, i);
				res++;
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (temp[i][j] != target[i][j])
				return -1;

	return res;
}

int mMin(int a, int b) { return a < b ? a : b; }

int main()
{
	int n, m;
	int res = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		char input[MAX + 1] = {};
		cin >> input;

		for (int j = 0; j < m; j++)
			board[i][j] = input[j] - '0';
	}

	for (int i = 0; i < n; i++)
	{
		char input[MAX + 1] = {};
		cin >> input;

		for (int j = 0; j < m; j++)
			target[i][j] = input[j] - '0';
	}

	int verRes = solveVertical(n, m);
	int horRes = solveHorizon(n, m);

	if (verRes == -1)
		res = horRes;
	else if (horRes == -1)
		res = verRes;
	else
		res = mMin(verRes, horRes);

	cout << res;

	return 0;
}