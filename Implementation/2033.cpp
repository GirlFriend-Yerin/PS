#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;;
	int p = 10;
	while (n > p) {
		n = (n + p / 2) / p * p;
		p *= 10;
	}
	cout << n;

	return 0;
}