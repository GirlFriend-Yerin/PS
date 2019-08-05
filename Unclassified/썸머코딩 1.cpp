#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> hashs = {};

bool isExist(int val) {
	for (int item : hashs) {
		if (val == item)
			return true;
	}
	return false;
}

void bruteForce(int leftCount, int rightCount, int cL, int cR, int curVal, int hash) {

	if (curVal == 0) {
		if (!isExist(hash))
			hashs.push_back(hash);
		cout << hash << endl;
	}
	else
	{
		int nextVal = curVal / 2;
		if (leftCount > 0)
			bruteForce(leftCount - 1, rightCount, cL + 1, cR, nextVal, hash);
		if (cL > 0 && rightCount > 0)
			bruteForce(leftCount, rightCount - 1, cL - 1, cR - 1, nextVal, hash + curVal);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	bruteForce(n, n, 0, 0, pow(2, n * 2 - 1), 0);

	for (int item : hashs) {
		string ans = "";
		for (int i = 0; i < n * 2; i++) {
			ans = (item % 2 ? ')' : '(') + ans;
			item /= 2;
		}
		cout << ans << endl;;
	}

	return 0;
}