#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int posX[] = { 1, 0, -1, 0 };
const int posY[] = { 0, 1, 0, -1 };
const int INF = 1e9 + 7;

typedef pair<int, int> pii;

struct Node {
	int x;
	int y;

	Node() {}
	Node(int x, int y) : x(x), y(y){};
};

void bfs(vector<vector<int>>& land, vector<vector<bool>>& visited, int n, int height, Node& start) {

	queue<Node> q;
	q.push(start);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			while (!q.empty())
			{
				Node cur = q.front(); q.pop();

				for (int i = 0; i < 4; i++)
				{
					int nextX = cur.x + posX[i];
					int nextY = cur.y + posY[i];

					if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n && !visited[nextX][nextY])
					{
						int diff = abs(land[cur.x][cur.y] - land[nextX][nextY]);
						if (diff <= height) {
							visited[nextX][nextY] = true;
							q.push(Node(nextX, nextY));
						}
					}
				}
			}
		}
	}

}

int solution(vector<vector<int>> land, int height) {
	int n = land.size();
	int answer = 0;
	vector<vector<bool>> visited(n, vector<bool>(n));

	vector<Node> entry;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			visited[i][j] = true;
			Node cur(i, j);
			entry.push_back(cur);
			bfs(land, visited ,n, height, cur);
		}
	}

	for (int i = 0; i < entry.size(); i++) {
		Node cur = entry[i];
		int minCost = INF;

		for (int i = 0; i < 4; i++) {
			int nextX = cur.x + posX[i];
			int nextY = cur.y + posY[i];

			if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n) {
				int diff = abs(land[cur.x][cur.y] - land[nextX][nextY]);

				if (diff <= height) continue;

				minCost = min(minCost, diff);
			}
		}
		
		answer += minCost * (minCost > height);
	}

	return answer;
}

int main()
{
	int n; cin >> n;
	vector<vector<int>> vec(n, vector<int>(n));

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> vec[i][j];

	int height; cin >> height;

	cout << solution(vec, height);


	return 0;
}