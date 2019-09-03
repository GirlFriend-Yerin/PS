#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool cmp(string& str1, string& str2)
{
	int str1Len = str1.length();
	int str2Len = str2.length();

	return str1Len != str2Len ? (str1Len < str2Len) : str1 < str2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		int n; cin >> n;
		set<string, cmp> vec;

		for (int i = 0; i < n; i++) {
			string val; cin >> val;
			vec.insert(val);
		}

		sort(vec.begin(), vec.end(), cmp);

		cout << '#' << tc << '\n';
		for (auto& str : vec) {
			cout << str << '\n';
		}
	}

	return 0;
}