#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool isWell(const string& s) {
	stack<char> stk;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			stk.push('(');
		else {
			if (stk.empty()) return false;
			if (stk.top() == '(')
				stk.pop();
		}
	}

	return stk.empty();
}

int balacnePoint(string& s) {
	int open = 0;
	int close = 0;

	for (int i = 0; i < s.length(); i++) {
		open += s[i] == '(';
		close += s[i] == ')';

		if (open == close)
			return i;
	}
	return s.length();
}

string func(string& p) {

	if (p == "") return "";

	int bp = balacnePoint(p);
	string u = p.substr(0, bp + 1);
	string v = p.substr(bp + 1);

	if (isWell(u))
		return u + func(v);

	string res = "(" + func(v) + ")";

	for (int i = 1; i < u.length() - 1; i++)
		res.push_back(u[i] == ')' ? '(' : ')');

	return res;
}

string solution(string p) {
	string answer = "";

	if (isWell(p)) answer = p;
	else 
		answer = func(p);

	return answer;
}

int main()
{
	string s; cin >> s;

	cout << solution(s);

	return 0;
}