#include <iostream>
#include <string>

using namespace std;

const int MAX = 100000;

int isAbleCheck(string& s)
{
	int len = s.length();

	string temp;

	for (int i = 0; i < len; i++) {
		if (s[i] != 'a')
			temp += s[i];
	}

	int tempLen = temp.length();

	if (tempLen % 2)
		return -1;

	for (int i = 0; i < tempLen / 2; i++) {
		if (temp[i] != temp[(tempLen / 2) + i])
			return -1;
	}

	return tempLen / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;

	cin >> input;

	int cnt;
	if ((cnt = isAbleCheck(input)) != -1)
	{
		string sQ = input.substr(input.length() - cnt);

		bool checker = true;
		int sQLen = sQ.length();
		for (int i = 0; i < sQLen; i++) {
			if (sQ[i] == 'a') {
				checker = false;
				break;
			}
		}

		if (checker)
			cout << input.substr(0, input.length() - sQLen);
		else
			cout << ":(";
	}
	else
		cout << ":(";

	return 0;
}