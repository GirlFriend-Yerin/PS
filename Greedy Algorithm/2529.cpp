#include <iostream>

using namespace std;

const int MAX = 10;

void toZero(char opers[MAX], const int& n)
{
	int res[MAX] = { };
	int last = n;
	int cur = n -1;
	int max = n;

	while (cur >= 0) {
		int cnt = 0;
		while (cur >= 0 && opers[cur] == '>') {
			cur--;
			cnt++;
		}

		for (int i = cnt; i >= 0; i--)
			res[last--] = max - i;
		max -= cnt + 1;
		cur--;
	}

	while (last >= 0)
		res[last--] = max--;

	for (int i = 0; i <= n; i++)
		cout << res[i];
	cout << '\n';
}

void toNine(char opers[MAX], const int& n)
{
	int res[MAX] = { };
	int last = 0;
	int cur = 0;
	int max = 9;
	
	while (cur < n) {
		int cnt = 0;
		while (cur < n && opers[cur] == '<') {
			cur++;
			cnt++;
		}

		for (int i = cnt; i >= 0; i--)
			res[last++] = max - i;
		max -= cnt + 1;
		cur++;
	}

	while (last <= n)
		res[last++] = max--;

	for (int i = 0; i <= n; i++)
		cout << res[i];
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	char oper[MAX] = {}; for (int i = 0; i < n; i++) cin >> oper[i];

	toNine(oper, n);
	toZero(oper, n);

	return 0;
}