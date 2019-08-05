/*
	2019 01 17
	1157 단어 공부
	문자열 처리

	- 성공 -
*/
#include <iostream>
#include <string>

using namespace std;

int alphaCount[26];

int main()
{
	int maxCount = 0;
	int res = -1;
	string input;

	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		if ('a' <= input[i] && input[i] <= 'z')
			input[i] -= ('a' - 'A');
		alphaCount[(input[i] - 'A')]++;
	}

	for (int i = 0; i < 26; i++)
		if (maxCount < alphaCount[i])
			maxCount = alphaCount[i];

	for (int i = 0; i < 26; i++)
	{
		if (maxCount == alphaCount[i])
		{
			if (res >= 0)
			{
				res = '?';
				break;
			}
			else
				res = i;

		}
	}

	cout << char(res < 26 ? res + 'A' : res);

	return 0;
}