/*
	2019 04 17

	Fail
*/

#include <iostream>
#include <queue>

using namespace std;

const short MAX = 2 * 100000;

bool solar[MAX];

struct Battery {
	int pos;
	int bat;
	int acc;

	Battery(int p, int b, int a) : pos(p), bat(b), acc(a) {};
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, b, a;
	int res = 0;
	cin >> n >> b >> a;

	for (int i = 0; i < n; i++) {
		cin >> solar[i];
	}

	queue<Battery> q;
	queue<Battery> nQ;

	q.push(Battery(0, b, a));


	while (!q.empty()) {
		Battery cur = q.front();
		q.pop();

		if (cur.acc == 0 && cur.bat == 0) {
			if (cur.pos == n - 1) {
				res = n;
				break;
			}

			if (cur.pos > res)
				res = cur.pos;
			continue;
		}

		if (solar[cur.pos] && cur.acc < a) {
			cur.acc++;
		}

		if (cur.bat > 0)
			q.push(Battery(cur.pos + 1, cur.bat - 1, cur.acc));
		if (cur.acc > 0)
			q.push(Battery(cur.pos + 1, cur.bat, cur.acc - 1));
	}

	cout << res;

	return 0;
}