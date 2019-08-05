/*
	2018-12-27
	7568 µ¢Ä¡
	Brute force

	- ¼º°ø -
*/

#include <iostream>

using namespace std;

int weight[50];
int height[50];
int mRank[50];

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> weight[i] >> height[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (weight[j] > weight[i] && height[j] > height[i])
					mRank[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << mRank[i]+1 << " ";

	return 0;
}