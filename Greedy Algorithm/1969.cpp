#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int NMAX = 1000;
const int MMAX = 50;

int _min(const int a, const int b) { return b ^ ((a ^ b) & -(a < b)); }
int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

int ch2num(char ch) {
	switch (ch) {
	case 'A':
			return 0;
	case 'C':
		return 1;
	case 'G':
		return 2;
	}

	return 3;
}

char num2ch(int val) {
	switch (val) {
	case 0:
		return 'A';
	case 1:
		return 'C';
	case 2:
		return 'G';
	}

	return 'T';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;
	int counter[MMAX][4] = {};

	vector<string> strings(n);
	for (int i = 0; i < n; i++)
		cin >> strings[i];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			counter[i][ch2num(strings[j][i])]++;

	int hamingDis = 0;
	for (int i = 0; i < m; i++) {
		int res = 0;
		int diff = counter[i][res] ? 1 : 0;
		for (int j = 1; j < 4; j++) {
			if (counter[i][res] < counter[i][j])
				res = j;
			if (counter[i][j])
				diff++;
		}

		hamingDis += n - counter[i][res];

		cout << num2ch(res);
	}

	cout << '\n' << hamingDis;

	return 0;
}