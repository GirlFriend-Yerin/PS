#include <iostream>

using namespace std;

const int MAX = 5000;

int main()
{
	int alphaCount[26] = { };
	int maxCount = 0;
	int input;

	while ((input = cin.get()) != '\n')
	{
		if ('a' <= input && input <= 'z')
			alphaCount[input - 'a']++;
	}

	
	for (int i = 0; i < 26; i++)
		if (maxCount < alphaCount[i])
			maxCount = alphaCount[i];

	for (int i = 0; i < 26; i++)
		if (maxCount == alphaCount[i])
			cout << char(i + 'a');

	return 0;
}