#include <iostream>

using namespace std;

const int NMAX = 999;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	int sum = 0;
	int sideSum[NMAX] = {}; for (int i = 0; i < n; i++) {
		cin >> sideSum[i];
		sum += sideSum[i];
	}

	sum /= 2;

	for (int i = 0; i < n; i++) {
		int res = sum;
		for (int j = (i + 1) % n; j != i && j != i -1 ; j = (j + 2) % n)
			res -= sideSum[j];
		cout << res << '\n';
	}

	return 0;
}