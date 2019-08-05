#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& str1, string& str2) {


	if (str1.length() == str2.length())
		return str1 < str2;
	return str1.length() < str2.length();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<string> inputs(n);

	for (int i = 0; i < n; i++)
		cin >> inputs[i];

	sort(inputs.begin(), inputs.end(), cmp);

	string checker = inputs[0];
	cout << inputs[0] << '\n';

	for (int i = 1; i < n; i++) {
		if (inputs[i] != checker) {
			cout << inputs[i] << '\n';
			checker = inputs[i];
		}
	}
	return 0;
}