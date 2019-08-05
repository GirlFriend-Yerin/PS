#include <iostream>

using namespace std;

const short MAX = 1000;

int main()
{
	int left = 0, right = 0;
	char taebo[MAX + 1];

	cin >> taebo;

	int pos = 0;

	// left
	for (; taebo[pos] != '('; pos++) {
		if (taebo[pos] == '@')
			left++;
	}

	// move
	for (; taebo[pos] != ')'; pos++);

	// right 
	for (; taebo[pos] != '\0'; pos++) {
		if (taebo[pos] == '@')
			right++;
	}

	cout << left << ' ' << right;


	return 0;
}