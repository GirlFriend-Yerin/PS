#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1024;
long long arr[MAX + 1][MAX + 1];
int n, m;

void add(int x, int y,long long val)
{
	int y1;
	for (; x < n + 1; x += x & (-x))
	{
		y1 = y;
		for (; y1 < n + 1; y1 += y1 & (-y1))
			arr[x][y1] += val;
	}
}

long long sum(int x, int y) {
	long long r = 0;
	int y1;
	for (; x > 0; x -= x & (-x))
	{
		y1 = y;
		for (; y1 > 0; y1 -= y1 & (-y1))
			r += arr[x][y1];
	}
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m ;

	for (int i = 1 ; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			long long input;
			cin >> input;
			add(i, j, input);
		}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		cout << sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x2, y1 - 1) - sum(x1 - 1, y2) << '\n';
	}

	return 0;
}