#include <iostream>

using namespace std;

const short MAX = 30;

int main()
{
	bool check[MAX] = {};

	for (int i = 0; i < MAX - 2; i++) {
		int val; cin >> val;
		check[val - 1] = true;
	}

	for (int i = 0; i < MAX; i++) {
		if (!check[i])
			cout << i + 1 << '\n';
	}
	return 0;
}