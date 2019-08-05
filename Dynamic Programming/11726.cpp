/*
	2019 01 13
	11726 2xn 타일링
	Dynamic Programming

	- 성공 -
*/
#include <iostream>

using namespace std;

const int MAX = 1000;

int main()
{
	int dpTable[MAX + 1];
	int n;

	cin >> n;

	dpTable[0] = 1;
	dpTable[1] = 2;
	
	for (int i = 2; i < MAX; i++)
		dpTable[i] = (dpTable[i - 1] + dpTable[i - 2]) % 10007;
		
	cout << dpTable[n - 1];
	return 0;
}