#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int sum = 0;

	for (int i = 0; i < 5; i++) {
		int val; cin >> val;

		val = val < 40 ? 40 : val;

		sum += val;
	}

	cout << sum / 5;

	return 0;
}