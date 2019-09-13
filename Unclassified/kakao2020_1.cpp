#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }

int convert(const string& str, int n) {

	string flag = str.substr(0, n);
	string res = "";

	int cnt = 0;
	int i = 0;
	for (; i * n < str.length(); i++) {
		string cur = str.substr(i * n, n);
		if (cur == flag)
			cnt++;
		else {
			if (cnt > 1)
				res += to_string(cnt);
			res += flag;
			flag = cur;
			cnt = 1;
		}
	}
	if (cnt > 1)
		res += to_string(cnt);
	res += flag;

	//cout << n << " : " << res << endl;

	return res.length();
}

int solution(string s) {
	int answer = s.length() > 1 ? 1005 : 1;

	for (int i = 1; i < s.length(); i++)
		answer = _min(answer, convert(s, i));

	return answer;
}
int main()
{
	string s; cin >> s;

	cout << solution(s);

	return 0;
}