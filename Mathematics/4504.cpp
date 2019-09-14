#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	while (true) {
		int val; cin >> val;
		if (!val) break;

		if (val % n)
			printf("%d is NOT a multiple of %d.\n", val, n);
		else
			printf("%d is a multiple of %d.\n", val, n);
			
	}

	return 0;
}