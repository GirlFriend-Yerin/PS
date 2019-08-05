#include <iostream>

using namespace std;

int main()
{
	int first; cin >> first;
	int ratio; cin >> ratio;
	int sum = 0;

	first = first * ratio / 100;
	for (int i = 2; first > 5; i *= 2) {
		sum += first * i;
		first = first * ratio / 100;
	}

	cout << sum;

	return 0;
}