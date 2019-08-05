/*
	2019 01 15
	10610 30
	Greedy Algorithm

	- ¼º°ø -
*/
#include <iostream>
#include <string>

using namespace std;

const int MAX = 100000;

int main()
{
	int digits[10] = {};
	char res[MAX + 1] = { '-', '1', };

	string input;

	cin >> input;

	for (int i = 0; i < input.length(); i++)
		digits[input[i] - '0']++;

	if (digits[0])
	{
		int isAble = 0;
		for (int i = 1; i < 10; i++)
			isAble += i * digits[i];

		if (isAble % 3 == 0)
		{
			int pos = 9;
			for (int i = 0; i < input.length(); i++)
			{
				while (digits[pos] == 0)
					pos--;
				res[i] = pos + '0';
				digits[pos]--;
			}
		}
	}

	cout << res;

	return 0;
}