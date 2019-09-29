#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void propagation(vector<int>& candies, vector<vector<int>>& followers, int n) {

	vector<bool> visited(followers.size());
	queue<int> q;

	for (int i = 0; i < followers[n].size(); i++) {
		q.push(followers[n][i]);
		visited[followers[n][i]] = true;
	}

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		candies[cur]++;

		for (int i = 0; i < followers[cur].size(); i++) {
			int next = followers[cur][i];

			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> candies(n);
	vector<vector<int>> followers(n);

	char order;
	for (int turn = 0; cin >> order; turn++) {

		int curPlayer = turn % n;

		switch (order) {
		case'A': 
			candies[curPlayer]++;
			propagation(candies, followers, curPlayer);
			break;
		case'J': {
			int left = (curPlayer - 1 + n) % n;
			int right = (curPlayer + 1) % n;
			candies[left]++; propagation(candies, followers, left);
			candies[right]++; propagation(candies, followers, right);
		}
			break;
		case'Q':
			for (int i = 0; i < n; i++) candies[i]++;
			break;
		case'K':
			int k; cin >> k;
			followers[curPlayer].push_back(k);
			break;
		}
	}

	for (int i = 0; i < n; i++)
		cout << candies[i] << ' ';

	return 0;
}