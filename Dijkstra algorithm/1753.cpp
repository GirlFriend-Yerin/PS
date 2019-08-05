#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct Edge {
	int des;
	short weight;

	Edge() {}
	Edge(int des, short weight) : des(des), weight(weight) {}
};

struct Point {
	int x;
	int y;
	int weight;

	Point() {}
	Point(int x, int y, int weight) : x(x), y(y), weight(weight) {};

	bool operator<(const Point& p) const {
		return weight > p.weight;
	}
};

const int MAX = 20000;
vector<vector<Edge>> edgeData(MAX + 1);
int cost[MAX + 1];

int main()
{
	int n, m, start;
	cin >> n >> m >> start;

	priority_queue <Point> q;

	memset(cost, -1, n * sizeof(int));

	for (int i = 0; i < m ;i++)
	{
		int st, de, w;
		scanf("%d %d %d", &st, &de, &w);

		edgeData[st - 1].push_back(Edge(de - 1, w));
	}

	for (int i = 0; i < edgeData[start - 1].size(); i++)
		q.push(Point(start - 1, edgeData[start - 1][i].des, edgeData[start - 1][i].weight));

	cost[start - 1] = 0;

	while (!q.empty())
	{
		Point cur = q.top();
		q.pop();

		if (cost[cur.y] != -1 && cost[cur.y] < cur.weight)
			continue;

		cost[cur.y] = cur.weight;

		for (int i = 0; i < edgeData[cur.y].size(); i++)
		{
			Edge edge = edgeData[cur.y][i];

			if (cost[edge.des] == -1 || edge.weight + cur.weight < cost[cur.y])
				q.push(Point(cur.y, edge.des, edge.weight + cur.weight));
		}
	}

	for (int i = 0; i < n; i++)
		if (cost[i] != -1)
			cout << cost[i] << '\n';
		else
			cout << "INF\n";

	return 0;
}