#include <iostream>
#include <vector>

using namespace std;

int getMax(vector<int> inputs) {
	int res = 0;
	for (int i = 0; i < inputs.size(); i++)
		if (res < inputs[i])
			res = inputs[i];
	return res;
}

int getSum (vector<int> inputs, int mxm)
{
	int res = 0;
	for (int i = 0; i < inputs.size(); i++)
		if (inputs[i] <= mxm)
			res += inputs[i];
		else
			res += mxm;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> inputs(n); 	for (int i = 0; i < n; i++) cin >> inputs[i];
	int mxm; cin >> mxm;

	int left = 0, right = getMax(inputs);

	while (left <= right) {
		int mid = (left + right) / 2;

		if (getSum(inputs, mid) > mxm)
			right = mid - 1;
		else
			left = mid + 1;
	}

	cout << right;

	return 0;
}