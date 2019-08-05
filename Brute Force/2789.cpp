#include <iostream>

using namespace std;

const int MAX = 100;
int cardCount;
int des;
int cards[MAX];
int res;

void solving(int pos, int sum, int selectedCount)
{
	if (pos == cardCount || selectedCount == 3)
	{
		if (selectedCount < 3)
			return;

		if (res < sum)
			res = sum;
	}
	else
	{
		if (sum + cards[pos] <= des)
			solving(pos + 1, sum + cards[pos], selectedCount + 1);
		solving(pos + 1, sum, selectedCount);
	}
}

int main()
{
	cin >> cardCount >> des;

	for (int i = 0; i < cardCount; i++)
		cin >> cards[i];

	solving(0, 0, 0);

	cout << res;

	return 0;
}