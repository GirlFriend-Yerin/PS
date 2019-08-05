#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const short MAX = 50;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char input[MAX] = {};

	cin >> input;

	int len = strlen(input);
	int aCount = 0;

	for (int i = 0; i < len; i++)
		if (input[i] == 'a')
			aCount++;

	int otherCount = len - aCount;

	while (aCount <= otherCount)
		otherCount--;

	cout << aCount + otherCount;

	return 0;
}