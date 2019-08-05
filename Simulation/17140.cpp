#include <iostream>
using namespace std;

const int MAX = 100;

struct DigitData {
	short digit;
	short count;

	DigitData() {};
	DigitData(short digit, short count) : digit(digit), count(count) {};
};

struct DigitHeap {
	int count;
	DigitData data[MAX];

	DigitHeap() : count(0) {};

	void add(DigitData dd) {
		data[count].count = dd.count;
		data[count].digit = dd.digit;

		count ++;

		adjust2Top();
	}

	DigitData pop() {
		DigitData ret = data[0];

		data[0] = data[--count];
		adjust2bottom();

		return ret;
	}

	bool isEmpty() {
		return count == 0;
	}

private:
	void adjust2bottom()
	{
		int pos = 0;

		while (pos * 2 + 1 < count || pos * 2 + 2 < count)
		{
			int nextPos = count;
			if (pos * 2 + 2 < count)
			{
				if (isBigger(pos, pos * 2 + 1) || isBigger(pos, pos * 2 + 2)) {
					nextPos = isBigger(pos * 2 + 1, pos * 2 + 2) ? pos * 2 + 2 : pos * 2 + 1;

					swap(data[pos], data[nextPos]);

					pos = nextPos;
				}
			}
			else if (pos * 2 + 1 < count) {
				if (isBigger(pos, pos * 2 + 1)) {
					swap(data[pos], data[pos * 2 + 1]);
					nextPos = pos * 2 + 1;
				}
			}
			pos = nextPos;
		}
	}

	void adjust2Top()
	{
		int pos = count - 1;

		while (pos != pos / 2 && isBigger(pos / 2, pos))
		{
			swap(data[pos], data[pos / 2]);
			pos /= 2;
		}
	}

	bool isBigger(int origin, int cmp) {
		if (data[origin].count > data[cmp].count)
			return true;
		else if (data[origin].count == data[cmp].count)
			return data[origin].digit > data[cmp].digit;
		return false;
	}
};

void funcR(int origin[MAX][MAX], int des[MAX][MAX], int& row, int& col)
{
	int rowMax = 0;
	for (int i = 0; i < col; i++)
	{
		DigitHeap heap;
		int digit[MAX + 1] = {};

		for (int j = 0; j < row; j++) {
			if (origin[i][j])
				digit[origin[i][j]]++;
		}

		for (int j = 1; j < MAX + 1; j++)
			if (digit[j] > 0)
				heap.add(DigitData(j, digit[j]));

		int count = 0;
		while (!heap.isEmpty() && count < 100) {
			DigitData cur = heap.pop();

			des[i][count++] = cur.digit;
			des[i][count++] = cur.count;
		}

		if (rowMax < count)
			rowMax = count;
	}

	row = rowMax;
}

void funcC(int origin[MAX][MAX], int des[MAX][MAX], int& row, int& col)
{
	int colMax = 0;
	for (int i = 0; i < row; i++)
	{
		DigitHeap heap;
		int digit[MAX + 1] = {};

		for (int j = 0; j < col; j++) {
			if (origin[j][i])
				digit[origin[j][i]]++;
		}

		for (int j = 1; j < MAX + 1; j++)
			if (digit[j] > 0)
				heap.add(DigitData(j, digit[j]));

		int count = 0;
		while (!heap.isEmpty() && count < 100) {
			DigitData cur = heap.pop();

			des[count++][i] = cur.digit;
			des[count++][i] = cur.count;
		}

		if (colMax < count)
			colMax = count;
	}

	col = colMax;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int r, c, k;
	int curRow = 3, curCol = 3;

	cin >> r >> c >> k;

	int board[MAX][MAX] = {};

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];

	int res = -1;

	for (int i = 0; i < MAX; i++)
	{
		if (board[r - 1][c - 1] == k)
		{
			res = i;
			break;
		}

		int copyBoard[MAX][MAX] = {};

		if (curRow > curCol)
			funcC(board, copyBoard, curRow, curCol);
		else
			funcR(board, copyBoard, curRow, curCol);

		for (int j = 0; j < curCol; j++)
			for (int k = 0; k < curRow; k++)
				board[j][k] = copyBoard[j][k];
	}

	cout << res;

	return 0;
}