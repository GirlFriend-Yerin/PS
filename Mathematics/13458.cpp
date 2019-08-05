/*
	2019 03 08
	13456 시험 감독
	MatheMatics

	- 성공 -
*/
#include <iostream>

using namespace std;

const int MAX = 1000000;

int applicant[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc, admin, submin;
	long long res = 0;

	cin >> tcc;

	for (int i = 0; i < tcc; i++)
		cin >> applicant[i];

	cin >> admin >> submin;

	for (int i = 0; i < tcc; i++)
	{
		applicant[i] -= admin;
		res++;
		
		if (applicant[i] <= 0)
			continue;

		res += applicant[i] / submin;
		res = res + (applicant[i] % submin ? 1 : 0);
	}

	cout << res;

	return 0;
}