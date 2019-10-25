#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>& vec, vector<bool>& visited, vector<int>& save, int pos, int start, int cnt, int n, int m) {

	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << save[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		save[pos] = vec[i];
		dfs(vec, visited, save, pos + 1, i + 1, cnt + 1, n, m);
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> vec(n); for (int i = 0; i < n; i++) cin >> vec[i];
	vector<bool> visited(n);
	vector<int> save(m);

	sort(vec.begin(), vec.end());

	dfs(vec, visited, save, 0, 0, 0, n, m);

	return 0;
}