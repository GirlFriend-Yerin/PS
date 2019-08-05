/*
	2019 01 09
	2455 지능형 기차
	Simulation

	- 성공 -
*/
#include <iostream>

using namespace std;

int main()
{
	int max = 0;
	int sum = 0;

	for (int i = 0; i < 8; i++)
	{
		int count;

		cin >> count;

		if (i % 2) // 타는 경우
			sum += count;
		else // 내리는 경우
			sum -= count;

		if (max < sum)
			max = sum;
	}

	cout << max;

	return 0;
}