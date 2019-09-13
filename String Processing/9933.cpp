#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSame(const string& str1, const string& str2) {

	int str1Len = str1.length();
	int str2Len = str2.length();

	if (str1Len != str2Len)
		return false;

	for (int i = 0; i < str1Len / 2; i++)
		if (str1[i] != str2[str2Len - i - 1])
			return false;

	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<string> vec(n); for (int i = 0; i < n; i++) cin >> vec[i];

	bool trigger = false;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (isSame(vec[i], vec[j])) {
				cout << vec[i].length() << ' ' << vec[i][vec[i].length() / 2];
				trigger = true;
				break;
			}
		}
		if (trigger)
			break;
	}

	return 0;
}