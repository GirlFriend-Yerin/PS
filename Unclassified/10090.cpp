#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
int arr[MAX + 1];
int n;

void add(int x, int val)
{
	for (; x < n + 1; x += x & (-x))
		arr[x] += val;
}

int sum(int x) {
	int r = 0;
	for (; x > 0; x -= x & (-x))
		r += arr[x];
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long res = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		add(input, 1);
		res += sum(n) - sum(input);
	}

	cout << res << endl;

	return 0;
}