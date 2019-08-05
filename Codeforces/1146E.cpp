#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;

class FenwickTree
{
private:
	vector<int> vec;

public:
	FenwickTree(int n) {
		int sz = 1;
		while (sz < n) sz <<= 1;
		vec.resize(sz + 1, 0);
	}

	void add(int x, int val)
	{
		for (; x < vec.size(); x += x & (-x))
			vec[x] += val;

	}

	int sum(int x) {
		int r = 0;
		for (; x; x -= x & (-x))
			r += vec[x];
		return r;
	}

};

int values[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++)
		cin >> values[i];

	bool flipped[MAX] = {};
	
	for (int i = 0; i < q; i++)
	{
		char oper;
		int val;

		cin >> oper >> val;

		if (oper == '>')
		{
			for (int j = 0; j < n; j++) {
				if (values[j] * (flipped[j] ? -1 : 1) > val)
					flipped[j] = !flipped[j];
			}
		}
		else
		{
			for (int j = 0; j < n; j++) {
				if (values[j] * (flipped[j] ? -1 : 1) < val)
					flipped[j] = !flipped[j];
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << values[i] * (flipped[i] ? -1 : 1) << ' ';

	return 0;
}