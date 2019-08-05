#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Relation {
	int des;
	int weight;

	Relation() : des(0), weight(0){}
	Relation(int des, int weight) : des(des), weight(weight) {} 
};

int func(int n, int to, int des, vector<vector<Relation>>& par, vector<vector<Relation>>& child)
{
	queue<int> posQ;
	queue<int> weiQ;

	bool visited[1000000];
	int res = -1000001;

	fill_n(visited, n, false);

	posQ.push(to);
	weiQ.push(0);

	while (!posQ.empty())
	{
		int cur = posQ.front();
		int curWeight = weiQ.front();

		if (cur == des)
		{
			res = curWeight;
			break;
		}

		posQ.pop();
		weiQ.pop();

		if (visited[cur])
			continue;

		visited[cur] = true;

		for (Relation r : par[cur])
		{
			if (visited[r.des])
				continue;
			posQ.push(r.des);
			weiQ.push(r.weight + curWeight);
		}

		for (Relation r : child[cur])
		{
			if (visited[r.des])
				continue;
			posQ.push(r.des);
			weiQ.push(r.weight + curWeight);
		}
	}

	return res;
}

int main()
{
	int n, m;

	cin >> n >> m;

	while (n != 0 && m != 0)
	{
		vector<vector<Relation>> parent(n);
		vector<vector<Relation>> child(n);

		for (int i = 0; i < m; i++)
		{
			char order;
			int to, des, w;
			
			scanf(" %c", &order);
			if (order == '!')
			{
				scanf("%d %d %d", &to, &des, &w);
				parent[to - 1].push_back(Relation(des - 1, w));
				child[des - 1].push_back(Relation(to - 1, -w));
			}
			else if (order == '?')
			{
				scanf("%d %d", &to, &des);

				int diff = func(n, to - 1, des - 1, parent, child);
				if (diff == -1000001)
					printf("UNKNOWN\n");
				else
					printf("%d\n", diff);

			}
		}

		cin >> n >> m;
	}

	return 0;
}