/*
	2019 01 20
	1075 나누기
	MatheMatics

	- 성공 -
*/

#include <iostream>

using namespace std;

int main()
{
	int input, div;

	cin >> input >> div;

	input = (input / 100) * 100;

	for (int i = 0; i < 100; i++)
	{
		if ((input + i) % div == 0)
		{
			printf("%02d", i);
			break;
		}
	}

	return 0;
}