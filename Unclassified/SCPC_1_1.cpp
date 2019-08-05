#include <iostream>
#include <string>

using namespace std;

const short MAX = 100;
const short ALPHA_COUNT = 8;

string croAlpha[ALPHA_COUNT] = { "c=" , "c-" , "dz=", "d-", "lj", "nj", "s=", "z=" };

int find(string& input, int pos, int len) {

	if (pos == len - 1)
		return 1;

	for (int i = 0; i < ALPHA_COUNT; i++) {
		bool checker = true;

		for (int j = 0; j < 2 + (i == 2) && pos + j < len; j++) {
			if (input[pos + j] != croAlpha[i][j]) {
				checker = false;
				break;
			}
		}

		if (checker)
			return 2 + (i == 2);
	}

	return 1;
}

int main()
{
	string input; cin >> input;
	int len = input.length();
	int res = 0;

	int pos = 0;
	while (pos < len) {
		int step = find(input, pos, len);
		pos += step;
		res++;
	}

	cout << res;

	return 0;
}