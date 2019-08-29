#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SNUM_MAX = 1000000;

typedef pair<int, int> pii;

long long fenwik[SNUM_MAX + 1];

void _add(int idx, int val) {

	for (; idx < SNUM_MAX + 1; idx += idx & (-idx))
		fenwik[idx] += val;
}

long long _sum(int idx) {

	long long res = 0;
	for (; idx; idx -= idx & (-idx))
		res += fenwik[idx];
	return res;
}

//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	long long sum = 0;
//	int n; cin >> n;
//	vector<int> vecA(n + 1);
//	for (int i = 0; i < n; i++) {
//		int val; cin >> val;
//		pos[val] = i + 1;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		int val; cin >> val;
//		vecA[i] = pos[val];
//	}
//
//	for (int i = 1; i <= n; i++) {
//		_add(vecA[i], 1);
//		long long ret = _sum(vecA[i]);
//		sum += i - ret;
//	}
//
//	cout << sum;
//
//	return 0;
//}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long sum = 0;
	int n; cin >> n;
	vector<pii> vecA(n);
	vector<int> values(n);
	vector<int> vecB(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> vecA[i].first;
		vecA[i].second = i + 1;
		values[i] = vecA[i].first;
	}

	sort(vecA.begin(), vecA.end());

	for (int i = 1; i <= n; i++) {
		int val; cin >> val;
		int idx = lower_bound(vecA.begin(), vecA.end(), make_pair(val, 0)) - vecA.begin();

		vecB[i] = vecA[idx].second;
	}

	for (int i = 1; i <= n; i++) {
		_add(vecB[i], 1);
		long long ret = _sum(vecB[i]);
		sum += i - ret;
	}

	cout << sum;

	return 0;
}