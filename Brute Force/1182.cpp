#include <iostream>

using namespace std;

const int MAX = 20;

int values[MAX];
int res = 0;
int n, tar;

void solve(int pos, int chk ,int sum) {

	if (pos == n) {
		if (chk && sum == tar) {
			res++;
		}
	}
	else
	{
		solve(pos + 1, chk + 1,sum + values[pos]);
		solve(pos + 1, chk, sum);
	}
}

int main()
{
	cin >> n >> tar;

	for (int i = 0; i < n; i++)
		cin >> values[i];

	solve(0, 0,0);

	cout << res;

	return 0;
}