#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const short MAX = 20;

int n;
int synergy[MAX][MAX] = {};
bool tStart[MAX] = {};
int res = 1e9;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

void dfs(int pos, int cnt) {
	if (cnt == (n / 2)) {
		vector<int> team[2];
		int ss = 0, sl = 0;

		for (int i = 0; i < n; i++) {
			if (tStart[i]) team[0].push_back(i);
			else team[1].push_back(i);
		}

		for (int i = 0; i < n / 2; i++)
			for (int j = i + 1; j < n / 2; j++) {
				ss += synergy[team[0][i]][team[0][j]] + synergy[team[0][j]][team[0][i]];
				sl += synergy[team[1][i]][team[1][j]] + synergy[team[1][j]][team[1][i]];
			}

		res = _min(res, abs(ss - sl));
	}
	else {
		for (int i = pos + 1; i < n; i++) {
			if (tStart[i]) continue;

			tStart[i] = true;
			dfs(i, cnt + 1);
			tStart[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> synergy[i][j];

	dfs(0, 0);

	cout << res;

	return 0;
}