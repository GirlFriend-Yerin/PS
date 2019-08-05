#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, flag; cin >> cnt >> flag;

	for (int i = 0; i < cnt; i++)
	{
		int val; cin >> val;
		if (val < flag)
			cout << val << ' ';
	}

	return 0;
}