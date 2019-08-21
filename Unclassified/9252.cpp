#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const short MAX = 1000;

int map[MAX + 1][MAX + 1];
char resStr[MAX + 1];

int fill_map(string& s1, string& s2)
{
	int length1 = s1.length();
	int length2 = s2.length();

	for (int i = 1; i <= length1; i++)
	{
		for (int j = 1; j <= length2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				map[i][j] = map[i - 1][j - 1] + 1;
			}
			else
				map[i][j] = max(map[i - 1][j], map[i][j - 1]);
		}
	}
	return map[length1][length2];
}

void trace(const string& str1, int s1Pos, int s2Pos, int n) {

	while (s1Pos && s2Pos) {

		if (map[s1Pos][s2Pos] == map[s1Pos][s2Pos - 1]) s2Pos--;
		else if (map[s1Pos][s2Pos] == map[s1Pos - 1][s2Pos]) s1Pos--;
		else {
			resStr[n - 1] = str1[s1Pos - 1];
			s1Pos--; s2Pos--; n--;
		}
	}

}

int main()
{
	string s1, s2;

	cin >> s1 >> s2;

	int result = fill_map(s1, s2);

	trace(s1, s1.length(), s2.length(), result);

	cout << result << '\n' << resStr;

	return 0;
}