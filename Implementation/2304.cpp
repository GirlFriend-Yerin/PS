#include <iostream>

using namespace std;

const int MAX = 1000;

int height[MAX] = {};

int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }
int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		int l, h; cin >> l >> h;
		height[l - 1] = h;
	}

	int rightMax = 0;
	int right[MAX] = {};
	for (int i = MAX - 1; i >= 0; --i)
		right[i] = rightMax = _max(rightMax, height[i]);

	int res = 0;
	int leftMax = 0;
	for (int i = 0; i < MAX; i++)
	{	
		leftMax = _max(leftMax, height[i]);
		res += _min(leftMax, right[i]);
	}

	cout << res;

	return 0;
}