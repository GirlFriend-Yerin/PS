#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int len;
	bool turn = true;
	string input;

	cin >> len >> input;

	for (int i = 0; len - i > 11; i++) {
		if (turn) {
			int pos = 0;
			for (pos = 0; input[pos] == '-'; pos++);
			for (; pos < len - 11 && (input[pos] == '8' || input[pos] == '-'); pos++);
			input[pos] = '-';
		}
		else
		{
			int pos = 0;
			for (pos = 0; input[pos] == '-'; pos++);
			if (input[pos] == '8')
				input[pos] = '-';
			else
			{
				for (pos = len - 1; input[pos] == '-'; pos--);
				input[pos] = '-';
			}
		}
		turn = !turn;
	}

	int pos = 0;
	for (; input[pos] == '-'; pos++);

	if (input[pos] == '8')
		cout << "YES";
	else
		cout << "NO";

	return 0;
}