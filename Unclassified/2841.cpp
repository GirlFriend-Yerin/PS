#include <iostream>
#include <stack>

using namespace std;

const int LMAX = 7;
const int PMAX = 300001;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<int> lStack[LMAX];
	bool checker[LMAX][PMAX] = {};

	int n, p; cin >> n >> p;
	int res = 0;

	for (int i = 0; i < n; i++) {
		int line, plat; cin >> line >> plat;

		if (checker[line][plat]) continue;

		while (!lStack[line].empty() && lStack[line].top() > plat) {
			checker[line][lStack[line].top()] = false;
			lStack[line].pop();
			res++;
		}

		lStack[line].push(plat);
		checker[line][plat] = true;
		res++;
	}

	cout << res;

	return 0;
}