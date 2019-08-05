#include <iostream>
#include <vector>

using namespace std;

vector<int> rev_vec;

void eratones(const int& des) {

	const int MAX = 1000;
	bool eratones[MAX + 1] = {};

	for (int i = 2; i < des + 1; i++) {
		if (!eratones[i]) {
			rev_vec.push_back(i);
			for (int j = 2; i * j <= des; j++) {
				if (!eratones[i * j]) {
					eratones[i * j] = true;
					rev_vec.push_back(i * j);
				}
			}
		}
	}
}

int main()
{
	int to, n; cin >> to >> n;

	eratones(to);

	cout << rev_vec[n - 1];

	return 0;
}