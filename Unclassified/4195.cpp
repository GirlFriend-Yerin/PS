#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class ID {
	map<string, int> ids;

public:
	ID() {};

	void add(string name) {
		if (ids.find(name) != ids.end()) return;
		int id = ids.size() + 1;
		ids.insert(make_pair(name, id));
	}

	int get(string& name) {
		return ids[name];
	}
};

class DisJointSet
{
	int size;
	vector<int> parent;
	vector<int> childs;

public:
	DisJointSet(int size) : size(size) {
		parent.resize(size);
		childs.resize(size);

		for (int i = 0; i < size; i++) {
			parent[i] = i;
			childs[i] = 1;
		}
	};

	int getChilds(int x)
	{
		return childs[find(x)];
	}

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
		childs[py] += childs[px];

		return true;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;
	cin >> tcc;

	while (tcc--)
	{
		int n;
		cin >> n;

		ID ids;
		DisJointSet dis(2 * n);

		while (n--)
		{
			string a, b;
			cin >> a >> b;

			ids.add(a); ids.add(b);
			dis.merge(ids.get(a), ids.get(b));

			cout << dis.getChilds(ids.get(a)) << '\n';
		}
	}

	return 0;
}