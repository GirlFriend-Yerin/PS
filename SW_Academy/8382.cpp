#include <iostream>
#include <cmath>

using namespace std;

short _max(const short a, const short b) { return a ^ ((a ^ b) & -(a < b)); }
short _min(const short a, const short b) { return b ^ ((a ^ b) & -(a < b)); }

int board[201][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tcc; cin >> tcc;
	for (int tc = 1; tc <= tcc; tc++) {
		short s_x, s_y, e_x, e_y; cin >> s_x >> s_y >> e_x >> e_y;

		short disX = abs(s_x - e_x);
		short disY = abs(s_y - e_y);

		short maxDis = _max(disX, disY);
		short minDis = _min(disX, disY);
		int res = (maxDis / 2) * 4 + (maxDis % 2);

		cout << '#' << tc << ' ' << res + (maxDis % 2 ? (minDis%2) : -(minDis % 2)) << '\n';
	}

	return 0;
}