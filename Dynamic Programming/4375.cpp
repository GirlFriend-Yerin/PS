#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int val;

	while (cin >> val) {

		if (val == 1) {
			cout << '1' << '\n';
			continue;
		}

		int flag = 1;
		int mod = 1;
		while (mod != 0) {
			mod = ((mod * 10) % val + 1) % val;
			flag++;
		}

		cout << flag << '\n';
	}

	return 0;
}