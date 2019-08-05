/*
	2019 01 02
	8595 히든넘버
	문자열 처리

	- 성공 -
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	int n;
	char sentense[5000000];

	scanf("%d", &n);

	scanf("%s", sentense);

	int upper = 0;
	bool isDigit = false;
	long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if ('0' <= sentense[i] && sentense[i] <= '9')
		{
			isDigit = true;
			upper = upper * 10 + int(sentense[i] - '0');
		}
		else
		{
			if (isDigit)
			{
				isDigit = false;
				sum += upper;
				upper = 0;
			}
				
		}
	}

	if (isDigit)
		sum += upper;

	cout << sum;

	return 0;
}