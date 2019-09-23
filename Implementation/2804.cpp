#include <iostream>
#include <string>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
const short MAX = 30;

int main()
{
	fastio;

	string str1, str2; cin >> str1 >> str2;

	int str1Len = str1.length();
	int str2Len = str2.length();

	int str1Pos = 0;
	int str2Pos = 0;

	bool check = false;
	for (int i = 0; i < str1Len; i++) {
		for (int j = 0; j < str2Len; j++)
		{
			if (str1[i] == str2[j]) {
				str1Pos = i;
				str2Pos = j;
				check = true;
				break;
			}
		}
		if (check) break;
	}

	char board[MAX][MAX + 1] = {};
	for (int i = 0; i < str2Len; i++) for (int j = 0; j < str1Len; j++) board[i][j] = '.';
	
	for (int i = 0; i < str1Len; i++)
		board[str2Pos][i] = str1[i];

	for (int i = 0; i < str2Len; i++)
		board[i][str1Pos] = str2[i];

	for (int i = 0; i < str2Len; i++) {
		for (int j = 0; j < str1Len; j++)
			cout << board[i][j];
		cout << '\n';
	}

	return 0;
}