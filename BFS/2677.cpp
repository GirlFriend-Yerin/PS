/*
	2019 01 05
	2677 - 단지번호 붙이기
	BFS

	- -
*/
#include <iostream>

using namespace std;

const short MAX_SIZE = 625;

struct mPoint {
	short x;
	short y;
	
	mPoint() {}
	mPoint(short x, short y) : x(x), y(y) {}
};

short map[25][25];
bool checker[25][25];
mPoint q[MAX_SIZE];
int head = 0;
int tail = 0;
const short posX[4] = { 1, 0 , -1, 0 };
const short posY[4] = { 0, 1, 0, -1 };

void push(short x, short y) {
	q[head++ % MAX_SIZE] = mPoint(x, y);
}

mPoint pop() {
	return q[tail++ % MAX_SIZE];
}

bool isEmpty() {
	return head == tail;
}

int main()
{
	int n;
	int number = 0;
	int sizeList[313];

	cin >> n;

	fill_n(sizeList, 313, 0);

	for (int i = 0; i < n; i++)
	{
		char line[26];
		cin >> line;
		for (int j = 0; j < n; j++)
			map[i][j] = int(line[j] - '0');
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (checker[i][j] || map[i][j] == 0)
				continue;

			push(i, j);

			// BFS
			while (!isEmpty())
			{
				mPoint cur = pop();

				if (checker[cur.x][cur.y])
					continue;

				checker[cur.x][cur.y] = true;
				sizeList[number]++;

				for (int k = 0; k < 4; k++)
				{
					short nextX = cur.x + posX[k];
					short nextY = cur.y + posY[k];
					if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n)
						if (map[nextX][nextY] == 1)
							push(nextX, nextY);
				}
					
			}

			number++;
		}
	}

	// Selection Sort
	for (int i = 0; i < number; i++)
	{
		int min = i;
		for (int j = i; j < number; j++)
			if (sizeList[min] > sizeList[j])
				min = j;
		swap(sizeList[min], sizeList[i]);
	}

	cout << number << '\n';
	for (int i = 0; i < number; i++)
		cout << sizeList[i] << '\n';

	return 0;
}