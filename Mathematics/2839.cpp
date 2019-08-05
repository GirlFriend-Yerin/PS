/* 
	2019 01 05
	2839 - 설탕배달
	MatheMatics

	- 성공 -
*/

#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int min = 1667;

	for (int i = 0; i < n / 5 +1; i++)
	{
		for (int j = 0; j < n / 3 + 1; j++)
		{
			if (n == ((i * 5) + (j * 3)))
			{
				if (min > i + j)
					min = i + j;
			}
		}
	}

	if (min == 1667)
		cout << -1;
	else
		cout << min;

	return 0;
}