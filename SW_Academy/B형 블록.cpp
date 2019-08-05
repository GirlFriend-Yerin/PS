#include <iostream>
#include <stdlib.h>

#define MAX 30000

using namespace std;

int makeBlock(int module[][4][4]);

int main(void)
{
	static int module[MAX][4][4];

	srand(3); // 3 will be changed

	for (int tc = 1; tc <= 10; tc++)
	{
		for (int c = 0; c < MAX; c++)
		{
			int base = 1 + (rand() % 6);
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					module[c][y][x] = base + (rand() % 3);
				}
			}
		}
		cout << "#" << tc << " " << makeBlock(module) << endl;
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

const int N = 4;

struct _pair{
	int first;
	int second;

	_pair() {}
	_pair(int first, int second) { this->first = first; this->second = second; }
};

struct _Stack {

};

int myMax(int a, int b)
{
	return a < b ? b : a;
}

int getHash(int map[4][4], int& base, int& maxHeight) {
	int hash = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			base = myMax(map[i][j], base);
			maxHeight = myMax(maxHeight, map[i][j]);
		}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			hash = (hash * 3);
			hash = (hash + map[i][j] - base);
		}
	return hash;
}

template<typename T>
void _swap(T &a, T &b) {
	T c(a); a = b; b = c;
}

void matFilp(int mat[N][N]) {
	for (int i = 0; i < N; i++) {
		_swap(mat[i][0], mat[i][3]);
		_swap(mat[i][1], mat[i][2]);
	}
}

void matRotate(int mat[][N])
{
	for (int x = 0; x < N / 2; x++)
	{
		for (int y = x; y < N - x - 1; y++)
		{
			int temp = mat[x][y];
			mat[x][y] = mat[y][N - 1 - x];
			mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];
			mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];
			mat[N - 1 - y][x] = temp;
		}
	}
}

void mySort(int begin, int end, _pair* pairs) {
	
	if (begin == end)
		return;

	int pivot = begin;
	int left = begin + 1;
	int right = end - 1;

	while (left <= right){

		while (left <= right && !(pairs[left].first < pairs[pivot].first))
			left++;
		while (left <= right && !(pairs[pivot].first < pairs[right].first))
			right--;

		if (left <= right)
			_swap(pairs[left], pairs[right]);
	}

	_swap(pairs[pivot], pairs[right]);

	mySort(begin, right, pairs);
	mySort(right + 1, end, pairs);

}

void mySort(int begin, int end, int* pairs) {

	if (begin == end)
		return;

	int pivot = begin;
	int left = begin + 1;
	int right = end - 1;

	while (left <= right) {

		while (left <= right && !(pairs[left] < pairs[pivot]))
			left++;
		while (left <= right && !(pairs[pivot] < pairs[right]) )
			right--;

		if (left <= right)
			_swap(pairs[left], pairs[right]);
	}

	_swap(pairs[pivot], pairs[right]);

	mySort(begin, right, pairs);
	mySort(right + 1, end, pairs);

}

template<typename T>
void _getIdx(T* arr, T& val) {
	int left = 0;
	int right = MAX - 1;

	while (left <= right) {

		int mid = (left + right) / 2;

		if (arr[mid] <= val)
			mid = left + 1;
		else
			mid = right - 1;
	}

	return arr[right] == val ? right : -1;
}

int makeBlock(int module[][4][4])
{
	int hash[MAX] = {};
	int base[MAX] = {};
	int height[MAX] = {};
	bool check[MAX] = {};

	_pair* vec = new _pair[MAX];

	for (int i = 0; i < MAX; i++) {
		base[i] = 10;
		hash[i] = getHash(module[i], base[i], height[i]);

		vec[i].first = height[i];
		vec[i].second = i;
	}

	mySort(0, MAX, vec);
	mySort(0, MAX, hash);


	for (int i = 0; i < MAX; i++) {
		int idx = vec[i].second;
	}

	delete[] vec;

	return sum;
}

