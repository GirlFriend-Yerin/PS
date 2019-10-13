#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5;
int yakCnt[MAX + 1];
int fenwik[MAX + 1];

int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

void add(int pos, int idx) {

	for (; pos <= MAX; pos += pos & (-pos))
		fenwik[pos] = _max(yakCnt[fenwik[pos]], yakCnt[idx]) >= yakCnt[idx] ? idx : fenwik[pos];
}

int find(int pos) {
	int res = pos;
	for (; pos > 0; pos -= pos & (-pos))
		if (yakCnt[fenwik[res]] < yakCnt[fenwik[pos]]) res = pos;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i <= MAX; i++)
		for (int j = 1; j * i <= MAX; j++)
			yakCnt[j * i]++;

	for (int i = 1; i <= MAX; i++)
		add(i, i);

	int tcc; cin >> tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		int n; cin >> n;

		cout << '#' << tc << ' ' << find(n) << '\n';
	}

	return 0;
}