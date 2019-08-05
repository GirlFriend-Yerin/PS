#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string converting(string& str) {
	string res;
	if (str.length() == 1)
		res = str;
	else
	{
		int zeroCounting = 0;

		while (str[zeroCounting] == '0')
			zeroCounting++;

		if (zeroCounting == str.length())
			res = "0";
		else
		{
			for (int i = 0; i < str.length() - zeroCounting; i++)
				res += str[i + zeroCounting];
		}
	}
	
	return res;
}

bool cmp(string& str1, string& str2) {

	int len1 = str1.length();
	int len2 = str2.length();

	if (len1 != len2)
		return len1 < len2;

	return str1 < str2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<string> inputs(n);
	vector<string> values;

	for (int i = 0; i < n; i++)
		cin >> inputs[i];

	for (int i = 0; i < n; i++) {
		string temp;
		int len = inputs[i].length();
		for (int j = 0; j < len; j++) {
			if ('0' <= inputs[i][j] && inputs[i][j] <= '9')
				temp += inputs[i][j];
			else
			{
				if (!temp.empty()) {
					values.push_back(converting(temp));
					temp.clear();
				}
			}
		}
		if (!temp.empty()) {
			values.push_back(converting(temp));
		}
	}

	sort(values.begin(), values.end(), cmp);

	for (int i = 0; i < values.size(); i++)
		cout << values[i] << '\n';

	return 0;
}