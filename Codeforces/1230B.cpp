#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	string str; cin >> str;

	if (k) {
		if (n > 1) {
			int cnt = str[0] != '1';

			str[0] = '1';
			int pos = 1;
			while (pos < n && cnt < k) {
				cnt += str[pos] != '0';
				if (str[pos] != '0')
					str[pos] = '0';
				pos++;
			}
		}
		else {
				str[0] = '0';
		}
	}

	cout << str;

	return 0;
}