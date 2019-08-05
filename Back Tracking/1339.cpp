/*
	2019 01 19
	1339 단어 수학
	Back Tracking

	- 성공 -
*/
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 10;
int alphaCount;
int n;
int mxm;

vector<char[MAX+1]> words(MAX);
char useAlpha[MAX];
short alphaValue[MAX];
bool check[MAX];

int find(char c)
{
	for (int i = 0; i < alphaCount; i++)
		if (useAlpha[i] == c)
			return i;
	return -1;
}

void backTrack(int pos)
{
	if (pos == alphaCount)
	{
		int sum = 0;
		/*for (int i = 0; i < alphaCount; i++)
			cout << alphaValue[i] << ' ';*/ // For Debug

		for (int i = 0; i < n; i++)
		{
			int cal = 0;
			int len = strlen(words[i]);
			for (int j = 0; j < len; j++)
				cal = (cal * 10) +  alphaValue[find(words[i][j])];
			sum += cal;

			// cout << cal << ' '; // For debug
		}

		// cout << sum << '\n'; // For debug

		if (mxm < sum)
			mxm = sum;
	}
	else
	{
		for (int i = 0; i < alphaCount; i++)
		{
			if (check[i])
				continue;

			alphaValue[pos] = MAX - i - 1;
			check[i] = true;
			backTrack(pos + 1);
			check[i] = false;
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> words[i];

		for (int j = 0; words[i][j] != '\0'; j++)
			if (find(words[i][j]) == -1)
				useAlpha[alphaCount++] = words[i][j];
	}

	backTrack(0);

	cout << mxm;
	return 0;
}