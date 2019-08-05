#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> toe;

int main()
{
	long long n, x, y;

	cin >> n >> x >> y;

	toe.resize(n);

	toe[0] = "0";

	for (int i = 1; i < n; i++) {
		toe[i] = toe[i - 1];
		int len = toe[i].length();
		for (int j = 0; j < len; j++) {
			toe[i] += toe[i - 1][j] == '0' ? '1' : '0';
		}
	}

	cout << toe[n - 1].substr(x - 1, y - x + 1);

	return 0;
}