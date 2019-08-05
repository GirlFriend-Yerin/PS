#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Question {
	int order;
	int x, y;
};

class DisJointSet
{
	int size;
	vector<int> parent;

public:
	DisJointSet(int size) : size(size) {
		parent.resize(size);
		for (int i = 0; i < size; i++) parent[i] = i;
	};

	int find(int v) {
		if (parent[v] == v) return v;

		return parent[v] = find(parent[v]);
	}
	bool merge(int x, int y) {

		int px = find(x);
		int py = find(y);

		if (px == py)
			return false;

		parent[px] = py;

		return true;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	DisJointSet dis(n + 1);
	vector<Question> queries(n-1+q);
	vector<int> res;
	vector<int> p(n + 1);

	for (int i = 2; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 0; i < n - 1 + q; i++)
	{
		cin >> queries[i].order;
		if (queries[i].order)
			cin >> queries[i].x >> queries[i].y;
		else
			cin >> queries[i].x;
	}

	for (int i = n - 1 + q - 1; i >= 0; i--) {
		if (queries[i].order) {
			if (dis.find(queries[i].x) == dis.find(queries[i].y))
				res.push_back(1);
			else
				res.push_back(0);
		}
		else
			dis.merge(queries[i].x, p[queries[i].x]);
	}

	for (int i = q - 1; i >= 0; i--)
		cout << (res[i] ? "YES" : "NO") << '\n';

	return 0;
}