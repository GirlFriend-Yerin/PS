#include <iostream>

using namespace std;

const short MAX = 100;

int main()
{
	char input[MAX + 1] = {};
	char res[MAX + 1] = {};

	cin >> input;

	bool trigger = true;
	int pos = 0;

	for (int i = 0; input[i] != '\0'; i++) {
		if (trigger)
		{
			if ('A' <= input[i] && input[i] <= 'Z')
				res[pos++] = input[i];
			trigger = false;
		}
		else
		{
			if (input[i] == '-')
				trigger = true;
		}
	}

	cout << res;

	return 0;
}