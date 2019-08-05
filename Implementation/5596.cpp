#include <iostream>

using namespace std;

int main()
{
	int minSum = 0, manSum = 0;

	for (int i = 0; i < 4; i++) {
		int val; cin >> val;
		minSum += val;
	}

	for (int i = 0; i < 4; i++) {
		int val; cin >> val;
		manSum += val;
	}

	cout << (minSum < manSum ? manSum : minSum);

	return 0;
}