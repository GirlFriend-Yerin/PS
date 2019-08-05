#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	vector<int> a(n), b(n + 1);
	vector<int> c(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		b[val]++;
	}

	for (int i = 0; i < n; i++) {
		int val = n - a[i];
		for (int j = 0; j < n; j++) {
			if (b[(val + j) % n]) {
				c[i] = (a[i] + (val + j))% n;
				b[(val + j) % n]--;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << c[i] << ' ';

	return 0;
}