#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Path {
	int count;
	int path[2000];

	Path() : count(0) { };
};
const int MAX = 100;

int currentGroup, groupCount;
int adj[26][26];
Path path[26];

int myAbs(int i) {
	return i < 0 ? -i : i;
}

void start() {
	groupCount = 1;
	currentGroup = 0;
	for (int i = 0; i < 26; i++)
	{
		path[i].count = 0;

		for (int j = 0; j < 26; j++)
			adj[i][j] = 0;
	}
	++path[0].count;
};

int getDist(int g1, int g2, int g1Pos, int cost, bool* check)
{
	if (g1 == g2)
	{
		return cost + abs(path[g2].count - g1Pos - 1);
	}

	for (int i = 0; i < groupCount; i++)
	{
		if (adj[g1][i] == 0 || check[i])
			continue;

		check[g1] = true;

		if (adj[g1][i] < 0) // to Parent
		{
			int cal = getDist(i, g2, 0, cost + myAbs(g1Pos - 1 - adj[g1][i]), check);

			if (cal)
				return cal;
		}
		else // to Child
		{
			int cal = getDist(i, g2, 0, cost + myAbs(g1Pos - 1 - i), check);
		}
		check[g1] = false;
	}

	return 0;
}

void move(int num) {
	path[currentGroup].path[path[currentGroup].count++] = num;
}

void changeGroup(char group) {
	int nextGroup = group - 'a';
	int res = 0;

	if (path[nextGroup].count == 0)
	{
		adj[currentGroup][nextGroup] = path[currentGroup].count;
		adj[nextGroup][currentGroup] = -path[currentGroup].count;
		path[nextGroup].path[path[nextGroup].count++] = path[currentGroup].path[path[currentGroup].count - 1];

		++groupCount;
	}
	else
	{
		bool checker[MAX] = {};

		res = getDist(currentGroup, nextGroup, path[currentGroup].count, 0, checker);
	}

	printf("%d\n", res);
	currentGroup = group - 'a';
}

int findRelation(int cnt, int cur, int target, int* parentList)
{
	if (cur == target)
	{	// 목적지에 도착
		return 1;
	}
	else
	{
		for (int i = 0; i < groupCount; i++)
		{
			if (adj[cur][i] > 0) // 부모 -> 자식 관계면 탐색
			{
				parentList[cnt] = cur + 1;
				if (findRelation(cnt + 1, i, target, parentList) != 0)
					return 1;
			}
		}
	}

	return 0;
}

void findCloseArea(char group1, char group2) {
	int g1 = group1 - 'a';
	int g2 = group2 - 'a';
	int closeParent = 0;
	int res;
	
	if (g1 == g2)
		res = path[g1].path[path[g1].count - 1];
	else
	{
		int parentList[2][2000] = {};
		findRelation(0, 0, g1, parentList[0]);
		findRelation(0, 0, g2, parentList[1]);

		for (int i = 0; i < groupCount; i++)
		{
			if ((parentList[0][i] && parentList[1]) && parentList[0][i] == parentList[1][i])
				closeParent = parentList[0][i] - 1;
			else
				break;
		}

		if (adj[closeParent][g1] > adj[closeParent][g2])
			res = path[closeParent].path[adj[closeParent][g1] - 1];
		else
			res = path[closeParent].path[adj[closeParent][g2] - 1];
	}
	
	printf("%d\n", res);
}

void showPath(char group) {
	int g = group - 'a';
	int parentList[2000] = {};

	findRelation(0, 0, g, parentList);

	for (int i = 0; parentList[i] != 0; i++)
	{
		int nextParent = (i < 26 && parentList[i + 1]) ? parentList[i + 1] : g;
		for (int j = 0; j < adj[parentList[i] - 1][nextParent] - 1; j++)
			printf("%d ", path[parentList[i] - 1].path[j]);
	}

	for (int i = 0; i < path[g].count; i++)
		printf("%d ", path[g].path[i]);
	printf("\n");
}

int main()
{
	int tc;
	int cmd;
	int areaID;
	char groupId1, groupId2;

	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
	{
		while (1)
		{
			scanf("%d", &cmd);

			if (cmd == 0)
				start();
			else if (cmd == 1)
			{
				scanf("%d", &areaID);
				move(areaID);
			}
			else if (cmd == 2)
			{
				scanf(" %c", &groupId1);
				changeGroup(groupId1);
			}
			else if (cmd == 3)
			{
				scanf(" %c %c", &groupId1, &groupId2);
				findCloseArea(groupId1, groupId2);
			}
			else if (cmd == 4) {
				scanf(" %c", &groupId1);
				showPath(groupId1);
			}
			else if (cmd == 5)
			{
				break;
			}
		}
	}
	return 0;
}