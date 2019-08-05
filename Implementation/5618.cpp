#include <iostream>

using namespace std;

int _max(const int& a, const int& b, const int& c) {
	if (b < a && c < a)
		return a;
	else if (a < b && c < b)
		return b;
	return c;
}

int main()
{
	int n; cin >> n;
	int arr[3] = {};

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int bound = _max(arr[0], arr[1], arr[2]);

	for (int i = 1; i < bound + 1; i++) {
		bool res = true;
		for (int j = 0; j < n; j++)
			res &= !(arr[j] % i);

		if (res)
			cout << i << '\n';
	}
	
	return 0;
}