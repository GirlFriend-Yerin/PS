#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 1000;

int find(vector<string>& vec, string& value)
{
	int len = vec.size();

	for (int i = 0; i < len; i++)
		if (vec[i] == value)
			return i;
	return -1;
}

int _max(const int a, const int b) { return a ^ ((a < b) & -(a < b)); }

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> values;
	int count[MAX] = {};

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string value; cin >> value;
		int idx = find(values, value);
		if (idx != -1)
			count[idx]++;
		else {
			values.push_back(value);
			count[values.size() - 1]++;
		}
	}
	
	int max = 0;
	for (int i = 0; i < values.size(); i++)
		max = _max(max, count[i]);

	bool isAble = true;
	bool isFill = false;
	vector<int> mozaram;
	for (int i = 0; i < values.size(); i++) {
		if (count[i] != max) {
			mozaram.push_back(i);
		}
	}

	if (mozaram.size() > 1)
		isAble = false;
	else if (mozaram.size() == 1) {
		int idx = mozaram[0];
		if (count[idx] + 1 != max)
			isAble = false;
		else {
			isFill = true;
		}
	}

	cout << (isAble ? "Y" : "N") << '\n';
	cout << (isAble ? n : (n + isFill)) << '\n';
	cout << values.size();

	return 0;
}