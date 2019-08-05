#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& str1, string& str2) {

	int len1 = str1.length();
	int len2 = str2.length();

	if (len1 != len2)
		return len1 < len2;

	int str1Sum = 0;
	int str2Sum = 0;

	for (int i = 0; i < len1; i++) {
		if ('0' <= str1[i] && str1[i] <= '9')
			str1Sum += str1[i] - '0';


		if ('0' <= str2[i] && str2[i] <= '9')
			str2Sum += str2[i] - '0';
	}

	if (str1Sum != str2Sum)
		return str1Sum < str2Sum;

	return str1 < str2;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<string> inputs(n);

	for (int i = 0; i < n; i++)
		cin >> inputs[i];

	sort(inputs.begin(), inputs.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << inputs[i] << '\n';

	return 0;
}