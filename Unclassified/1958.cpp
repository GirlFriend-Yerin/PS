#include <iostream>
#include <string>

using namespace std;

const short MAX = 101;

int map[MAX][MAX][MAX];

int _max(const int a, const int b) { return a ^ ((a ^ b) & -(a < b)); }

int fill_map(string& s1, string& s2, string& s3)
{
	int length1 = s1.length();
	int length2 = s2.length();
	int length3 = s3.length();

	for (int i = 1; i <= length1; i++)
	{
		for (int j = 1; j <= length2; j++)
		{
			for (int k = 1; k <= length3; k++) {
				
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
				{
					map[i][j][k] = map[i - 1][j - 1][k - 1] + 1;
				}
				else
					map[i][j][k] = _max(_max(map[i - 1][j][k], map[i][j - 1][k]), map[i][j][k - 1]);
			}
		}
	}

	return map[length1][length2][length3];
}

int main()
{
	string s1, s2, s3;

	cin >> s1 >> s2 >> s3;

	int result = fill_map(s1, s2, s3);

	cout << result;

	return 0;
}