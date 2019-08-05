#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 500000;

int income[MAX + 1];
int boss[MAX + 1];
vector<vector<int>> under;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	cin >> income[1];

	under.resize(n + 1);
	under[1].resize(n - 1);
	for (int i = 0; i < n - 1; i++)
		under[1][i] = i + 2;

	for (int i = 2; i < n + 1; i++)
	{
		cin >> income[i] >> boss[i];
		under[boss[i]].push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		char order; cin >> order;

		if (order == 'p')
		{
			int boss, inc; cin >> boss >> inc;
			bool check[MAX + 1] = {};

			queue<int> q;
			q.push(boss);
			check[boss] = true;

			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				for (int i = 0; i < under[cur].size(); i++) {
					int next = under[cur][i];

					if (!check[next])
					{
						income[next] += inc;
						check[next] = true;
						q.push(next);
					}
				}
			}
		}
		else
		{
			int num; cin >> num;
			cout << income[num] << '\n';
		}
	}

	return 0;
}