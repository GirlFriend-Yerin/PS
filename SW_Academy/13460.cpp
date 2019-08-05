#include <iostream>
#include <queue>
#include <string>

using namespace std;

const short MAX = 10;
char board[MAX][MAX + 1];

struct Point
{
	short x, y;

	Point() {};
	Point(short x, short y) : x(x), y(y) {};
};

struct Data
{
	Point cur;
	int before;
};

int main()
{
	int row, col;
	Point red, blue, des;

	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{
		cin >> board[i];
		for (int i = 0; i < col; i++)
		{

		}
	}
	
	

	return 0;
}