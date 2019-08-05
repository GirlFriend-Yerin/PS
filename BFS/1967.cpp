#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short NODE_MAX = 10000;

struct Node {
	short vertex;
	int weight;

	Node() {};
	Node(short v, int w) : vertex(v), weight(w) {};
};

Node parent[NODE_MAX];
vector<vector<Node>> child;

int getMaxNodeAtRoot() {

	bool check[NODE_MAX] = { true, };
	int maxLength = 0;
	int maxNode = 0;
	queue<Node> q;
	q.push(Node(0, 0));

	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();

		if (cur.weight > maxLength) {
			maxLength = cur.weight;
			maxNode = cur.vertex;
		}

		for (int i = 0; i < child[cur.vertex].size(); i++) {
			Node childNode = child[cur.vertex][i];
			if (!check[childNode.vertex]) {
				check[childNode.vertex] = true;
				q.push(Node(childNode.vertex, cur.weight + childNode.weight));
			}
		}
	}

	return maxNode;
}

int solve(int start) {

	int res = 0;
	bool check[NODE_MAX] = {};
	queue<Node> q;
	q.push(Node(start, 0));
	check[start] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		if (cur.weight > res) {
			res = cur.weight;
		}

		Node curParent = parent[cur.vertex];
		if (!check[curParent.vertex]) {
			check[curParent.vertex] = true;
			q.push(Node(curParent.vertex, cur.weight + curParent.weight));
		}

		for (int i = 0; i < child[cur.vertex].size(); i++) {
			Node childNode = child[cur.vertex][i];
			if (!check[childNode.vertex]) {
				check[childNode.vertex] = true;
				q.push(Node(childNode.vertex, cur.weight + childNode.weight));
			}
		}
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int nodeCount;
	cin >> nodeCount;

	child.resize(nodeCount);

	for (int i = 0; i < nodeCount; i++) {
		int par, chd, wei;

		cin >> par >> chd >> wei;

		child[par - 1].push_back(Node(chd - 1, wei));
		parent[chd - 1] = Node(par - 1, wei);
	}

	int maxAtRoot = getMaxNodeAtRoot();

	int res = solve(maxAtRoot);
	
	cout << res;

	return 0;
}