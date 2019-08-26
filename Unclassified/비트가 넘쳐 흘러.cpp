#include <iostream>

using namespace std;

const int MAX = 1000000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	char input[MAX + 1] = {}; cin >> input;

	int bin = 0;
	for (int i = 0; i < n; i++) {
		bin *= 2;
		bin += input[i] == '1';
	}

	int res = 0;
	while (bin) {
		bin = bin - (bin & ((~bin) + 1));
		res++;
	}

	cout << res;

	return 0;
}