#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int main()
{
	int n;
	int res = 0;
	cin >> n;

	vec.resize(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n - 1; i++)
		res += vec[i] - 1;

	cout << res + vec[n - 1];

	return 0;
}