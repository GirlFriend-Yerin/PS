#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> vec(n); for (int i = 0; i < n; i++) cin >> vec[i];
	int res = 0;

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
	{
		if (vec[i] > res + 1)
			break;
		res += vec[i];
	}

	cout << res + 1;

	return 0;
}