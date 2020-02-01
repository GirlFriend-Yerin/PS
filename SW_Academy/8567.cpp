#include <iostream>

using namespace std;

const int MAX = 1e5;
int yakCnt[MAX + 1];
int res[MAX + 1];
int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (register int i = 1; i <= MAX; i++) for (register int j = 1; j * i <= MAX; j++) yakCnt[j * i]++;

	int maxIdx = 1;
	for (register int i = 1; i <= MAX; i++) 
		res[i] = maxIdx = yakCnt[maxIdx] <= yakCnt[i] ? i : maxIdx;

	int tcc; cin >> tcc;

	for (register int tc = 1; tc <= tcc; tc++) {
		int n; cin >> n; printf("#%d %d\n", tc, res[n]);
	}

	return 0;
}