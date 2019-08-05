#include <iostream>
#include <string.h>

using namespace std;

const short MAX = 10;
const short ALPHA_MAX = 26;
int inputLength;
int alpha[ALPHA_MAX];

int solve(char before, int pos)
{
	int count = 0;

	if (pos == inputLength)
		++count;
	else
	{
		for (int i = 0; i < ALPHA_MAX; i++)
		{
			if (alpha[i] < 1 || 'a' + i == before)
				continue;
			
			--alpha[i];
			count += solve('a' + i, pos + 1);
			++alpha[i];
		}
	}

	return count;
}

int main()
{
	char input[MAX + 1] = { };

	cin >> input;

	inputLength = strlen(input);

	for (int i = 0; i < inputLength; i++)
		alpha[input[i] - 'a']++;

	cout << solve(0, 0);

	return 0;
}