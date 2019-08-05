#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calAtom(char c) {
	return c == 'H' ? 1 : (c == 'C' ? 12 : 16);
}

int calValue(string& s, int pos, bool trig) {

	int res = 0;
	stack<int> value;

	char endFlag = trig ? ')' : '\0';

	for (int i = pos; s[i] != endFlag; i++) {
		char token = s[i];

		if ('0' <= token && token <= '9')
		{
			int atomV = value.top(); value.pop();
			value.push(atomV * (token - '0'));
		}
		else if (token == '(') {
			value.push(calValue(s, i + 1, true));
			while (s[++i] != ')');
		}
		else if (token == ')')
			continue;
		else {
			value.push(calAtom(token));
		}

	}

	while (!value.empty()) {
		res += value.top();
		value.pop();
	}

	return res;
}

int main()
{
	string input; cin >> input;

	cout << calValue(input, 0, false);

	return 0;
}