#include <iostream>

using namespace std;

int main()
{
	int n, x, y; cin >> n >> x >> y;

	while (n--) {
		int val; cin >> val;

		if (val * val <= (x * x + y * y))
			cout << "DA\n";
		else
			cout << "NE\n";
	}

	return 0;
}