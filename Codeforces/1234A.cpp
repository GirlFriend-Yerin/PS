#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++){
			int price; cin >> price;
			sum += price;
		}

		cout << ceil(sum*1.0f / n) << '\n';
	}

	return 0;
}