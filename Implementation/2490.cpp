#include <iostream>

using namespace std;

char what(const int& val) {
	return val == 0 ? 'D' : val == 1 ? 'C' : val == 2 ? 'B' : val == 3 ? 'A' : 'E';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			int val; cin >> val;
			sum += val;
		}
		
		cout << what(sum) << '\n';

	}

	return 0;
}