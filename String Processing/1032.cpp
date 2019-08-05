#include <iostream>

using namespace std;

const short MAX = 50;

int main()
{
	int cnt; cin >> cnt;
	char fileList[MAX][MAX + 1] = {};
	char res[MAX + 1] = {};

	for (int i = 0; i < MAX; i++)
		cin >> fileList[i];

	for (int i = 0; fileList[0][i] != '\0'; i++) {
		char ch = fileList[0][i];
		bool isAllSame = true;

		for (int j = 1; j < cnt; j++) {
			if (fileList[j][i] != ch) {
				isAllSame = false;
				break;
			}
		}

		if (isAllSame)
			res[i] = ch;
		else
			res[i] = '?';
	}

	cout << res;

	return 0;
}