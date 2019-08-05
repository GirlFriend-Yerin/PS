#include <iostream>
#include <vector>

using namespace std;

// LSB = x & (-x)
template <typename T>
class FenwickTree
{
private:
	vector<T> vec;

public:
	FenwickTree(int n) {
		int sz = 1;
		while (sz < n) sz <<= 1;
		vec.resize(sz + 1, 0);
	}

	void add(int x, T val)
	{
		for (; x < vec.size(); x += x & (-x))
			vec[x] += val;

	}

	T sum(int x) {
		T r = 0;
		for (; x; x -= x & (-x))
			r += vec[x];
		return r;
	}

};

int main()
{
	FenwickTree<int> ft(10);
	ft.add(2, 10);
	ft.add(5, 20);
	cout << ft.sum(3) << endl;
	cout << ft.sum(5) << endl;

	return 0;
}