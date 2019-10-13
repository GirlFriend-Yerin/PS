#include <iostream>

using namespace std;

const int MAX = 100;

int main()
{
	int n; cin >> n;
	char input[MAX + 1] = {}; cin >> input;

	for (int i = 0; i < n / 2; i++) {
		char& left = input[i];
		char& right = input[n - 1 - i];
		if (left == right && left == '?')
			left = right = 'a';
		else if (left == '?')
			left = right;
		else if (right == '?')
			right = left;
	}

	if (input[n / 2] == '?')
		input[n / 2] = 'a';

	cout << input;

	return 0;
}