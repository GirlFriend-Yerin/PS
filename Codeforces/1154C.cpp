/*
	2019 04 17

	Fail
*/

#include <iostream>

using namespace std;

int feed[7] = { 0, 1, 2, 0, 2, 1, 0};
int food[3];

int min(int a, int b, int c) {
	int res;
	if (a <= b) {
		if (a < c)
			res = a;
		else
			res = c;
	}
	else if (b <= c) {
		if (b < a)
			res = b;
		else
			res = a;
	}
	else {
		if (c < b)
			res = c;
		else
			res = b;
	}

	return res;
}

int max(int a, int b, int c) {
	int res;

	if (a >= b) {
		if (a > c)
			res = a;
		else
			res = c;
	}
	else if (b >= c) {
		if (b > a)
			res = b;
		else
			res = a;
	}
	else {
		if (c > b)
			res = c;
		else
			res = b;
	}

	return res;
}

int startFeed(int startDay, int r[3])
{
	int res = 0;

	for (int i = startDay; i < 7 && r[feed[i]]; i++) {
		r[feed[i]]--;
		res++;
	}

	return res;
}

int weekFeed(int r[3])
{
	int aWeek = r[0] / 3;
	int bWeek = r[1] / 2;
	int cWeek = r[2] / 2;

	int minWeek = min(aWeek, bWeek, cWeek);

	r[0] -= minWeek * 3;
	r[1] -= minWeek * 2;
	r[2] -= minWeek * 2;

	return minWeek * 7;
}

int main()
{
	int res = 0;
	cin >> food[0] >> food[1] >> food[2];

	for (int i = 0; i < 7; i++) {
		int remain[3] = { food[0], food[1], food[2] };

		int firstWeek = startFeed(i, remain);
		int curRes = firstWeek;

		if (firstWeek == 7 - i)
		{
			curRes += weekFeed(remain);
			curRes += startFeed(i, remain);
		}

		//cout << i << " - " << curRes << endl;

		if (res < curRes)
			res = curRes;
	}

	cout << res;

	return 0;
}