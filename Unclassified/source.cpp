#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {

	int n, w; cin >> n >> w;
	vector<vector<string>> vec(n, vector<string>(n));

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> vec[i][j];

	int line = ceil(n / 2);

	vector<vector<string>> out(line + (n % 2));
	for (int i = 0; i < line + (n % 2); i++) {

		// top
		for (int j = i; j < n - i; j++)
			out[i].push_back(vec[i][j]);

		// right
		for (int j = i + 1; j < n - i; j++)
			out[i].push_back(vec[j][n - 1 - i]);

		// bottom
		for (int j = n - 2 - i; j >= i; j--)
			out[i].push_back(vec[n - 1 - i][j]);

		// left
		for (int j = n - 2 - i; j > i; j--)
			out[i].push_back(vec[j][i]);
	}

	vector<vector<string>> move(line + (n % 2));

	bool flag = w < 0;
	for (int i = 0; i < line + (n % 2); i++) {
		int size = out[i].size();
		int startPos = (abs(w) % size) * (flag ? 1 : -1);
		for (int j = 0; j < size; j++) {
			move[i].push_back(out[i][(startPos + j + size) % size]);
		}
		flag != flag;
	}

	for (int i = 0; i < line + (n % 2); i++) {
		int pos = 0;

		// top
		for (int j = i; j < n - i; j++)
			vec[i][j] = move[i][pos++];

		// right
		for (int j = i + 1; j < n - i; j++)
			vec[j][n - 1 - i] = move[i][pos++];

		// bottom
		for (int j = n - 2 - i; j >= i; j--)
			vec[n - 1 - i][j] = move[i][pos++];

		// left
		for (int j = n - 2 - i; j > i; j--)
			vec[j][i] = move[i][pos++];

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << vec[i][j] << ' ';
		cout << '\n';
	}


	return 0;
}