/*
	2019 01 13
	1003 피보나치 함수
	Dynamic Programming

	- 성공 -
*/
#include <iostream>

using namespace std;

const int MAX = 40;

int main()
{
	int tcc;
	int zeroTable[MAX + 1] = { 1, };
	int oneTable[MAX + 1] = { 0 , 1 };

	cin >> tcc;

	for (int i = 2; i < MAX + 1; i++)
	{
		zeroTable[i] = zeroTable[i - 1] + zeroTable[i - 2];
		oneTable[i] = oneTable[i - 1] + oneTable[i - 2];
	}

	for (int i = 0; i < tcc; i++)
	{
		int n;
		cin >> n;

		cout << zeroTable[n] << ' ' << oneTable[n] << '\n';
	}

	return 0;
}
