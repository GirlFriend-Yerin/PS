#include <iostream>

using namespace std;

const short MAX = 9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	char oper[MAX + 1];
	short greater = 0;
	short smaller = 0;
	for (int i = 0; i < n; i++) {
		cin >> oper[i];
		greater += oper[i] == '>';
		smaller += oper[i] == '<';
	}

	// greater
	short gg = 9 - smaller;
	short gs = 9 - n + 1;

	char res[MAX + 1] = {};
	res[0] = gg + '0'; 

	for (int i = 1; i < n + 1; i++)
		res[i] = (oper[i - 1] == '<' ? ++gg : --gs) + '0';

	cout << res << '\n';

	// smaller
	short sg = n - smaller;
	short ss = greater - 1;

	res[0] = sg + '0';
	for (int i = 1; i < n + 1; i++)
		res[i] = (oper[i - 1] == '<' ? ++sg : ss-- ) + '0';

	cout << res << '\n';
	return 0;
}