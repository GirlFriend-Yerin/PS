#include <iostream>

using namespace std;

int dayOfMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void solve(const int& val) {
	switch (val)
	{
	case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;

	default:
		break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x, y; cin >> x >> y;

	int diff = y;
	for (int i = 1; i < x; i++)
		diff += dayOfMonth[i-1];

	solve(diff % 7);

	return 0;
}