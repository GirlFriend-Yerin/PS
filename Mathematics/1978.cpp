/*
	2019 01 20
	1978 소수찾기
	MatheMatics

	- 성공 -
*/

#include <iostream>

using namespace std;

const short MAX = 1000;

void eratos(bool arr[MAX + 1]) {

	arr[0] = arr[1] = true;
	for (int i = 2; i < MAX / 2 + 1; i++)
	{
		if (!arr[i])
		{
			for (int j = i * 2; j < MAX; j += i)
				arr[j] = true;
		}
	}
}

int main()
{
	int n;
	bool prime[MAX + 1] = {};
	int count = 0;
	
	eratos(prime);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int k;

		cin >> k;

		if (!prime[k])
			count++;
	}

	cout << count;

	return 0;
}