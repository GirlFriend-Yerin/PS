/*
	2019 02 01
	14501 Επ»η
	Brute force

	- ΌΊ°ψ -
*/
#include <iostream>
using namespace std;

const int MAX = 15;

int n;
int max_earn;
int time[MAX];
int pay[MAX];
bool check[MAX];

void solution(int pos, int sum)
{
	if (pos < n)
	{
		int next = pos + time[pos];
		if (next <= n)
			solution(next, sum + pay[pos]);
		else
			solution(next, sum);
		solution(pos + 1, sum);
	}
	else
	{
		if (max_earn < sum)
			max_earn = sum;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> time[i] >> pay[i];

	for (int i = 0; i < n; i++)
		solution(i, 0);

	cout << max_earn;
	return 0;
}