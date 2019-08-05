/*
	2019 01 15
	2875 대회 or 인턴
	Greedy Algorithm

	- 성공 -
*/
#include <iostream>

using namespace std;

int main()
{
	int n, m, k;

	cin >> n >> m >> k;
	
	for (;k > 0; k--)
	{
		if (n >= (m * 2))
			n--;
		else if (n < (m * 2))
			m--;
	}

	if ((n / 2) < m)
		m = n / 2;

	cout << m;

	return 0;
}