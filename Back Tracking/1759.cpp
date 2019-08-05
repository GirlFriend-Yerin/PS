/*
	2019 01 10
	1759 암호 만들기
	Back Tracking

	- 성공 -
*/

#include <iostream>

using namespace std;

int l, c;

bool alpha[26];
char password[16];

void func(int pos, int last, int conson, int vow)
{
	if (pos == l)
	{
		if (conson > 1 && vow > 0)
			cout << password << '\n';
	}
	else
	{
		for (int i = last; i < 26; i++)
		{
			if (alpha[i])
			{
				bool vowol = false;
				if (i == 0 || i == ('e' - 'a') || i == ('i' - 'a') || i == ('o' - 'a') || i == ('u' - 'a'))
					vowol = true;

				password[pos] = i + 'a';
				alpha[i] = false;
				func(pos + 1, i, conson + !vowol, vow + vowol);
				password[pos] = 0;
				alpha[i] = true;
			}
		}
	}
}

int main()
{
	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		char al;
		cin >> al;
		alpha[al - 'a'] = true;
	}

	func(0, 0, 0, 0);

	return 0;
}