/*
	2019 01 27
	1356 유진수
	MatheMatics

	- 성공 -
*/
#include <iostream>

using namespace std;

const int MAX = 10;
char input[MAX + 1];
int len;

bool yuZin(int cut)
{
	int left = input[0] - '0';
	int right = input[cut] - '0';

	for (int i = 1; i < cut; i++)
		left *= input[i] - '0';
	for (int i = cut + 1; i < len; i++)
		right *= input[i] - '0';

	return left == right;
}

int main()
{
	cin >> input;
	bool check = false;

	while (input[len] != '\0')
		len++;

	for (int i = 1; i < len; i++)
		check |= yuZin(i);

	if (check)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}