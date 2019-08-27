#include <iostream>
#include <cmath>

using namespace std;

const int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }
const int _min(const int a, const int b) { return b ^ ((a^b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int res = -1;
		int x1, y1, r1, x2, y2, r2;

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		long long dist = (x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2);

		if ((r2 - r1)*(r2 -r1) < dist && dist < (r1 + r2)*(r1+r2))
			res = 2;
		else if (dist == (r1 + r2) * (r1 + r2))
			res = 1;
		else if (dist == (r2 - r1) * (r2 - r1)) {
			if (dist)
				res = 1;
			else
				res = -1;
		}
		else if (dist < (r2 - r1) * (r2 - r1) || dist > (r1 + r2) * (r1 + r2))
			res = 0;

		cout << res << '\n';
	}



	return 0;
}