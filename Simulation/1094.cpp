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
	int target;
	int count = 0;

	cin >> target;

	for (;target != 0; target >>= 1 )
		if (target % 2)
			count++;

	cout << count;

	return 0;
}