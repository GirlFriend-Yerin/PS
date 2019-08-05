#include <iostream>

using namespace std;

const int MAX = 10000;

int dp[MAX + 1] = {};

void init()
{
	for (int i = 0; i < MAX + 1; i++)
	{
		int cnt = 0;
		int temp_i = 0;
		for (int jmp = 1; temp_i < i; jmp++, cnt++) {
			temp_i += jmp;
			if (temp_i + jmp + 1 > i)
				jmp = 0;
		}
		dp[i] = cnt;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		int res = 0;
		long long to, des; cin >> to >> des;

		if (des < MAX + 1) {
			res = dp[to];
			for (long long i = to + 1; i <= des; i++)
				if (res < dp[i])
					res = dp[i];
		}

		cout << "Case #" << tc << '\n' << res << '\n';
	}

	return 0;
}