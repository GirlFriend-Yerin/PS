/*
	2018-12-28
	1065 한수
	Brute force

	- 성공 -
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	int count = 0;

	cin >> n;

	if (n == 1000) // 1000 is not arithmetic sequence
		n = 999;

	if (n < 100) // under 100 is arithmetic sequence
		count = n;
	else
	{
		count = 99;

		for (int i = 100; i < n + 1; i++)
		{
			int number = i;
			int digit[3];
			int j = 0;
			while (number)
			{
				digit[j++] = number % 10;
				number /= 10;
			}
		
			if (digit[0] - digit[1] == digit[1] - digit[2])
				count++;
		}
	}

	cout << count;

	return 0;
}