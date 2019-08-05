#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int maximum[MAX * 2];
int minimum[MAX * 2];
int n, m;

void set(int x, int v)
{
	int maxPos = x + n - 1;
	int minPos = x + n - 1;
	while (maxPos >= 1)
	{
		if (maximum[maxPos] < v)
			maximum[maxPos] = v;
		else
			break;
		maxPos /= 2;
	}

	while (minPos >= 1)
	{
		if (minimum[minPos] > v)
			minimum[minPos] = v;
		else
			break;
		minPos /= 2;
	}
}

int minGet(int l, int r)
{
	l += n - 1;
	r += n - 1;
	int ret = 2000000000;
	while (l <= r)
	{
		if (l % 2 == 1)
			ret = min(minimum[l], ret);
		if (r % 2 == 0)
			ret = min(minimum[r], ret);

		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}

	return ret;
}

int maxGet(int l, int r)
{
	l += n - 1;
	r += n - 1;
	int ret = 0;
	while (l <= r)
	{
		if (l % 2 == 1)
			ret = max(maximum[l], ret);
		if (r % 2 == 0)
			ret = max(maximum[r], ret);

		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	fill_n(minimum, n * 2, 1000000001);

	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		set(i, val);
	}

	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << minGet(l, r) << ' ' << maxGet(l, r) << '\n';
	}

	return 0;
}