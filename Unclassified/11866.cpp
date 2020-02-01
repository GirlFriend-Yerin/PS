#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, counter = 1; cin >> n >> k;
	queue<int> q;

	for (int i = 1; i <= n; i++) q.push(i);

	cout << '<';
	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		if (counter != k) {
			q.push(cur);
			counter++;
		}
		else {
			cout << cur;
			counter = 1;
			if (!q.empty()) cout << ", ";
		}
	}
	cout << '>';

	return 0;
}