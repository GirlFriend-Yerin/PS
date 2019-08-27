#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int val[] = { 4, 3 };

int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

int maxLen, res; 
int n;

void cmp(string str) {
	int cvt = stoi(str);
	if (cvt <= n)
		res = _max(cvt, res);
}

void bruteforce(string str, const int len) {

	if (len == maxLen) return;

	cmp(str + '4');
	bruteforce(str + '4', len + 1);
	cmp(str + '7');
	bruteforce(str + '7', len + 1);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	maxLen = log10(n) + 1;

	string str;

	bruteforce("", 0);
	
	cout << res;

	return 0;
}