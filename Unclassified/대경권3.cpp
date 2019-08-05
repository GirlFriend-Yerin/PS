#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100;

bool adj[MAX][MAX];
bool visited[MAX];
vector<int> calVec;

long long calCaseCount() {

	long long sum = 0;
	int size = calVec.size();

	for (int i = 0; i < size - 1; i++) {
		int cal = 0;

		for (int j = i + 1; j < size; j++) {
			cal += calVec[i] * calVec[j];
		}
		sum += cal;
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;

		cin >> a >> b;

		adj[a - 1][b - 1] = true;
		adj[b - 1][a - 1] = true;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;

		queue<int> q;
		int count = 0;

		q.push(i);
		visited[i] = true;

		while (!q.empty()) {

			int cur = q.front();
			q.pop();
			count++;

			for (int j = 0; j < n; j++) {

				if (adj[cur][j] && !visited[j]) {
					visited[j] = true;
					q.push(j);
				}
			}
		}
		calVec.push_back(count);
	}

	cout << calCaseCount();

	return 0;
}