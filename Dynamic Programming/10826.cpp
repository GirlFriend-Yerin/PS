#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ull;

const int MAX = 10000;

struct BigInt {
	string value;

	BigInt() {};
	BigInt(string s) : value(s) {};

	BigInt operator +(const BigInt& bi) {
		string res = "";

		bool carry = false;
		int len = value.length();
		int bLen = bi.value.length();
		int pos = 0;
		int bpos = 0;

		while (pos < len && bpos < bLen) {
			int vc = value[pos] - '0';
			int vb = bi.value[bpos] - '0';
			int sum = vc + vb + carry;
			carry = sum > 9;
			res.push_back(sum % 10 + '0');

			++pos;
			++bpos;
		}

		while (pos < len) {
			int sum = carry + (value[pos] - '0');
			carry = sum == 10;
			res.push_back(sum % 10 + '0');
			++pos;
		}

		while (bpos < bLen) {
			int sum = carry + (bi.value[bpos] - '0');
			carry = sum == 10;
			res.push_back(sum % 10 + '0');
			++bpos;
		}

		if (carry)
			res.push_back('1');

		return BigInt(res);
	}
};

int main()
{
	int n; cin >> n;

	BigInt dp[MAX + 1] = { BigInt("0"), BigInt("1") };

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 2] + dp[i - 1];
	
	int len = dp[n].value.length();
	for (int i = len - 1; i >= 0; i--)
		cout << dp[n].value[i];

	return 0;
}