#include <iostream>

using namespace std;

char solve(const int& val) {
	return val < 60 ? 'F' : val < 70 ? 'D' : val < 80 ? 'C' : val < 90 ? 'B' : 'A';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int val; cin >> val;
	cout << solve(val);

	return 0;
}