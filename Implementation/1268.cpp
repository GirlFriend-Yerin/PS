#include <iostream>

using namespace std;

const int MAX = 1000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int cls[MAX][5] = {};
	int cnt[MAX] = {};

	for (int i = 0; i < n; i++) for (int j = 0; j < 5; j++) cin >> cls[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			bool isSame = false;
			for (int k = 0; k < 5; k++) {
				if (cls[i][k] == cls[j][k]) {
					isSame = true;
					break;
				}
			}
			cnt[i] += isSame;
		}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[res] < cnt[i])
			res = i;
	}

	cout << res + 1;


	return 0;
}