/*
	2019 08 19
	Á¶¾àµ¹ ²¨³»±â

	È®·ü
*/

#include <iostream>
#include <vector>

using namespace std;

const short MAX = 2500;
const short R_MAX = 50;

typedef double ld;

ld triangle[MAX + 1][MAX + 1];

void initPascal() {
	triangle[0][0] = triangle[1][0] = triangle[1][1] = 1;
	for (int i = 2; i <= MAX; ++i) {
		triangle[i][0] = triangle[i][i] = 1;
		for (int j = 1; j <= i; ++j) {
			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	initPascal();

	int m; cin >> m;
	int total = 0;
	vector<int> vec(m);

	for (int i = 0; i < m; i++) {
		cin >> vec[i];
		total += vec[i];
	}

	int k; cin >> k;

	ld base = triangle[total][k];
	ld sumStone = 0;

	for (int i = 0; i < m; i++) {
		sumStone += triangle[vec[i]][k];
	}

	printf("%.18lf", sumStone / base);

	return 0;
}