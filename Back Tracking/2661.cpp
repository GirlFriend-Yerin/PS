/*
	2019 01 19
	2661 좋은 수열
	Back Tracking

	- 성공 -
*/
#include <iostream>

using namespace std;

const short MAX = 80;
char number[MAX + 1] = {};
int n;

bool isAble(int pos)
{
	for (int i = 1; i <= (pos + 1) / 2; i++)
	{
		bool duple = false;
		for (int j = 0; j < i; j++)
		{
			if (number[pos - j] != number[pos - i - j]) {
				duple = duple | true;
				break;
			}
		}

		if (!duple)
			return false;
	}
	return true;
}

int solution(int pos)
{
	if (pos == n)
	{
		return 0;
	}
	else
	{
		for (int i = '1'; i < '1' + 3; i++)
		{
			number[pos] = i;
			if (isAble(pos))
			{
				int res = solution(pos + 1);
				if (res != -1)
					return res;
			}
		}
	}

	return -1;
}

int main()
{
	cin >> n;

	solution(0);
	
	cout << number;

	return 0;
}