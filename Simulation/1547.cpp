/*
	2019 02 10
	1547 °ø
	Simulation

	- ¼º°ø -
*/
#include <iostream>

using namespace std;

void mSwap(bool& to, bool& des)
{
	bool temp = to;
	to = des;
	des = temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int count, to, des;
	bool ball[3] = { true, false, false };
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> to >> des;
		mSwap(ball[to - 1], ball[des - 1]);
	}

	for (int i = 0; i < 4; i++)
		if (ball[i])
		{
			cout << i + 1;
			break;
		}
	return 0;
}