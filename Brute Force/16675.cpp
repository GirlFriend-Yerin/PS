/*
	2019 03 21
	16675 두개의 손
	Brute Force

	- 성공 -
*/

#include <iostream>

using namespace std;

// A - Win ( 1 ) , B - Win ( -1 ) Draw ( 0 )
int win(char a, char b)
{
	if (a == 'R')
	{
		if (b == 'S')
			return 1;
		else if (b == 'R')
			return 0;
		else
			return -1;
	}
	else if (a == 'S')
	{
		if (b == 'S')
			return 0;
		else if (b == 'R')
			return -1;
		else
			return 1;
	}
	
	if (b == 'S')
		return -1;
	else if (b == 'R')
		return 1;

	return 0;
}


int main()
{
	char left[2];
	char right[2];

	cin >> left[0] >> left[1] >> right[0] >> right[1];

	if (left[0] == left[1]) {

		int res1 = win(left[0], right[0]);
		int res2 = win(left[0], right[1]);

		if (res1 == -1 || res2 == -1)
			cout << "TK";
		else if (res1 == 0 || res2 == 0)
			cout << "?";
		else
			cout << "MS";
	}
	else if (right[0] == right[1])
	{
		int res1 = win(left[0], right[0]);
		int res2 = win(left[1], right[1]);

		if (res1 == 1 || res2 == 1)
			cout << "MS";
		else if (res1 == 0 || res2 == 0)
			cout << "?";
		else
			cout << "TK";
	}
	else
		cout << "?";

	return 0;
}