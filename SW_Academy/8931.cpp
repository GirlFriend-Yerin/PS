#include <iostream>

using namespace std;

const int MAX = 100000;

int stack[MAX] = {};
int pos;
int sum;

void init() {
	pos = 0;
	sum = 0;
}

void push(int& val) {
	sum += val;
	stack[pos++] = val;
}

void pop() {
	if (!pos) return;
	sum -= stack[--pos];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tcc; cin >> tcc;

	for (register int tc = 1; tc <= tcc; tc++) {
		init();
		int k; cin >> k;
		for (register int i = 0; i < k; i++)
		{
			int val; cin >> val;
			if (val) push(val);
			else pop();
		}

		cout << '#' << tc << ' ' << sum << '\n';
	}

	return 0;
}