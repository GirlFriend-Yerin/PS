/*
	2019 01 09
	2455 ������ ����
	Simulation

	- ���� -
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

		if (i % 2) // Ÿ�� ���
			sum += count;
		else // ������ ���
			sum -= count;

		if (max < sum)
			max = sum;
	}

	cout << max;

	return 0;
}