#include <iostream>
#include <string.h>

using namespace std;

const short MAX = 1000;

int minPos(char* line, int len)
{
	int res = 0;

	for (int i = 1; i < len - 1; i++)
	{
		int resSum = (line[res] - '0') + (line[res + 1] - '0');
		int curSum = (line[i] - '0') + (line[i + 1] - '0');

		if (resSum < curSum)
			res = i;
	}

	return res;
}

void link(char* data, int len, int pos)
{
	for (int i = pos; i < len; i++)
		data[i] = data[i + 1];
}

int main()
{
	int tcc;

	cin >> tcc;

	for (int i = 0; i < tcc; i++)
	{
		char input[MAX + 1];
		int len;
		bool flag = true;

		cin >> input;

		len = strlen(input);

		while (len > 1)
		{
			int pos = minPos(input, len);
			int cal = (input[pos] - '0') + (input[pos + 1] - '0');

			if (cal < 10)
			{
				input[pos] = cal + '0';
				link(input, len, pos + 1);

				--len;
			}
			else
			{
				input[pos] = (cal / 10) + '0';
				input[pos + 1] = (cal % 10) + '0';
			}

			flag = !flag;
		}

		cout << '#' << i + 1 << ' ' << (flag ? 'B' : 'A') << '\n';
	}

	return 0;
}