#include <iostream>

using namespace std;

const short MAX = 50;

char str[MAX + 1] = {};
char target[] = "ACTG";
int n;

int left(int to, int des) {
	int res = 0;
	while (to != des) {
		if (to == 0)
			to = 25;
		else
			to--;
		res++;
	}

	return res;
}

int right(int to, int des) {
	int res = 0;
	while (to != des) {
		if (to == 25)
			to = 0;
		else
			to++;
		res++;
	}

	return res;
}

int func(int strPos) {
	int sum = 0;
	for (int i = 0; i < 4 ; i++) {
		int strValue = str[strPos + i] - 'A';
		int tarValue = target[i] - 'A';

		if (strValue == tarValue)
			continue;

		int lDist = left(strValue, tarValue);
		int rDist = right(strValue, tarValue);

		sum += lDist > rDist ? rDist : lDist;
	}

	return sum;
}

int main()
{
	cin >> n >> str;

	int res = 26 * 4;

	for (int i = 0; i + 3 < n; i++)
	{
		int cal = func(i);
		if (res > cal)
			res = cal;
	}
	
	cout << res;

	return 0;
}