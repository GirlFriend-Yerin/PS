/*
	2019 02 10
	1120 문자열
	Simulation

	- 성공 -
*/
#include <iostream>

using namespace std;

const short MAX = 50;

int mLen(char words[MAX + 1])
{
	int len = 0;

	for (; words[len] != '\0'; len++);

	return len;
}

int main()
{
	int leftLen, rightLen, res;
	int diff;
	char left[MAX + 1], right[MAX + 1];

	cin >> left >> right;
	
	leftLen = mLen(left);
	res = rightLen = mLen(right);
	diff = rightLen - leftLen;

	for (int i = 0; i <= diff; i++)
	{
		int cal = 0;
		for (int j = 0; j < leftLen; j++)
			if (left[j] != right[j + i])
				cal++;

		if (res > cal)
			res = cal;
	}

	cout << res;

	return 0;
}