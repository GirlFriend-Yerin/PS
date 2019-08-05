#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;

bool backtrack(int pos, int n, vector<pair<int, int>>& memory) {

	if (pos == n)
		return true;
	else
	{
		for (int i = 0; i < memory.size(); i++) {
			if ((pos && res[pos - 1] + 1 == memory[i].first) || !memory[i].second)
				continue;

			res[pos] = memory[i].first;

			memory[i].second--;
			if (backtrack(pos + 1, n, memory))
				return true;
			memory[i].second++;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		int n; cin >> n;

		vector<int> vec(n);
		vector<pair<int, int>> counting;

		for (int i = 0; i < n; i++)
			cin >> vec[i];

		sort(vec.begin(), vec.end());

		counting.push_back({ vec[0], 1 });
		for (int i = 1; i < n; i++) {
			if (vec[i] == vec[i - 1])
				counting[counting.size() -1].second++;
			else
				counting.push_back({ vec[i], 1 });
		}

		res.resize(n);

		backtrack(0, n, counting);

		cout << '#' << tc << ' ';
		for (int i = 0; i < n; i++)
			cout << res[i] << ' ';
		cout << '\n';
	}

	return 0;
}