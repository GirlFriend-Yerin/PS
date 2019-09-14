#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		int val; cin >> val;

		if (val == -1) break;

		int sum = 0;
		vector<int> vec;
		for (int i = 1; i < val; i++) {
			if (!(val % i)) {
				vec.push_back(i);
				sum += i;
			}
		}

		if (sum == val) {
			cout << val << " =";
			for (int i = 0; i < vec.size(); i++) {
				cout << ' ' << vec[i] << ' ';
				if (i + 1 != vec.size())
					cout << '+';
			}
		}
		else
			cout << val << " is NOT perfect.";
		cout << '\n';
	}

	return 0;
}