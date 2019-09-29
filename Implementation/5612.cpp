#include <iostream>

using namespace std;

const int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }
const int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

int main()
{
	int n, car; cin >> n >> car;
	int max = car, min = car;

	for (int i = 0; i < n; i++) {
		int in, out; cin >> in >> out;
		car = car + in - out;
		max = _max(max, car);
		min = _min(min, car);
	}

	cout << (min < 0 ? 0 : max);

	return 0;
}