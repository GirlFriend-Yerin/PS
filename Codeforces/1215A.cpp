#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t1, t2; cin >> t1 >> t2;
	int card1, card2; cin >> card1 >> card2;
	int n; cin >> n;

	int maxBuf = (t1 * (card1 - 1)) + (t2 * (card2 - 1));
	int calMin = maxBuf >= n ? 0 : (n - maxBuf);
	int calMax = 0;
	if (card1 < card2) {
		if (card1 * t1 >= n)
			calMax = n / card1;
		else {
			int temp = n - (card1 * t1);
			calMax += t1;
			calMax += temp / card2;
		}
	}
	else {
		if (card2 * t2 >= n)
			calMax = n / card2;
		else {
			int temp = n - (card2 * t2);
			calMax += t2;
			calMax += temp / card1;
		}
	}
	cout << calMin << ' ' << calMax;

	
	return 0;
}