#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int vertex;
	int weight;

	Node() : vertex(0), weight(0) {};
	Node(int vertex, int weight) : vertex(vertex), weight(weight) {};
};

const int MAX = 40000;

vector<vector<Node>> node;
Node parent[MAX];
int level[MAX];
bool visitedCheck[MAX];

int balancing(int& vert1, int& vert2) {
	int res = 0;

	while (level[vert1] > level[vert2]) {
		res += parent[vert1].weight;
		vert1 = parent[vert1].vertex;
	}

	while (level[vert1] < level[vert2]) {
		res += parent[vert2].weight;
		vert2 = parent[vert2].vertex;
	}

	return res;
}

void setLevelNParent(int pos) {
	visitedCheck[pos] = true;
	int edgeCount = node[pos].size();

	for (int i = 0; i < edgeCount; i++){
		Node vert = node[pos][i];
		if (!visitedCheck[vert.vertex]) {
			parent[vert.vertex] = Node(pos, vert.weight);
			level[vert.vertex] = level[pos] + 1;

			setLevelNParent(vert.vertex);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;

	node.resize(n);

	for (int i = 0; i < n - 1; i++) {
		int to, des, weight;
		cin >> to >> des >> weight;

		node[to - 1].push_back(Node(des -1, weight));
		node[des - 1].push_back(Node(to -1, weight));
	}

	setLevelNParent(0);

	cin >> m;

	for (int i = 0; i < m; i++) {
		int to, des;

		cin >> to >> des;

		to--; des--;

		int res = balancing(to, des);

		while (to != des) {
			res += parent[to].weight + parent[des].weight;

			to = parent[to].vertex;
			des = parent[des].vertex;
		}

		cout << res << '\n';
	}

	return 0;
}