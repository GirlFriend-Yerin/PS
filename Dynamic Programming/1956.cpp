#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e7;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int v, e; cin >> v >> e;
	vector<vector<int>> floyd(v, vector<int>(v, INF));

	for (int i = 0; i < e; i++) {
		int t, d, w; cin >> t >> d >> w;

		floyd[t - 1][d - 1] = w;
	}

	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			for (int k = 0; k < v; k++)
				floyd[j][k] = _min(floyd[j][k], floyd[j][i] + floyd[i][k]);

	int res = INF;

	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			res = _min(res, floyd[i][j] + floyd[j][i]);

	cout << (res >= INF ? -1 : res);


	return 0;
}