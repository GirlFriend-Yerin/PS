/*
	2019 01 10
	1799 비숍
	Back Tracking

	- 시간초과 -
*/
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	short x;
	short y;

	Point() {};
	Point(short x, short y) : x(x), y(y) {}
};

int side;
int res;
Point bishops[100];
Point ablePoint[100];
int ableCount;

void func(int pos, int count)
{
	if (pos == ableCount)
	{
		if (res < count)
			res = count;
	}
	else
	{
		bool isAble = true;

		for (int i = 0; i < count; i++)
			if (abs(ablePoint[pos].x - bishops[i].x) == abs(ablePoint[pos].y - bishops[i].y))
			{
				isAble = false;
				break;
			}

		if (isAble)
			bishops[count] = ablePoint[pos];
		func(pos + 1, count + isAble);
		bishops[count] = Point();
		func(pos + 1, count);
	}
}

int main()
{
	cin >> side;
	int startRow = -1;

	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
		{
			short val;
			cin >> val;
			if (val)
			{
				if (startRow == -1)
					startRow = i;
				ablePoint[ableCount++] = Point(i, j);
			}
		}
		
	for (int i = 0; i < ableCount; i++)
		func(i, 0);

	cout << res;

	return 0;
}