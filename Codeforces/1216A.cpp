#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;

	int res = 0;
	for (int i = 0; i < n / 2; i++) {
		if (s[i * 2] == s[i * 2 + 1]) {
			if (s[i * 2] == 'a')
				s[i * 2 + 1] = 'b';
			else
				s[i * 2] = 'a';
			res++;
		}
	}

	cout << res << '\n' << s;

	return 0;
}