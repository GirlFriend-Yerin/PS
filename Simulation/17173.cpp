#include <iostream>

using namespace std;

const int MAX = 1000;

bool checkBoard[MAX + 1];

int main()
{
	int n, m; cin >> n >> m;

	int start = -1;

	while (m--) {
		int k; cin >> k;

		if (start == -1)
			start = k;

		for (int i = 1; i * k <= 1000; i++)
			checkBoard[i*k] = true;
	}

	int sum = 0;
	for (int i = start; i <= n; i++)
		if (checkBoard[i])
			sum += i;

	cout << sum;

	return 0;
}