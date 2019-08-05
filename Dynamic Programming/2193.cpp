/*
	2019 01 13
	2193 이친수
	Dynamic Programming

	- 성공 -
*/

#include <iostream>

using namespace std;

const int MAX = 90;

int main()
{
	int tc;
	long long int dpTable[MAX + 1] = { 1, 1, };

	cin >> tc;

	for (int i = 2; i < MAX + 1; i++)
		dpTable[i] = dpTable[i - 1] + dpTable[i - 2];

	cout << dpTable[tc-1]<< endl;

	return 0;
}