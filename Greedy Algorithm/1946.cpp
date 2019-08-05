#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TestScore {
	int first;
	int second;

	TestScore() {};
	TestScore(int first, int second) : first(first), second(second) {}
};

bool compare(TestScore& ts1, TestScore& ts2) {
	if (ts1.first < ts2.first)
		return true;
	else if (ts1.first == ts2.first) {
		if (ts1.second <= ts2.second)
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc;
	cin >> tcc;

	for (int tc = 0; tc < tcc; tc++) {
		vector<TestScore> tsv;
		int n;
		int res = 1;

		cin >> n;
		tsv.resize(n);

		for (int i = 0; i < n; i++)
			cin >> tsv[i].first >> tsv[i].second;

		sort(tsv.begin(), tsv.end(), compare);

		int secondMin = tsv[0].second;

		for (int i = 1; i < n; i++) {
			if (tsv[i].first == tsv[i-1].first) {
				res++;
				if (secondMin > tsv[i].second)
					secondMin = tsv[i].second;
			}
			else
			{
				if (secondMin > tsv[i].second) {
					res++;
					secondMin = tsv[i].second;
				}
			}
		}

		cout << res << '\n';
	}

	return 0;
}