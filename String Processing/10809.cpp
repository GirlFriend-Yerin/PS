/*
	2019 01 17
	10809 ���ĺ� ã��
	���ڿ� ó��

	- ���� -
*/

#include <iostream>

using namespace std;

int main()
{
	char sentense[101] = { };
	int alphaPos[26] = { };

	fill_n(alphaPos, 26, -1);
		
	cin >> sentense;

	for (int i = 0; i < (sizeof(sentense) / sizeof(char)); i++)
	{
		if (alphaPos[sentense[i] - 'a'] == -1)
			alphaPos[sentense[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << alphaPos[i] << ' ';

	return 0;
}