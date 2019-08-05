#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
long long arr[MAX + 1];
int n, m, k;

void add(int x, long long val)
{
	for (; x < n + 1; x += x & (-x))
		arr[x] += val;
}

long long sum(int x) {
	long long r = 0;
	for (; x > 0; x -= x & (-x))
		r += arr[x];
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		long long input;
		cin >> input;
		add(i, input);
	}

	for (int i = 0; i < m + k; i++)
	{
		int order, pos;
		long long val;

		cin >> order >> pos >> val;

		if (order == 1)
		{
			long long diff = sum(pos) - sum(pos - 1);
			add(pos, -diff);
			add(pos, val);
		}
		else
			cout << sum(val) - sum(pos - 1) << '\n';
	}

	return 0;
}