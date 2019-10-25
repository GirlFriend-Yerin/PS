#include <iostream>

using namespace std;

const short MAX = 8;

int arr[MAX] = {};

void dfs(int pos, int start, int cnt, int n, int m) {

	if (cnt == m) {
		for (int i = 0; i < cnt; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i <= n - m + cnt; i++) {
		arr[pos] = i + 1;
		dfs(pos + 1, i + 1, cnt + 1, n, m);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	dfs(0, 0, 0, n, m);

	return 0;
}
