/*
	2019 01 28
	1074 Z
	MatheMatics

	- ¼º°ø -
*/
#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;

int solve(int sX, int eX, int sY, int eY, int startV, int endV)
{
	if (sX == c && sY == r)
		return startV;

	int halfX = (sX + eX) / 2;
	int halfY = (sY + eY) / 2;
	int quarter = (endV - startV) / 4;
	if (sX <= c && c < halfX && sY <= r && r < halfY) // left top
		return solve(sX, halfX, sY, halfY, startV, startV + quarter);
	else if (halfX <= c && c < eX && sY <= r && r < halfY) // right bottom
		return solve(halfX, eX, sY, halfY, startV +quarter, startV + (quarter * 2));
	else if (sX <= c && c < halfX && halfY <= r && r < eY) // left bottom
		return solve(sX, halfX, halfY, eY, startV + (quarter * 2), startV + (quarter * 3));
	return solve(halfX, eX, halfY, eY, startV + (quarter * 3), endV); // right top
}

int main()
{
	int i;
	cin >> n >> r >> c;

	for (i = 1; !(r < pow(2, i) && c < pow(2, i)); i++); // get N

	cout << solve(0, pow(2, i), 0, pow(2, i), 0, pow(2, i) * pow(2, i));

	return 0;
}