#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> res(n);

	for (int i = 0; i < n; i++) {
		int big; cin >> big;
		for (int j = 0; j < n; j++) {
			if (!big && !res[j]) {
				res[j] = i + 1;
				break;
			}
			else if (!res[j]) big--;
		}
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';

	return 0;
}