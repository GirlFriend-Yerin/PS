#include <iostream>
#include <stack>
#include <string>

using namespace std;

int solution(string dartResult) {
	int answer = 0;

	stack<int> stk;
	string buffer;
	for (auto ch : dartResult) {
		if ('0' <= ch && ch <= '9')
			buffer += ch;
		else {
			if (!buffer.empty()) {
				stk.push(stoi(buffer));
				buffer = "";
			}

			if (ch == 'D') {
				int val = stk.top(); stk.pop();
				stk.push(val * val);
			}
			else if (ch == 'T') {
				int val = stk.top(); stk.pop();
				stk.push(val * val * val);
			}
			else if (ch == '*') {
				int cur = stk.top(); stk.pop();
				if (stk.size() > 0) {
					int pre = stk.top(); stk.pop();
					stk.push(pre * 2);
				}
				stk.push(cur * 2);
			}
			else if (ch == '#') {
				int cur = stk.top() * -1; stk.pop();
				stk.push(cur);
			}
		}
	}

	if (!buffer.empty())
		stk.push(stoi(buffer));

	while (!stk.empty()) {
		answer += stk.top();
		stk.pop();
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str; cin >> str;

	cout << solution(str);

	return 0;
}