#include <iostream>

using namespace std;

const short MAX = 7;

int arr[MAX] = {};

void permutation(int pos, int start ,int n, int m) {

	if (pos == m) {

		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = start; i < n; i++) {
		arr[pos] = i + 1;
		permutation(pos + 1, i, n, m);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	permutation(0, 0, n, m);

	return 0;
}