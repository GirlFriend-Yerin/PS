#include <iostream>

using namespace std;

const short LEN_MAX = 6;
const short QUERY_MAX = 60;

struct Query {
	short to, des;
	short sum;
};

Query queries[QUERY_MAX];
short x, q;
short _curMax;
short _maxArr[LEN_MAX];
bool _existAns;

bool check(short prefix[LEN_MAX]) {

	for (int i = 0; i < q; i++) {
		short cal = prefix[queries[i].des] - prefix[queries[i].to - 1];

		if (cal != queries[i].sum)
			return false;
	}
	return true;
}

void dfs(short cnt[LEN_MAX], short n, short pos) {

	if (pos == n) {
		short prefixSum[LEN_MAX + 1] = {};
		for (int i = 1; i <= n; i++)
			prefixSum[i] = prefixSum[i - 1] + cnt[i - 1];

		if (check(prefixSum) && _curMax < prefixSum[n])
		{
			_existAns = true;
			_curMax = prefixSum[n];
			for (int i = 0; i < n; i++)
				_maxArr[i] = cnt[i];
		}

		return;
	}

	for (int i = 0; i <= x; i++) {
		cnt[pos] = i;
		dfs(cnt, n, pos + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		short cnt[LEN_MAX] = {};
		bool trigger[LEN_MAX + 1] = {};

		_curMax = -1;
		_existAns = false;
		for (short i = 0; i < LEN_MAX; i++)
			_maxArr[i] = 0;

		int n; cin >> n >> x >> q;

		for (int i = 0; i < q; i++) {
			cin >> queries[i].to >> queries[i].des >> queries[i].sum;
			for (int j = queries[i].to; j < queries[i].des; j++)
				trigger[j] = true;
		}

		cout << '#' << tc << ' ';
		dfs(cnt, n, 0);
		if (_existAns) {
			for (int i = 0; i < n; i++)
				cout << _maxArr[i] << ' ';
			cout << '\n';
		}
		else
			cout << -1 << '\n';
	}

	return 0;
}