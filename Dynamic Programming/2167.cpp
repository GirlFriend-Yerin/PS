#include <iostream>

using namespace std;

const int MAX = 300;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	int prefix[MAX + 1][MAX + 1] = {};

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> prefix[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			prefix[i][j] += prefix[i][j - 1];

	int query; cin >> query;

	while (query--){
		int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;

		int sum = 0;

		for (int i = sx; i <= ex; i++)
			sum += prefix[i][ey] - prefix[i][sy-1];

		cout << sum << '\n';
	}

	return 0;
}