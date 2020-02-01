#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, res = 0; cin >> n >> m;

	vector<int> income(n + 1), outcome(n + 1);

	for (int i = 0; i < m; i++)
	{
		int to, des; cin >> to >> des;
		income[to]++; outcome[des]++;
	}

	for (int i = 1; i <= n; i++)
		res += !income[i] || !outcome[i];

	cout << res;

	return 0;
}