#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class SegmentTree
{
private:
	int size;
	vector<T> vec;

public:
	SegmentTree(int n) {
		size = 1;
		while (size < n) size *= 2;
		vec.resize(2 * size, 2000000000);
	}

	void set(int x, T v)
	{
		x += size - 1;
		while (x >= 1)
		{
			if (vec[x] > v)
				vec[x] = v;
			else
				break;
			x /= 2;
		}
	}

	T get(int l, int r)
	{
		l += size - 1;
		r += size - 1;
		T ret = 2000000000;
		while (l <= r)
		{
			if (l % 2 == 1)
				ret = min(vec[l], ret);
			if (r % 2 == 0)
				ret = min(vec[r], ret);

			l = (l + 1) / 2;
			r = (r - 1) / 2;
		}

		return ret;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	SegmentTree<int> st(10);

	st.set(1, 4);
	st.set(4, 6);
	st.set(6, 9);
	st.set(8, 1);
	st.set(9, 2);

	while (true)
	{
		int l, r;
		cin >> l >> r;

		cout << st.get(l, r) << endl;
	}

	return 0;
}