#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>& vec, vector<int>& save, int pos, int cnt, int n, int m) {

	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << save[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		save[pos] = vec[i];
		dfs(vec, save, pos + 1, cnt + 1, n, m);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> vec(n); for (int i = 0; i < n; i++) cin >> vec[i];
	vector<int> save(m);

	sort(vec.begin(), vec.end());

	dfs(vec, save, 0, 0, n, m);

	return 0;
}