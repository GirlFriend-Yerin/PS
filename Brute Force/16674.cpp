/*
	2019 03 21
	16674 2018년을 돌아보며
	Brute Force

	- 성공 - 
*/
#include <iostream>

using namespace std;

int digits[10];

int main()
{
	int res = 1;
	char input[11];

	cin >> input;

	for (int i = 0; input[i] != '\0'; i++)
		digits[input[i] - '0']++;

	// Related
	for (int i = 0; i < 10; i++)
	{
		if (i == 0 || i == 1 || i == 2 || i == 8)
			continue;

		if (digits[i] != 0)
		{
			res = 0; break;
		}
	}

	if (res != 0)
	{
		res = 1;
		if (digits[0] && digits[1] && digits[2] && digits[8])
		{
			res = 2;
			if (digits[0] == digits[1] && digits[1] == digits[2] && digits[2] == digits[8])
				res = 8;
		}
	}

	cout << res;
	return 0;
}