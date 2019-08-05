/*
	2019 01 20
	1076 저항
	MatheMatics

	- 성공 -
*/

#include <iostream>
#include <cmath>

using namespace std;

int value(char* word)
{
	const char color[10][5] = { "bla", "bro", "r", "o", "y", "gree", "blu", "v", "grey", "w" };

	if (word[0] == 'b')
	{
		if (word[2] == 'a')
			return 0;
		else if (word[2] == 'o')
			return 1;
		else
			return 6;
	}
	else if (word[0] == 'g')
	{
		if (word[3] == 'e')
			return 5;
		else
			return 8;
	}
	else
	{
		for (int i = 0; i < 10; i++)
			if (word[0] == color[i][0])
				return i;
	}
	return -1;
}

int main()
{
	char words[3][7] = {};

	for (int i = 0; i < 3; i++)
		cin >> words[i];

	long long res = (value(words[0]) * 10 + value(words[1])) * powl(10, value(words[2]));

	cout << res;

	return 0;
}