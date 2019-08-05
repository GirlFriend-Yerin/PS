#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int DIV = 1000000000;

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
struct Edge {
	int x, y, cost;

	bool operator<(Edge &e) {
		return cost < e.cost;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	long long costSum = 0;
	long long sum = 0;
	cin >> n >> m;

	DisJointSet dis(n + 1);
	vector<Edge> edges(m + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> edges[i].x >> edges[i].y >> edges[i].cost;

		costSum += edges[i].cost;
	}

	sort(edges.begin(), edges.end());

	for (int i = m; i >= 0; i--)
	{
		long long xChilds = dis.getChilds(edges[i].x);
		long long yChilds = dis.getChilds(edges[i].y);

		if (dis.find(edges[i].x) != dis.find(edges[i].y))
		{
			sum += (costSum * (xChilds * yChilds));
			sum %= DIV;

			dis.merge(edges[i].x, edges[i].y);
		}
		costSum -= edges[i].cost;		
	}

	cout << sum % DIV;

	return 0;
}