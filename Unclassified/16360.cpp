#include <iostream>
#include <cstring>

using namespace std;

const short MAX = 33;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;
	cin >> tcc;

	while (tcc--)
	{
		char input[MAX + 1] = {}; cin >> input;
		int len = strlen(input);

		if (input[len - 1] == 'a')
			input[len] = 's';
		else if (input[len - 1] == 'i' || input[len - 1] == 'y')
		{
			input[len - 1] = 'i'; input[len] = 'o'; input[len + 1] = 's';
		}
		else if (input[len - 1] == 'l')
		{
			input[len] = 'e'; input[len + 1] = 's';
		}
		else if (input[len - 1] == 'n')
		{
			input[len - 1] = 'a'; input[len] = 'n'; input[len + 1] = 'e'; input[len + 2] = 's';
		}
		else if (input[len - 2] == 'n' && input[len - 1] == 'e')
		{
			input[len - 2] = 'a'; input[len - 1] = 'n'; input[len] = 'e'; input[len + 1] = 's';
		}
		else if (input[len - 1] == 'o')
			input[len] = 's';
		else if (input[len - 1] == 'r')
		{
			input[len] = 'e'; input[len + 1] = 's';
		}
		else if (input[len - 1] == 't')
		{
			input[len] = 'a'; input[len + 1] = 's';
		}
		else if (input[len - 1] == 'u')
			input[len] = 's';
		else if (input[len - 1] == 'v')
		{
			input[len] = 'e'; input[len + 1] = 's';
		}
		else if (input[len - 1] == 'w')
		{
			input[len] = 'a'; input[len + 1] = 's';
		}
		else
		{
			input[len] = 'u'; input[len + 1] = 's';
		}

		cout << input << '\n';
	}

	return 0;
}