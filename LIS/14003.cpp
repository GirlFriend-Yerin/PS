#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <climits>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

vector<int> vec;
vector<pii> ans;

deque<int> lis;
int _lower_bound(int start, int end, int target)
{
	int mid;

	while (start < end)
	{
		mid = (start + end) / 2;

		if (lis[mid] < target)
			start = mid + 1;

		else
			end = mid;
	}

	return end;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vec.resize(n); ans.resize(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	lis.push_back(vec[0]);

	ans[0].first = 0;
	ans[0].second = vec[0];

	for (int i = 1; i < n; i++) {

		if (lis.back() < vec[i]) {
			lis.push_back(vec[i]);

			ans[i].first = lis.size() - 1;
			ans[i].second = vec[i];
		}
		else {
			int lower = lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin();
			//int lower = _lower_bound(0, lis.size() - 1, vec[i]);
			lis[lower] = vec[i];
			ans[i].first = lower;

			ans[i].first = lower;
			ans[i].second = vec[i];
		}
	}

	cout << lis.size() << '\n';

	stack<int> printer;

	int t = lis.size() - 1;

	for (int i = n - 1; i >= 0; i--) {
		if (ans[i].first == t) {
			printer.push(ans[i].second);
			t--;
		}
	}

	while (!printer.empty()) {
		cout << printer.top() << ' '; printer.pop();
	}

	return 0;
}