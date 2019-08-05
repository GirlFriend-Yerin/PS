/*
	2019 01 13
	1149 RGB거리
	Dynamic Programming

	- 성공 -
*/
#include <iostream>

using namespace std;

const int MAX = 1000;

int tcc;
int RGB_val[MAX + 1][3];
int dpTable[MAX + 1][3];

int myMin(int val1, int val2)
{
	return val1 > val2 ? val2 : val1;
}

int main()
{
	cin >> tcc;

	for (int i = 0; i < tcc; i++)
		for (int j = 0; j < 3; j++)
			cin >> RGB_val[i][j];

	for (int i = 0; i < 3; i++)
		dpTable[0][i] = RGB_val[0][i];

	for (int i = 1; i < tcc; i++)
	{
		for (int j = 0; j < 3; j++)
			dpTable[i][j] = RGB_val[i][j] + myMin(dpTable[i - 1][(j + 1) % 3], dpTable[i - 1][(j + 2) % 3]);

	}

	int minVal = dpTable[tcc-1][0];
	for (int i = 1; i < 3; i++)
		if (minVal > dpTable[tcc - 1][i])
			minVal = dpTable[tcc - 1][i];

	cout << minVal;
	return 0;
}