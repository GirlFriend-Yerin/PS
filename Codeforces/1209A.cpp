#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool allVisited(vector<bool>& check) {
	for (int i = 0; i < check.size(); i++)
		if (!check[i])
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n; cin >> n;
	vector<int> vec(n); for (int i = 0; i < n; i++) cin >> vec[i];
	vector<bool> check(n, false);
	sort(vec.begin(), vec.end());

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (check[i]) continue;
			
		for (int j = 0; j < n; j++) {
			if (check[j]) continue;

			check[j] = !(vec[j] % vec[i]);
		}

		res++;
		if (allVisited(check))
			break;
	}


	cout << res;

	return 0;
}