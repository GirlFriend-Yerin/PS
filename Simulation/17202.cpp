#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char s1[9]; cin >> s1;
	char s2[9]; cin >> s2;

	int table[16] = {};

	for (int i = 0; i < 8; i++) {
		table[i * 2] = s1[i] - '0';
		table[(i * 2)+ 1] = s2[i] - '0';
	}

	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 15 - i; j++)
			table[j] = (table[j] + table[j + 1]) % 10;

	cout << table[0] << table[1];

	return 0;
}