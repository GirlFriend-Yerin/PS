/*
	2019 04 17

	Success
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const short MAX = 100;

vector<int> numbers;

bool checker[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int digitsCount = 0;
	cin >> n;
	numbers.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
		if (!checker[numbers[i]]) {
			checker[numbers[i]] = true;
			digitsCount++;
		}
	}

	sort(numbers.begin(), numbers.end());

	if (digitsCount == 1) {
		cout << 0;
	}
	else if (digitsCount < 4) {
		int diff = numbers[n - 1] - numbers[0];
		int d = diff % 2 ? diff : diff / 2;

		bool isAble = true;

		for (int i = 0; i < n; i++) {
			if (!(numbers[i] == numbers[0] || numbers[i] == (numbers[0] + d) || numbers[i] == numbers[n - 1]))
				isAble = false;
		}

		if (isAble)
			cout << d;
		else
			cout << -1;
	}
	else
		cout << -1;

	return 0;
}