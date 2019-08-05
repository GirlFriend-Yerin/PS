#include <iostream>

using namespace std;

char input[5][16];

int main()
{
	for (int i = 0; i < 5; i++)
		cin >> input[i];

	char res[5 * 15 + 1] = {};
	int pos = 0;

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (input[j][i])
				res[pos++] = input[j][i];
		}
	}

	cout << res;

	return 0;
}