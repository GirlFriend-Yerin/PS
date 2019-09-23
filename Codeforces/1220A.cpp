#include <iostream>
#include <string>

using namespace std;

int convert(char ch) {
	if (ch == 'z')
		return 4;
	else if (ch == 'e')
		return 3;
	else if (ch == 'r')
		return 2;
	else if (ch == 'o')
		return 1;
	return 0;
}

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	string str; cin >> str;
	int cnt[5] = {};

	for (int i = 0; i < n; i++)
		cnt[convert(str[i])]++;

	int makeOne = _min(_min(cnt[0], cnt[1]), cnt[3]);
	cnt[0] -= makeOne;
	cnt[1] -= makeOne;
	cnt[3] -= makeOne;
	int makeZero = _min(_min(cnt[4], cnt[3]), _min(cnt[2], cnt[1]));

	for (int i = 0; i < makeOne; i++)
		cout << 1 << ' ';
	for (int i = 0; i < makeZero; i++)
		cout << 0 << ' ';

	return 0;
}