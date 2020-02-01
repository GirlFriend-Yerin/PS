#include <iostream>
#define MAX 100001

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (register int tc = 1; tc <= tcc; tc++) {
		int len; cin >> len;
		char s1[MAX], s2[MAX];
		cin >> s1 >> s2;
		int res = 0;

		for (int i = 0; i < len; i++)
			res += s1[i] == s2[i];

		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}