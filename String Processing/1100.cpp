#include <iostream>

using namespace std;

const short MAX = 8;

int main()
{
	char board[MAX][MAX+1] = {};

	int res = 0;

	for (int i = 0; i < MAX; i++)
		cin >> board[i];

	for (int i = 0; i < MAX; i++)
	{
		// Odd
		if (i % 2)
		{
			for (int j = 1; j < MAX; j += 2)
				if (board[i][j] == 'F')
					res++;
		}
		// Even
		else
		{
			for (int j = 0; j < MAX; j += 2)
				if (board[i][j] == 'F')
					res++;
		}
	}

	cout << res;

	return 0;
}