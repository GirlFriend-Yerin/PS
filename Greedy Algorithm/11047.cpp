/*
	2019 01 15
	11047 동전 0
	Greedy Algorithm

	- 성공 -
*/
#include <iostream>

using namespace std;

int main()
{
	int coinValue[10];
	int coinCount, targetValue;
	int totalCount = 0;

	cin >> coinCount >> targetValue;
	for (int i = 0; i < coinCount; i++)
		cin >> coinValue[i];

	for (int pos = coinCount - 1; pos >= 0; pos--)
	{
		if (coinValue[pos] > targetValue)
			continue;

		int count = targetValue / coinValue[pos];
		targetValue -= coinValue[pos] * count;
		totalCount += count;
	}

	cout << totalCount;
}