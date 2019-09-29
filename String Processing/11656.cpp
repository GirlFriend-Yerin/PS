#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str; cin >> str;
	vector<string> prefix;

	int len = str.length();

	for (int i = 0; i < len; i++)
		prefix.push_back(str.substr(i));

	sort(prefix.begin(), prefix.end());

	for (string& item : prefix)
		cout << item << '\n';

	return 0;
}