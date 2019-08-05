#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int flag; cin >> flag;
	int res = 0;
	for (int i = 0; i < 5; i++){
		int val; cin >> val;
		res += (val % 10) == flag;
	}

	cout << res;

	return 0;
}