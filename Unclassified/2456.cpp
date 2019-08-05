#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class kth_segment_tree {
private:
	int n;
	vector<int> v;

public:
	kth_segment_tree(int _n)
	{
		n = 1;
		while (n < _n) n <<= 1;

		v.resize(2 * n, 0);
		for (int i = 0; i < 2 * n; i++) v[i] = 1;
		for (int i = n - 1; i > 0; i--) v[i] = v[2 * i] + v[2 * i + 1];
	}

	void remove(int x) {
		for (x += n - 1; x > 0; x >>= 1)
			v[x]--;
	}

	int kth(int k)
	{
		int x = 1;
		while (x < n) {
			if (v[2 * x] >= k) x = 2 * x;
			else {
				k -= v[2 * x];
				x = 2 * x + 1;
			}
		}

		return x - n + 1;
	}
};

int main()
{
	int n;
	cin >> n;
	kth_segment_tree kst(n * 2);
	vector<int> people(n, 0);
	vector<int> rank(n, 0);
	vector<int> result(n, 0);

	for (int i = 0; i < n; i++)
		cin >> people[i];

	sort(people.begin(), people.end());

	for (int i = 0; i < n; i++)
		cin >> rank[i];

	for (int i = n - 1; i >= 0; i--)
	{
		int idx = kst.kth(rank[i] + 1);
		result[i] = people[idx-1];
		kst.remove(idx);
	}

	for (int i = 0; i < n; i++)
		cout << result[i] << ' ';

	return 0;
}