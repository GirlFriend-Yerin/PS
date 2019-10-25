#include <iostream>
#include <vector>

using namespace std;

const short MAX = 8;

int value[MAX] = {};
bool visited[MAX] = {};

void dfs(int pos, int n, int m) {

	if (pos == m) {
		for (int i = 0; i < m; i++)
			cout << value[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		value[pos] = i + 1;
		dfs(pos + 1, n, m);
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	dfs(0, n, m);

	return 0;
}