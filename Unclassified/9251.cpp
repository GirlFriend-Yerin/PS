#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int map[1001][1001];

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

int main()
{
	string s1, s2;

	cin >> s1 >> s2;

	int result = fill_map(s1, s2);

	cout << result;

	return 0;
}