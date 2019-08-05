#include <iostream>
#include <vector>

using namespace std;

vector<int> beforeFound;

bool isExist(int n) {

	int len = beforeFound.size();
	for (int i = 0; i < len; i++)
		if (n == beforeFound[i])
			return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int cnt = 0;

	while (!isExist(n)) {
		beforeFound.push_back(n);
		cnt++;
		n++;
		while (n % 10 == 0)
			n /= 10;
	}

	cout << cnt;

	return 0;
}