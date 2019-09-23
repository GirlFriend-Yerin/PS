#include <iostream>

using namespace std;

const int VMAX = 100;
const int NMAX = 200;
const int RMAX = 3;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int val[NMAX][RMAX] = {};

	for (int i = 0; i < n; i++)
		for (int j = 0; j < RMAX; j++)
			cin >> val[i][j];

	int score[NMAX] = {};

	for (int i = 0; i < RMAX; i++) {
		int checker[VMAX + 1] = {};

		for (int j = 0; j < n; j++)
			checker[val[j][i]]++;

		for (int j = 0; j < n; j++)
			score[j] += (checker[val[j][i]] == 1) * val[j][i];
	}

	for (int i = 0; i < n; i++)
		cout << score[i] << '\n';

	return 0;
}