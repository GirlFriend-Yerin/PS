#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, t; cin >> n >> t;
	vector<int> vec(n + 1);

	for (int i = 1; i <= n; i++) {
		int val; cin >> val;
		vec[i] = vec[i - 1] + val;
	}

	int res = 0;
	for (int i = 1; i <= n; i++) 
		res += vec[i] <= t;

	cout << res;

	return 0;
}