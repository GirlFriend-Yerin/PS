/*
	2019 04 16
	17143 ³¬½Ã¿Õ
	½Ã¹Ä·¹ÀÌ¼Ç

	- ¼º°ø -
*/
#include <iostream>
#include <vector>

using namespace std;

const short MAX = 100;

const short posX[4] = { 0, 0, 1, 1 }; // N S E W
const short posY[4] = { 1, 1, 0, 0 };

int row, col, sharkCount;

struct Point {
	short x;
	short y;
	short speed;
	short direction;
	short size;
};

vector<Point> sharks;
vector<bool> deadSharks;

void updateShark() {

	for (int i = 0; i < sharkCount; i++)
	{
		if (deadSharks[i])
			continue;

		Point cur = sharks[i];

		int xMove = posX[cur.direction - 1] * cur.speed;
		int yMove = posY[cur.direction - 1] * cur.speed;

		while (xMove) {
			int moveDistace;
			if (cur.direction == 3)
			{
				if (cur.x + xMove < row)
				{
					cur.x += xMove;
					moveDistace = xMove;
				}
				else
				{
					moveDistace = row - cur.x;
					cur.x = row;
					cur.direction = 4;
				}
			}
			else if (cur.direction == 4)
			{
				if (cur.x - xMove > 0)
				{
					cur.x -= xMove;
					moveDistace = xMove;
				}
				else
				{
					moveDistace = cur.x - 1;
					cur.x = 1;
					cur.direction = 3;
				}

			}
			xMove -= moveDistace;
		}

		while (yMove) {
			int moveDistace;
			if (cur.direction == 1)
			{
				if (cur.y - yMove > 0)
				{
					cur.y -= yMove;
					moveDistace = yMove;
				}
				else
				{
					moveDistace = cur.y - 1;
					cur.y = 1;
					cur.direction = 2;
				}
			}
			else if (cur.direction == 2)
			{
				if (cur.y + yMove < col)
				{
					cur.y += yMove;
					moveDistace = yMove;
				}
				else
				{
					moveDistace = col - cur.y;
					cur.y = col;
					cur.direction = 1;
				}
			}

			yMove -= moveDistace;
		}

		sharks[i] = cur;
	}

	for (int i = 0; i < sharkCount; i++)
	{
		if (deadSharks[i])
			continue;

		for (int j = i + 1; j < sharkCount; j++)
		{
			if (deadSharks[j])
				continue;

			if (sharks[i].x == sharks[j].x && sharks[i].y == sharks[j].y) {
				if (sharks[i].size < sharks[j].size)
					deadSharks[i] = true;
				else if (sharks[i].size > sharks[j].size)
					deadSharks[j] = true;
			}
		}
	}
}

int topShark(int pos) {

	int idx = -1;

	for (int i = 0; i < sharkCount; i++) {
		if (deadSharks[i] || sharks[i].x != pos)
			continue;

		if (idx == -1)
			idx = i;
		else if (sharks[idx].y > sharks[i].y)
			idx = i;
	}

	return idx;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int res = 0;

	cin >> col >> row >> sharkCount;

	sharks.resize(sharkCount);
	deadSharks.resize(sharkCount);

	for (int i = 0; i < sharkCount; i++)
		cin >> sharks[i].y >> sharks[i].x >> sharks[i].speed >> sharks[i].direction >> sharks[i].size;

	for (int i = 0; i < row; i++)
	{
		int top = topShark(i + 1);

		if (top != -1) {
			//cout << i + 1 << " : " << sharks[top].size << '\n';

			res += sharks[top].size;
			deadSharks[top] = true;
		}

		updateShark();
	}

	cout << res;

	return 0;
}