#include <iostream>

using namespace std;

const int MAX = 100;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	int sul[MAX] = {}; for (int i = 0; i < m; i++) cin >> sul[i];
	int score[MAX] = {};

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int val; cin >> val;
			score[j] += sul[i] == val;
			score[sul[i] - 1] += sul[i] != val;
		}
	}

	for (int i = 0; i < n; i++)
		cout << score[i] << '\n';

	return 0;
}