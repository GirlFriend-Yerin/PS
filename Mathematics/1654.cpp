#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMax(vector<int> input) {
	int res = 0;

	for (unsigned int i = 0; i < input.size(); i++)
		if (res < input[i])
			res = input[i];

	return res;
}

long long getMax(long long ll1, long long ll2)
{
	return ll1 < ll2 ? ll2 : ll1;
}

long long getCount(vector<int> input, long long cut) {
	long long res = 0;

	for (unsigned int i = 0; i < input.size(); i++)
		res += (input[i] / cut);

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long n, tar; cin >> n >> tar;
	vector<int> input(n); for (long long i = 0; i < n; i++) cin >> input[i];

	long long left = 1, right = getMax(input);
	long long res = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (tar > getCount(input, mid))
			right = mid - 1;
		else {
			left = mid + 1;
			res = getMax(res, mid);
		}
	}

	cout << res;

	return 0;
}