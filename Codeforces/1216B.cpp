#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

bool cmp(const pii& a, const pii& b) {
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<pii> vec(n);
	vector<int> res(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i].first;
		vec[i].second = i + 1;
	}

	sort(vec.begin(), vec.end(), cmp);

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += vec[i].first * i + 1;
		res[i] = vec[i].second;
	}

	cout << sum << '\n';
	for (int pos : res)
		cout << pos << ' ';

	return 0;
}