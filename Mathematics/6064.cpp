#include <iostream>

using namespace std;

int cal_gcb(int a, int b) {

	if (a > b)
	{
		if (a % b)
			return cal_gcb(b, (a % b));
		else
			return b;
	}
	else
	{
		if (b % a)
			return cal_gcb(a, (b % a));
		return a;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;

	cin >> tcc;

	while (tcc--) {
		int n, m, x, y;

		cin >> m >> n >> x >> y;

		int gcb = cal_gcb(m, n);
		int lcm = (m / gcb) * (n / gcb) * gcb;
		int res = -1;

		int leftDiff = x - 1;
		int rightDiff = y - 1;

		for (int i = 0; (m * i) < lcm; i++)
		{
			int mulX = m * i;
			int cur = mulX + leftDiff + 1;
			int right = (cur - 1) % n + 1;

			if (right == y)
				res = cur;
		}

		cout << res << '\n';
	}

	return 0;
}