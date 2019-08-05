#include <iostream>

using namespace std;

const int DIV[3] = { 10, 12, 16 };

bool check(int num)
{
	int sum[3] = {};

	for (int i = 0; i < 3; i++)
	{
		int flag = num;

		for (; flag != 0; flag /= DIV[i])
			sum[i] += flag % DIV[i];
	}

	return sum[0] == sum[1] && sum[1] == sum[2];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1000; i < 10000; i++)
	{
		if (check(i))
			cout << i << '\n';
	}

	return 0;
}