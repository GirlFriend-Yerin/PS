#include <iostream>
#include <cstring>

using namespace std; 

char input[11] = {};

bool isUnder()
{
	if (input[0] < '2')
	{
		for (int i = 1; input[i] != '\0'; i++)
			if (input[i] > '2')
				break;
			else if (input[i] == '0')
				return true;
	}

	return false;
}

int main()
{
	cin >> input;

	int len = strlen(input);

	cout << len - isUnder();

	return 0;
}